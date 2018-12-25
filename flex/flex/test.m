@interface A 
{
	@public
	NSString * str;
	float f;
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
		return [[base formatStr] append:[str append: " format from ABC"]];
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


void func(A *obj, float number, A *array[] ) {
	printf("This is func()");
	number = number * 1000;
	obj->str = [[NSString alloc] init: "From func string"];
	int i = 0;
	while( i < 5){
		[array[i] setStr: "From func World"];
		printf( [array[i] formatStr]);
		i = i + 1;
	}
	//[obj setStr: "Bye World"];
	//[obj setF: number];
}

void main()
{
	A* array[5] = { [A alloc], [AB alloc], [ABC alloc], [AC alloc], [AD alloc]};
	
	A* obj = [A alloc];
	//obj->str = [[NSString alloc] init: "someStr"];
	obj->str = "someStr";
	


	float f = 0.5;
	printf( [[NSString alloc] init: "Before func: "] );
	printf( obj->str);
	printf( [NSString fromFloat: f]);

	func( obj, f, array);
	
	printf( [[NSString alloc] init: "After func: "] );
	printf( obj->str);
	printf( [NSString fromFloat: f]);
}