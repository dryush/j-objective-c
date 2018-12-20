int func() {
	printf("Fooo");
	return 1;
}
void main()
{
	NSScanner *in = [[NSScanner alloc]init];
	int c = [ in scanInt];
	while ( c > 0){
		return;
		c = c - 1;
		printf([NSString fromInt: c]);
	}
}