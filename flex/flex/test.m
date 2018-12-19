void func(int a, int b) {
	printf("this is func");
	printf([ NSString fromInt: a]);
	b = b / 2;
	printf([ NSString fromInt: b]);
}

void main()
{
	int a = 0;
	NSScanner* in= [[NSScanner alloc] init];
	a = [in scanInt];
	int b = 3;
	func(a,b);
	printf([ NSString fromInt: a]);
	printf([ NSString fromInt: b]);
}
