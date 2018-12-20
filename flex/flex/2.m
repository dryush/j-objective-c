void main() {
	NSScanner *scan = [[NSScanner alloc] init];
	int a = [scan scanInt];
	if (a > 0)
		printf("More");
	else if (a == 0)
		printf("Equal");
	else
		printf("Less");
}