@interface MyClass 
{} 
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
	[myObject localMethod];
}