@interface A {
@public
	NSString* str;
//@private
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
		return [str append: " format from A"];
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
	//	return [[base formatStr] append: [str append: " format from AC "]];
		return [base formatStr] ;
	}

@end



void main()
{


	/*
	A* a = [A alloc];
	A* ab = [AB alloc];
	A* abc = [ABC alloc];
	A* ac =	[AC alloc];
 
	
	A* array[4] = {a, ab, abc, ac};	
	a[0] = a;
	a[1] = ab;
	a[2] = abc;
	a[3] = ac;

	[a setStr: "return 2007"];
	[ab setStr: "return 2007"];
	[abc setStr: "return 2007"];
	[ac setStr: "return 2007"];
	
	
	printf( [a formatStr]);
	printf( [ab formatStr]);
	printf( [abc formatStr]);
	printf( [ac formatStr]);
	
	printf( [a formatStr2]);
	printf( [ab formatStr2]);
	printf( [abc formatStr2]);
	printf( [ac formatStr2]);
	
	a->str = [NSString fromInt: 2019];
	printf( [a getStr]);
	[A print: [a getStr]];
	*/
	
	A* array = { [A alloc], [AB alloc], [ABC alloc], [AC alloc]};
	int i = 0;
	while( i < 4){
		[array[i] setStr: "return 2007"];
		printf( [array[i] formatStr]);
		printf( [array[i] formatStr2]);
		i = i + 1;
	}
}