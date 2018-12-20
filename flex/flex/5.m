
void main() {
	NSScanner *scan = [[NSScanner alloc] init];
	int a = [scan scanInt];
	while ( !( (a < 3 && a > 0) ) ) {
		if (a <= 0)
			a = a + 1;
		else if (a >= 3)
			a = a - 1;
		printf([ NSString fromInt: a]);
	}
}