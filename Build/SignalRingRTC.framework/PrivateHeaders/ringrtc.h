/*
 *
 *  Copyright (C) 2019 Signal Messenger, LLC.
 *  All rights reserved.
 *
 *  SPDX-License-Identifier: GPL-3.0-only
 *
 */

#ifndef CBINDGEN_BINDINGS_H
#define CBINDGEN_BINDINGS_H

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#if defined(TARGET_OS_IOS)
/**
 * For convenience, define jlong as a native i64 type for easier
 * compatibility with JNI implementation.
 */
typedef int64_t jlong;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Structure for passing buffers (such as strings) to Swift.
 */
typedef struct {
    const uint8_t *bytes;
    size_t len;
} IOSByteSlice;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Structure for passing Ice Candidates to/from Swift.
 */
typedef struct {
    IOSByteSlice sdpMid;
    int32_t sdpMLineIndex;
    IOSByteSlice sdp;
} IOSIceCandidate;
#endif

#if defined(TARGET_OS_IOS)
typedef struct {
    const IOSIceCandidate *candidates;
    size_t count;
} IOSIceCandidateArray;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Recipient object for interfacing with Swift.
 */
typedef struct {
    void *object;
    void (*destroy)(void *object);
    void (*onSendOffer)(void *object, int64_t callId, IOSByteSlice offer);
    void (*onSendAnswer)(void *object, int64_t callId, IOSByteSlice answer);
    void (*onSendIceCandidates)(void *object, int64_t callId, const IOSIceCandidateArray *iceCandidate);
    void (*onSendHangup)(void *object, int64_t callId);
    void (*onSendBusy)(void *object, int64_t callId);
} IOSRecipient;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Structure for passing common configuration options.
 */
typedef struct {
    int64_t callId;
    bool outBound;
    IOSRecipient recipient;
} IOSCallConfig;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Observer object for interfacing with Swift.
 * iOS CallConnectionObserver
 */
typedef struct {
    void *object;
    void (*destroy)(void *object);
    void (*onCallEvent)(void *object, int64_t callId, int32_t callEvent);
    void (*onCallError)(void *object, int64_t callId, IOSByteSlice errorString);
    void (*onAddStream)(void *object, int64_t callId, void *stream);
} IOSObserver;
#endif

#if defined(TARGET_OS_IOS)
/**
 * Log object for interfacing with swift.
 */
typedef struct {
    void *object;
    void (*destroy)(void *object);
    void (*log)(void *object, IOSByteSlice message, IOSByteSlice file, IOSByteSlice function, int32_t line, int8_t level);
} IOSLogger;
#endif

#if defined(TARGET_OS_ANDROID)
jlong Java_org_signal_ringrtc_CallConnectionFactory_nativeCreateCallConnection(JNIEnv env,
                                                                               JClass class_,
                                                                               jlong native_factory,
                                                                               JObject call_config,
                                                                               jlong native_observer,
                                                                               JObject rtc_config,
                                                                               JObject media_constraints,
                                                                               JObject ssl_cert_verifier);
#endif

#if defined(TARGET_OS_ANDROID)
jlong Java_org_signal_ringrtc_CallConnectionFactory_nativeCreateCallConnectionFactory(JNIEnv env,
                                                                                      JClass _class,
                                                                                      jlong peer_connection_factory);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnectionFactory_nativeFreeFactory(JNIEnv env,
                                                                     JClass _class,
                                                                     jlong factory);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnectionFactory_nativeInitialize(JNIEnv env, JClass _class);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeAcceptOffer(JNIEnv env,
                                                              JObject jcall_connection,
                                                              jlong call_connection,
                                                              JString offer);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeAddIceCandidate(JNIEnv env,
                                                                  JObject _object,
                                                                  jlong call_connection,
                                                                  JString sdp_mid,
                                                                  jint sdp_mline_index,
                                                                  JString sdp);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeAnswerCall(JNIEnv env,
                                                             JObject _object,
                                                             jlong call_connection);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeClose(JNIEnv env,
                                                        JObject _object,
                                                        jlong call_connection);
