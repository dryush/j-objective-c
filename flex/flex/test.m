@interface MyClass 
{
	int am;
} 
+ (int) staticMethod;
- (float) localMethod;
@end

@interface MyClass2 
{} 
+ (MyClass*) staticMethod: (MyClass*[]) firstparam (int) secondparam;
- (float) localMethod;
@end

void foo( MyClass* n){
	return;
}

int main()
{
	MyClass* MyClass;
	
	foo(MyClass);

	return 0;
}
