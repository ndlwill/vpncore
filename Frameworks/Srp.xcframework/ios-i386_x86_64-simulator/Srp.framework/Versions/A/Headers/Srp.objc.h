// Objective-C API for talking to go-srp Go package.
//   gobind -lang=objc go-srp
//
// File is generated by gobind. Do not edit.

#ifndef __Srp_H__
#define __Srp_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class SrpAuth;
@class SrpProofs;

/**
 * Auth stores byte data for the calculation of SRP proofs.
 * Changed SrpAuto to Auth because the name will be used as srp.SrpAuto by other packages and as SrpSrpAuth on mobile
 * Also the data from the API called Auth. it could be match the meaning and reduce the confusion
 */
@interface SrpAuth : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * NewAuth Creates new Auth from strings input. Salt and server ephemeral are in
base64 format. Modulus is base64 with signature attached. The signature is
verified against server key. The version controls password hash algorithm.

Parameters:
	 - version int: The *x* component of the vector.
	 - username string: The *y* component of the vector.
	 - password string: The *z* component of the vector.
	 - salt string:
Returns:
  - auth *Auth: the pre caculated auth information
  - err error: throw error
Usage:

Warnings:
	 - Be carefull! Poos can hurt.
 */
- (nullable instancetype)init:(long)version username:(NSString* _Nullable)username password:(NSString* _Nullable)password salt:(NSString* _Nullable)salt signedModulus:(NSString* _Nullable)signedModulus serverEphemeral:(NSString* _Nullable)serverEphemeral;
/**
 * NewAuthForVerifier Creates new Auth from strings input. Salt and server ephemeral are in
base64 format. Modulus is base64 with signature attached. The signature is
verified against server key. The version controls password hash algorithm.

Parameters:
	 - version int: The *x* component of the vector.
	 - username string: The *y* component of the vector.
	 - password string: The *z* component of the vector.
	 - salt string:
Returns:
  - auth *Auth: the pre caculated auth information
  - err error: throw error
Usage:

Warnings:
	 - none.
 */
- (nullable instancetype)initForVerifier:(NSString* _Nullable)password signedModulus:(NSString* _Nullable)signedModulus rawSalt:(NSData* _Nullable)rawSalt;
@property (nonatomic) NSData* _Nullable modulus;
@property (nonatomic) NSData* _Nullable serverEphemeral;
@property (nonatomic) NSData* _Nullable hashedPassword;
/**
 * GenerateProofs calculates SPR proofs.
 */
- (SrpProofs* _Nullable)generateProofs:(long)bitLength error:(NSError* _Nullable* _Nullable)error;
/**
 * GenerateVerifier verifier for update pwds and create accounts
 */
- (NSData* _Nullable)generateVerifier:(long)bitLength error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * Proofs Srp Proofs object. Changed SrpProofs to Proofs because the name will be used as srp.SrpProofs by other packages and as SrpSrpProofs on mobile
ClientProof []byte  client proof
ClientEphemeral []byte  calculated from
ExpectedServerProof []byte
 */
@interface SrpProofs : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSData* _Nullable clientProof;
@property (nonatomic) NSData* _Nullable clientEphemeral;
@property (nonatomic) NSData* _Nullable expectedServerProof;
@end

@interface Srp : NSObject
/**
 * ErrDataAfterModulus found extra data after decode the modulus
 */
+ (NSError* _Nullable) errDataAfterModulus;
+ (void) setErrDataAfterModulus:(NSError* _Nullable)v;

/**
 * ErrInvalidSignature invalid modulus signature
 */
+ (NSError* _Nullable) errInvalidSignature;
+ (void) setErrInvalidSignature:(NSError* _Nullable)v;

// skipped variable RandReader with unsupported type: io.Reader

@end

FOUNDATION_EXPORT NSString* _Nonnull SrpGetModulusKey(void);

/**
 * HashPassword returns the hash of password argument. Based on version number
following arguments are used in addition to password:
* 0, 1, 2: userName and modulus
* 3, 4: salt and modulus
 */
FOUNDATION_EXPORT NSData* _Nullable SrpHashPassword(long authVersion, NSString* _Nullable password, NSString* _Nullable userName, NSData* _Nullable salt, NSData* _Nullable modulus, NSError* _Nullable* _Nullable error);

/**
 * MailboxPassword get mailbox password hash

Parameters:
	 - password string: a mailbox password
	 - salt []byte: a salt is random 128 bits data
Returns:
  - hashed string: a hashed password
  - err error: throw error
 */
FOUNDATION_EXPORT NSString* _Nonnull SrpMailboxPassword(NSString* _Nullable password, NSData* _Nullable salt, NSError* _Nullable* _Nullable error);

/**
 * NewAuth Creates new Auth from strings input. Salt and server ephemeral are in
base64 format. Modulus is base64 with signature attached. The signature is
verified against server key. The version controls password hash algorithm.

Parameters:
	 - version int: The *x* component of the vector.
	 - username string: The *y* component of the vector.
	 - password string: The *z* component of the vector.
	 - salt string:
Returns:
  - auth *Auth: the pre caculated auth information
  - err error: throw error
Usage:

Warnings:
	 - Be carefull! Poos can hurt.
 */
FOUNDATION_EXPORT SrpAuth* _Nullable SrpNewAuth(long version, NSString* _Nullable username, NSString* _Nullable password, NSString* _Nullable salt, NSString* _Nullable signedModulus, NSString* _Nullable serverEphemeral, NSError* _Nullable* _Nullable error);

/**
 * NewAuthForVerifier Creates new Auth from strings input. Salt and server ephemeral are in
base64 format. Modulus is base64 with signature attached. The signature is
verified against server key. The version controls password hash algorithm.

Parameters:
	 - version int: The *x* component of the vector.
	 - username string: The *y* component of the vector.
	 - password string: The *z* component of the vector.
	 - salt string:
Returns:
  - auth *Auth: the pre caculated auth information
  - err error: throw error
Usage:

Warnings:
	 - none.
 */
FOUNDATION_EXPORT SrpAuth* _Nullable SrpNewAuthForVerifier(NSString* _Nullable password, NSString* _Nullable signedModulus, NSData* _Nullable rawSalt, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSData* _Nullable SrpRandomBits(long bits, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSData* _Nullable SrpRandomBytes(long byes, NSError* _Nullable* _Nullable error);

/**
 * VersionNumber get current libaray version
 */
FOUNDATION_EXPORT NSString* _Nonnull SrpVersionNumber(void);

#endif
