void main() {
	NSScanner *scan = [[NSScanner alloc] init];
	int a = [scan scanInt];
	if ( !( (a < 3 && a > 0) || (a > 10 && a < 13) ) )
		printf("YEE BABY");
	else
		printf("Ohh, common");
}