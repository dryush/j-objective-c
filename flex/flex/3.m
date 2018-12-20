void func(int c) {
	printf([ NSString fromInt: c]);
	if (c > 0)
		func(c - 1);
}
void main()
{
	NSScanner *in = [[NSScanner alloc]init];
	int c = [ in scanInt];
	func(c);
}