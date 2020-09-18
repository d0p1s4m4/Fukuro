int             strlen_group_tests(void);
int             strrev_group_tests(void);
int             itoa_group_tests(void);

int
main(void)
{
	int             result;

	result = 0;
	result |= strlen_group_tests();
	result |= strrev_group_tests();
	result |= itoa_group_tests();

	return (result);
}
