@interface A 
{
	NSString * str;
	float f;
}
@public
	-(void) setStr: (NSString*) nstr;
	-(NSString*) getStr;
	+(void) print: (NSString*) str;
	-(void) setF: (float) v;
	-(float) getF;

@end

@implementation A
	-(void) setStr: (NSString*) nstr {
		//this->str = str;
		str = nstr;
	}
	-(NSString*) getStr {
		return str;
	}
	+(void) print: (NSString*) str {
		//this->f = 0;
		f = 0;
		setStr("");
		printf( str);
	}
	
	-(void) setF: (float) v {
		this->f = v;
	}
	-(float) getF {
		return this->f;
	}

@end

void main()
{
	A* a = [A alloc];
	[a setStr: "str"];
	
	[A print: a->str];
	[A print: "someStr"];
}