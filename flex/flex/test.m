

75E-2 
15.75  
1.575E1     
1575e-2    
-2.5e-3     
25E-4    
.0075e2  
0.075e1  
.075e1  
75e-2   


"some string"
/*some comment*/
/*
* some comment
too ****
*/
// one line comment
NSString * str="string \" with magic \x2A \052 \n \\"


int array[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

self = [super init];
if (self) {
	_poolSize = poolSize;
	_bufferedConsumers = [NSMutableArray arrayWithCapacity:poolSize];
} else if ( YES ){
	int a;
} else {
	int a;
}
int a = 2;
whlie(a){
	printf("hehehe:%d", a);
}
@interface SRIOConsumerPool : NSObject

- (instancetype)initWithBufferCapacity:(NSUInteger)poolSize;

- (SRIOConsumer *)consumerWithScanner:(stream_scanner)scanner
                              handler:(data_callback)handler
                          bytesNeeded:(size_t)bytesNeeded
                   readToCurrentFrame:(BOOL)readToCurrentFrame
                          unmaskBytes:(BOOL)unmaskBytes;
- (void)returnConsumer:(SRIOConsumer *)consumer;

@end

@implementation SRIOConsumerPool {
    NSUInteger _poolSize;
    NSMutableArray<SRIOConsumer *> *_bufferedConsumers;
}

- (instancetype)initWithBufferCapacity:(NSUInteger)poolSize;
{
    self = [super init];
    if (self) {
        _poolSize = poolSize;
        _bufferedConsumers = [NSMutableArray arrayWithCapacity:poolSize];
    }
	int a = 2;
	whlie(a){
		printf("hehehe:%d", a);
	}
    return self;
}

- (instancetype)init
{
    return [self initWithBufferCapacity:8];
}

- (SRIOConsumer *)consumerWithScanner:(stream_scanner)scanner
                              handler:(data_callback)handler
                          bytesNeeded:(size_t)bytesNeeded
                   readToCurrentFrame:(BOOL)readToCurrentFrame
                          unmaskBytes:(BOOL)unmaskBytes
{
    SRIOConsumer *consumer = nil;
    if (_bufferedConsumers.count) {
        consumer = [_bufferedConsumers lastObject];
        [_bufferedConsumers removeLastObject];
    } else {
        consumer = [[SRIOConsumer alloc] init];
    }

    [consumer resetWithScanner:scanner
                       handler:handler
                   bytesNeeded:bytesNeeded
            readToCurrentFrame:readToCurrentFrame
                   unmaskBytes:unmaskBytes];

    return consumer;
}

- (void)returnConsumer:(SRIOConsumer *)consumer;
{
    if (_bufferedConsumers.count < _poolSize) {
        [_bufferedConsumers addObject:consumer];
    }
}

@end