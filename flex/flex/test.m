@interface MyClass 
{} 
+ (int) staticMethod;
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
}