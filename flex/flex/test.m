@interface A {
@public
	NSString* str;
}
@public
	-(void) setStr: (NSString*) str;
	-(NSString*) getStr;
	-(NSString*) formatStr;
	-(NSString*) formatStr2;
@end

@implementation A
	-(void) setStr: (NSString*) str {
		this->str = str;
	}
	-(NSString*) getStr {
		return str;
	}
	-(NSString*) formatStr {
		return [str append: " format from A"];
	}
	-(NSString*) formatStr2 {
		return [[this formatStr] append: " and from A"];
	}

@end

@interface AB : A {}
	-(NSString*) formatStr;
@end

@implementation AB
	-(NSString*) formatStr {
		return [str append: " format from AB"];
	}

@end

@interface ABC : AB {}
	-(NSString*) formatStr;
@end

@implementation ABC
	-(NSString*) formatStr {
		return [str append: " format from ABC"];
	}

@end


@interface AC : A {}
	-(NSString*) formatStr;
@end

@implementation AC
	-(NSString*) formatStr {
		return [[base formatStr] append: [str append: " format from AC "]];
	}

@end



void main()
{
	A* a[4] = { 
		[A alloc],
		[AB alloc],
		[ABC alloc],
		[AC alloc]
	};

	int i = 0;
	while( i < 4){
		i = i + 1;
		[a[i] setStr: "return 2007"];
	}

	i = 0;
	while( i < 4){
		i = i + 1;
		printf( [a[i] formatStr]);
	}

	i = 0;
	while( i < 4){
		i = i + 1;
		printf( [a[i] formatStr2]);
	}

}