#endif

#if defined(TARGET_OS_ANDROID)
jlong Java_org_signal_ringrtc_CallConnection_nativeCreateCallConnectionObserver(JNIEnv env,
                                                                                JClass _class,
                                                                                JObject observer,
                                                                                jlong call_id,
                                                                                JObject recipient);
#endif

#if defined(TARGET_OS_ANDROID)
jlong Java_org_signal_ringrtc_CallConnection_nativeGetNativePeerConnection(JNIEnv env,
                                                                           JClass _class,
                                                                           jlong call_connection);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeHandleOfferAnswer(JNIEnv env,
                                                                    JObject _object,
                                                                    jlong call_connection,
                                                                    JString session_desc);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeHangUp(JNIEnv env,
                                                         JObject _object,
                                                         jlong call_connection);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeSendBusy(JNIEnv env,
                                                           JObject _object,
                                                           jlong call_connection,
                                                           JObject recipient,
                                                           jlong call_id);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeSendOffer(JNIEnv env,
                                                            JObject jcall_connection,
                                                            jlong call_connection);
#endif

#if defined(TARGET_OS_ANDROID)
void Java_org_signal_ringrtc_CallConnection_nativeSendVideoStatus(JNIEnv env,
                                                                  JObject _object,
                                                                  jlong call_connection,
                                                                  jboolean enabled);
#endif

#if defined(TARGET_OS_ANDROID)
jboolean Java_org_signal_ringrtc_CallConnection_nativeValidateResponseState(JNIEnv env,
                                                                            JObject _object,
                                                                            jlong call_connection);
#endif

#if defined(TARGET_OS_IOS)
/**
 * Create a 'native' WebRTC via iOS Application Call Connection,
 * passing in a custom observer implemented by RingRTC.
 */
extern void *appCreatePeerConnection(void *appFactory,
                                     void *appCallConnection,
                                     void *rtcConfig,
                                     void *rtcConstraints,
                                     void *customObserver);
#endif

#if defined(TARGET_OS_IOS)
extern void *appCreateStreamFromNative(const void *appCallConnection, void *nativeStream);
#endif

#if defined(TARGET_OS_IOS)
extern void appReleaseStream(const void *appCallConnection, void *appStream);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcAccept(void *callConnection);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcClose(void *callConnection);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcCreateCallConnection(void *callConnectionFactory,
                                  void *appCallConnection,
                                  IOSCallConfig callConfig,
                                  void *callConnectionObserver,
                                  void *rtcConfig,
                                  void *rtcConstraints);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcCreateCallConnectionFactory(void *appCallConnectionFactory);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcCreateCallConnectionObserver(IOSObserver observer, int64_t callId);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcFreeFactory(void *factory);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcHangup(void *callConnection);
#endif

#if defined(TARGET_OS_IOS)
/**
 * Library initialization routine.
 * Sets up the logging infrastructure.
 */
void *ringRtcInitialize(IOSLogger logObject);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcReceivedAnswer(void *callConnection, const uint8_t *bytes, size_t len);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcReceivedIceCandidate(void *callConnection,
                                  const uint8_t *sdpBytes,
                                  size_t sdpLen,
                                  int32_t lineIndex,
                                  const uint8_t *sdpMidBytes,
                                  size_t sdpMidLen);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcReceivedOffer(void *callConnection,
                           void *appCallConnection,
                           const uint8_t *bytes,
                           size_t len);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcSendBusy(void *callConnection, int64_t callId);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcSendOffer(void *callConnection, void *appCallConnection);
#endif

#if defined(TARGET_OS_IOS)
void *ringRtcSendVideoStatus(void *callConnection, bool enabled);
#endif

#endif /* CBINDGEN_BINDINGS_H */
