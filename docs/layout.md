# Source layout

- `docs/` Documentation
- `make/` Makefiles helper
    - `aarch64/`
	- `arm/`
    - `x86/`
        - `32/`
        - `64/`
- `src/`
    - `kernel/`
        - `arch/`
            - `aarch64/`
            - `arm/`
            - `x86/`
                - `32/`
                - `64/`
    - `lib/`
        - `minic/`
        - `fukuro/`
    - `server/`
        - `net/`
        - `rtl8139/`
- `test/`
- `thirdparty/` Sources code from external source
- `tools/` Scripts used in order to build Fukurō
