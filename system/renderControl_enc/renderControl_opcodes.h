// Generated Code - DO NOT EDIT !!
// generated by 'emugen'
#ifndef __GUARD_renderControl_opcodes_h_
#define __GUARD_renderControl_opcodes_h_

#define OP_rcGetRendererVersion 					10000
#define OP_rcGetEGLVersion 					10001
#define OP_rcQueryEGLString 					10002
#define OP_rcGetGLString 					10003
#define OP_rcGetNumConfigs 					10004
#define OP_rcGetConfigs 					10005
#define OP_rcChooseConfig 					10006
#define OP_rcGetFBParam 					10007
#define OP_rcCreateContext 					10008
#define OP_rcDestroyContext 					10009
#define OP_rcCreateWindowSurface 					10010
#define OP_rcDestroyWindowSurface 					10011
#define OP_rcCreateColorBuffer 					10012
#define OP_rcOpenColorBuffer 					10013
#define OP_rcCloseColorBuffer 					10014
#define OP_rcSetWindowColorBuffer 					10015
#define OP_rcFlushWindowColorBuffer 					10016
#define OP_rcMakeCurrent 					10017
#define OP_rcFBPost 					10018
#define OP_rcFBSetSwapInterval 					10019
#define OP_rcBindTexture 					10020
#define OP_rcBindRenderbuffer 					10021
#define OP_rcColorBufferCacheFlush 					10022
#define OP_rcReadColorBuffer 					10023
#define OP_rcUpdateColorBuffer 					10024
#define OP_rcOpenColorBuffer2 					10025
#define OP_rcCreateClientImage 					10026
#define OP_rcDestroyClientImage 					10027
#define OP_rcSelectChecksumHelper 					10028
#define OP_rcCreateSyncKHR 					10029
#define OP_rcClientWaitSyncKHR 					10030
#define OP_rcFlushWindowColorBufferAsync 					10031
#define OP_rcDestroySyncKHR 					10032
#define OP_rcSetPuid 					10033
#define OP_rcUpdateColorBufferDMA 					10034
#define OP_rcCreateColorBufferDMA 					10035
#define OP_rcWaitSyncKHR 					10036
#define OP_rcCompose 					10037
#define OP_rcCreateDisplay 					10038
#define OP_rcDestroyDisplay 					10039
#define OP_rcSetDisplayColorBuffer 					10040
#define OP_rcGetDisplayColorBuffer 					10041
#define OP_rcGetColorBufferDisplay 					10042
#define OP_rcGetDisplayPose 					10043
#define OP_rcSetDisplayPose 					10044
#define OP_rcSetColorBufferVulkanMode 					10045
#define OP_rcReadColorBufferYUV 					10046
#define OP_rcIsSyncSignaled 					10047

//************ add opcode start ********************
//for sync  PostVirtualDisplay
#define OP_rcPostVirtualDisplay 					18888
#define OP_rcPpostAllVirtualDisplaysDone 					18889
//************ add opcode end ********************

#define OP_last 					18890


#endif
