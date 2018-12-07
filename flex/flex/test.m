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

int main()
{
	MyClass* myObject;
	myObject->am;
	[myObject localMethod];
	MyClass* mc1 = [MyClass staticMethod];
	MyClass* mc2 = [MyClass alloc];


	return 0;
}