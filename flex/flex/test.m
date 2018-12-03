@interface Man : NSObject
{
    @protected
	int age;
	
	@public
	char name;
}
@public
+ (void)setAge: (int)age;
@private
- (int)getAge;
@end