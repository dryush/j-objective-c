void main()
{
	NSScanner* in= [[NSScanner alloc] init];
	int a = [in scanInt];
	if (a > 0 && a < 5)
		printf([ NSString fromInt: a]);

}
