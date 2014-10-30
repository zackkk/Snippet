/*
	Serialise by storing the width of each string[] as a fixed-width prefix in each line.

	So

	string[0]="abc"
	string[1]="defg"
	string[2]=" :::==--==::: "
	becomes
	0003abc0004defg0014 :::==--==:::

	...where the size of the prefix is large enough to cater for the string maximum length
*/