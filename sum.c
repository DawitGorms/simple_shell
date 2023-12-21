/**
 * add_numbers - Add two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum of the two numbers.
 */
int add_numbers(int a, int b)
{
return (a + b);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
int num1 = 10;
int num2 = 5;
int sum;

sum = add_numbers(num1, num2);

printf("The sum of %d and %d is %d\n", num1, num2, sum);

return (0);
}
