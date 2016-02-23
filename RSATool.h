//
//  RSATool.h
//  AFM
//
//  Created by su-fun on 16/2/23.
//  Copyright © 2016年 su-fun. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum {
    KeyTypePublic = 0,
    KeyTypePrivate
}KeyType;

@interface RSATool : NSObject
/**
 *  导入密钥
 */
- (BOOL)importKeyWithType:(KeyType)type andPath:(NSString*)path;
- (BOOL)importKeyWithType:(KeyType)type andkeyString:(NSString *)keyString;

/**
 *  验证签名 Sha1 + RSA
 */
- (BOOL)verifyString:(NSString *)string withSign:(NSString *)signString;

/**
 *  验证签名 md5 + RSA
 */
- (BOOL)verifyMD5String:(NSString *)string withSign:(NSString *)signString;

/**
 *  Sha1+RSA签名
 *
 *  @param string 要签名的内容
 *
 *  @return 加签后的内容
 */
- (NSString *)signString:(NSString *)string;

/**
 *  MD5+RSA签名
 *
 *  @param string 要签名的内容
 *
 *  @return 加签后的内容
 */
- (NSString *)signMD5String:(NSString *)string;

/**
 *  公钥加密
 *
 *  @param content 要加密的明文
 *
 *  @return 加密后的密文
 */
- (NSString *) encryptWithPublicKey:(NSString*)content;

/**
 *  私钥解密
 *
 *  @param content 密文
 *
 *  @return 解密后的明文
 */
- (NSString *) decryptWithPrivatecKey:(NSString*)content;



@end
