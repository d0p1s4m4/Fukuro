#!/bin/sh

if [ -z ${ARCH+x} ]; then
	ARCH=i686
fi

if [ -z ${GCC_VERSION+x} ]; then
	GCC_VERSION="10.2.0"
fi

if [ -z ${BINUTILS_VERSION+x} ]; then
	BINUTILS_VERSION="2.35"
fi

PREFIX="$(pwd)/toolchain"
# XXX: quick fix
if [ "$ARCH" = "arm" ]; then
    TARGET="$ARCH-none-eabi"
else
    TARGET="$ARCH-elf"
fi
PATH="$PREFIX/bin:$PATH"

if [ "$GITHUB_ACTIONS" = true ]; then
	echo "::add-path::$PREFIX/bin"
fi

mkdir -p "$PREFIX"

echo "Selected Toolchain: $TARGET"

if [ ! -f "$PREFIX/bin/$TARGET-gcc" ]; then
	echo "Toolchain not found"
	cd "$PREFIX"
	if [ ! -f "gcc-$GCC_VERSION.tar.xz" ]; then
	   wget "ftp://ftp.lip6.fr/pub/gcc/releases/gcc-$GCC_VERSION/gcc-$GCC_VERSION.tar.xz"
	fi

	if [ ! -f "binutils-2.35.tar.xz" ]; then
		wget "https://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VERSION.tar.xz"
	fi

	echo "Extract archive"
	tar -xf "gcc-$GCC_VERSION.tar.xz"
	tar -xf "binutils-$BINUTILS_VERSION.tar.xz"

	echo "Building binutils"
	mkdir binutils-build
	cd binutils-build
	"../binutils-$BINUTILS_VERSION/configure" --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
	make -j $(nproc)
	make install
	cd ..
	rm -rf binutils-build

	echo "Building gcc"
	mkdir gcc-build
	cd gcc-build
	"../gcc-$GCC_VERSION/configure" --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c --without-headers
	make all-gcc
	make all-target-libgcc
	make install-gcc
	make install-target-libgcc
	cd ..
	rm -rf gcc-build
fi
