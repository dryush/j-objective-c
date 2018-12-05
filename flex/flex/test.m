@interface MyClass 
{} 
+ (int) staticMethod;
- (float) localMethod;
@end

int main()
{
	MyClass* myObject;
	[myObject localMethod];
}