void dfs(int v) {
}
@public
	-(void) setStr: (NSString*) str;
	-(NSString*) getStr;
	-(NSString*) formatStr;
	-(NSString*) formatStr2;
	+(void) print: (NSString*) str;
	-(void) setF: (float) v;
	-(float) getF;

@end

@implementation A
	-(void) setStr: (NSString*) str {
		this->str = str;
	}
	-(NSString*) getStr {
		return str;
	}
	-(NSString*) formatStr {
		return [str append: " format from A "];
	}
	-(NSString*) formatStr2 {
		return [[this formatStr] append: " and from A"];
	}
	+(void) print: (NSString*) str {
		printf( str);
	}
	-(void) setF: (float) v {
		this->f = v;
	}
	-(float) getF {
		return this->f;
	}

@end

@interface AB : A {}
@public
	-(NSString*) formatStr;
@end

@implementation AB
	-(NSString*) formatStr {
		return [str append: " format from AB"];
	}

@end

@interface ABC : AB {}
@public
	-(NSString*) formatStr;
@end

@implementation ABC
	-(NSString*) formatStr {
		return [str append: " format from ABC"];
	}

@end


@interface AC : A {}
@public
	-(NSString*) formatStr;
@end

@implementation AC
	-(NSString*) formatStr {
		return [[base formatStr] append: [str append: "\t format from AC "]];
	//	return [base formatStr] ;
	}
@end

@interface AD : A {}
@end

@implementation AD
@end


void main()
{

	A* array[5] = { [A alloc], [AB alloc], [ABC alloc], [AC alloc], [AD alloc]};
	int i = 0;
	while( i < 5){
		printf( [NSString fromInt: i]);
		[array[i] setStr: "return 2007"];
		printf( [array[i] formatStr]);
		printf( [array[i] formatStr2]);
		i = i + 1;
	}
	
	printf("lolkek\n");

	NSScanner * in = [[NSScanner alloc] init];
	float x = [in scanFloat];
	while (x < 0 || x > 4.345) {
		if (x < 0)
			x = x + 1.5;
		else if (x > 4.345)
			x = x - 1;
		printf([NSString fromFloat: x]);
	}
}