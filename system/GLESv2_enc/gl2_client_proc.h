// Generated Code - DO NOT EDIT !!
// generated by 'emugen'
#ifndef __gl2_client_proc_t_h
#define __gl2_client_proc_t_h



#include "gl2_types.h"
#ifndef gl2_APIENTRY
#define gl2_APIENTRY 
#endif
typedef void (gl2_APIENTRY *glActiveTexture_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glAttachShader_client_proc_t) (void * ctx, GLuint, GLuint);
typedef void (gl2_APIENTRY *glBindAttribLocation_client_proc_t) (void * ctx, GLuint, GLuint, const GLchar*);
typedef void (gl2_APIENTRY *glBindBuffer_client_proc_t) (void * ctx, GLenum, GLuint);
typedef void (gl2_APIENTRY *glBindFramebuffer_client_proc_t) (void * ctx, GLenum, GLuint);
typedef void (gl2_APIENTRY *glBindRenderbuffer_client_proc_t) (void * ctx, GLenum, GLuint);
typedef void (gl2_APIENTRY *glBindTexture_client_proc_t) (void * ctx, GLenum, GLuint);
typedef void (gl2_APIENTRY *glBlendColor_client_proc_t) (void * ctx, GLclampf, GLclampf, GLclampf, GLclampf);
typedef void (gl2_APIENTRY *glBlendEquation_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glBlendEquationSeparate_client_proc_t) (void * ctx, GLenum, GLenum);
typedef void (gl2_APIENTRY *glBlendFunc_client_proc_t) (void * ctx, GLenum, GLenum);
typedef void (gl2_APIENTRY *glBlendFuncSeparate_client_proc_t) (void * ctx, GLenum, GLenum, GLenum, GLenum);
typedef void (gl2_APIENTRY *glBufferData_client_proc_t) (void * ctx, GLenum, GLsizeiptr, const GLvoid*, GLenum);
typedef void (gl2_APIENTRY *glBufferSubData_client_proc_t) (void * ctx, GLenum, GLintptr, GLsizeiptr, const GLvoid*);
typedef GLenum (gl2_APIENTRY *glCheckFramebufferStatus_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glClear_client_proc_t) (void * ctx, GLbitfield);
typedef void (gl2_APIENTRY *glClearColor_client_proc_t) (void * ctx, GLclampf, GLclampf, GLclampf, GLclampf);
typedef void (gl2_APIENTRY *glClearDepthf_client_proc_t) (void * ctx, GLclampf);
typedef void (gl2_APIENTRY *glClearStencil_client_proc_t) (void * ctx, GLint);
typedef void (gl2_APIENTRY *glColorMask_client_proc_t) (void * ctx, GLboolean, GLboolean, GLboolean, GLboolean);
typedef void (gl2_APIENTRY *glCompileShader_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glCompressedTexImage2D_client_proc_t) (void * ctx, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
typedef void (gl2_APIENTRY *glCompressedTexSubImage2D_client_proc_t) (void * ctx, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
typedef void (gl2_APIENTRY *glCopyTexImage2D_client_proc_t) (void * ctx, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
typedef void (gl2_APIENTRY *glCopyTexSubImage2D_client_proc_t) (void * ctx, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
typedef GLuint (gl2_APIENTRY *glCreateProgram_client_proc_t) (void * ctx);
typedef GLuint (gl2_APIENTRY *glCreateShader_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glCullFace_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glDeleteBuffers_client_proc_t) (void * ctx, GLsizei, const GLuint*);
typedef void (gl2_APIENTRY *glDeleteFramebuffers_client_proc_t) (void * ctx, GLsizei, const GLuint*);
typedef void (gl2_APIENTRY *glDeleteProgram_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glDeleteRenderbuffers_client_proc_t) (void * ctx, GLsizei, const GLuint*);
typedef void (gl2_APIENTRY *glDeleteShader_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glDeleteTextures_client_proc_t) (void * ctx, GLsizei, const GLuint*);
typedef void (gl2_APIENTRY *glDepthFunc_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glDepthMask_client_proc_t) (void * ctx, GLboolean);
typedef void (gl2_APIENTRY *glDepthRangef_client_proc_t) (void * ctx, GLclampf, GLclampf);
typedef void (gl2_APIENTRY *glDetachShader_client_proc_t) (void * ctx, GLuint, GLuint);
typedef void (gl2_APIENTRY *glDisable_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glDisableVertexAttribArray_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glDrawArrays_client_proc_t) (void * ctx, GLenum, GLint, GLsizei);
typedef void (gl2_APIENTRY *glDrawElements_client_proc_t) (void * ctx, GLenum, GLsizei, GLenum, const GLvoid*);
typedef void (gl2_APIENTRY *glEnable_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glEnableVertexAttribArray_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glFinish_client_proc_t) (void * ctx);
typedef void (gl2_APIENTRY *glFlush_client_proc_t) (void * ctx);
typedef void (gl2_APIENTRY *glFramebufferRenderbuffer_client_proc_t) (void * ctx, GLenum, GLenum, GLenum, GLuint);
typedef void (gl2_APIENTRY *glFramebufferTexture2D_client_proc_t) (void * ctx, GLenum, GLenum, GLenum, GLuint, GLint);
typedef void (gl2_APIENTRY *glFrontFace_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glGenBuffers_client_proc_t) (void * ctx, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glGenerateMipmap_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glGenFramebuffers_client_proc_t) (void * ctx, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glGenRenderbuffers_client_proc_t) (void * ctx, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glGenTextures_client_proc_t) (void * ctx, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glGetActiveAttrib_client_proc_t) (void * ctx, GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*);
typedef void (gl2_APIENTRY *glGetActiveUniform_client_proc_t) (void * ctx, GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*);
typedef void (gl2_APIENTRY *glGetAttachedShaders_client_proc_t) (void * ctx, GLuint, GLsizei, GLsizei*, GLuint*);
typedef int (gl2_APIENTRY *glGetAttribLocation_client_proc_t) (void * ctx, GLuint, const GLchar*);
typedef void (gl2_APIENTRY *glGetBooleanv_client_proc_t) (void * ctx, GLenum, GLboolean*);
typedef void (gl2_APIENTRY *glGetBufferParameteriv_client_proc_t) (void * ctx, GLenum, GLenum, GLint*);
typedef GLenum (gl2_APIENTRY *glGetError_client_proc_t) (void * ctx);
typedef void (gl2_APIENTRY *glGetFloatv_client_proc_t) (void * ctx, GLenum, GLfloat*);
typedef void (gl2_APIENTRY *glGetFramebufferAttachmentParameteriv_client_proc_t) (void * ctx, GLenum, GLenum, GLenum, GLint*);
typedef void (gl2_APIENTRY *glGetIntegerv_client_proc_t) (void * ctx, GLenum, GLint*);
typedef void (gl2_APIENTRY *glGetProgramiv_client_proc_t) (void * ctx, GLuint, GLenum, GLint*);
typedef void (gl2_APIENTRY *glGetProgramInfoLog_client_proc_t) (void * ctx, GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (gl2_APIENTRY *glGetRenderbufferParameteriv_client_proc_t) (void * ctx, GLenum, GLenum, GLint*);
typedef void (gl2_APIENTRY *glGetShaderiv_client_proc_t) (void * ctx, GLuint, GLenum, GLint*);
typedef void (gl2_APIENTRY *glGetShaderInfoLog_client_proc_t) (void * ctx, GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (gl2_APIENTRY *glGetShaderPrecisionFormat_client_proc_t) (void * ctx, GLenum, GLenum, GLint*, GLint*);
typedef void (gl2_APIENTRY *glGetShaderSource_client_proc_t) (void * ctx, GLuint, GLsizei, GLsizei*, GLchar*);
typedef const GLubyte* (gl2_APIENTRY *glGetString_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glGetTexParameterfv_client_proc_t) (void * ctx, GLenum, GLenum, GLfloat*);
typedef void (gl2_APIENTRY *glGetTexParameteriv_client_proc_t) (void * ctx, GLenum, GLenum, GLint*);
typedef void (gl2_APIENTRY *glGetUniformfv_client_proc_t) (void * ctx, GLuint, GLint, GLfloat*);
typedef void (gl2_APIENTRY *glGetUniformiv_client_proc_t) (void * ctx, GLuint, GLint, GLint*);
typedef int (gl2_APIENTRY *glGetUniformLocation_client_proc_t) (void * ctx, GLuint, const GLchar*);
typedef void (gl2_APIENTRY *glGetVertexAttribfv_client_proc_t) (void * ctx, GLuint, GLenum, GLfloat*);
typedef void (gl2_APIENTRY *glGetVertexAttribiv_client_proc_t) (void * ctx, GLuint, GLenum, GLint*);
typedef void (gl2_APIENTRY *glGetVertexAttribPointerv_client_proc_t) (void * ctx, GLuint, GLenum, GLvoid**);
typedef void (gl2_APIENTRY *glHint_client_proc_t) (void * ctx, GLenum, GLenum);
typedef GLboolean (gl2_APIENTRY *glIsBuffer_client_proc_t) (void * ctx, GLuint);
typedef GLboolean (gl2_APIENTRY *glIsEnabled_client_proc_t) (void * ctx, GLenum);
typedef GLboolean (gl2_APIENTRY *glIsFramebuffer_client_proc_t) (void * ctx, GLuint);
typedef GLboolean (gl2_APIENTRY *glIsProgram_client_proc_t) (void * ctx, GLuint);
typedef GLboolean (gl2_APIENTRY *glIsRenderbuffer_client_proc_t) (void * ctx, GLuint);
typedef GLboolean (gl2_APIENTRY *glIsShader_client_proc_t) (void * ctx, GLuint);
typedef GLboolean (gl2_APIENTRY *glIsTexture_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glLineWidth_client_proc_t) (void * ctx, GLfloat);
typedef void (gl2_APIENTRY *glLinkProgram_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glPixelStorei_client_proc_t) (void * ctx, GLenum, GLint);
typedef void (gl2_APIENTRY *glPolygonOffset_client_proc_t) (void * ctx, GLfloat, GLfloat);
typedef void (gl2_APIENTRY *glReadPixels_client_proc_t) (void * ctx, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid*);
typedef void (gl2_APIENTRY *glReleaseShaderCompiler_client_proc_t) (void * ctx);
typedef void (gl2_APIENTRY *glRenderbufferStorage_client_proc_t) (void * ctx, GLenum, GLenum, GLsizei, GLsizei);
typedef void (gl2_APIENTRY *glSampleCoverage_client_proc_t) (void * ctx, GLclampf, GLboolean);
typedef void (gl2_APIENTRY *glScissor_client_proc_t) (void * ctx, GLint, GLint, GLsizei, GLsizei);
typedef void (gl2_APIENTRY *glShaderBinary_client_proc_t) (void * ctx, GLsizei, const GLuint*, GLenum, const GLvoid*, GLsizei);
typedef void (gl2_APIENTRY *glShaderSource_client_proc_t) (void * ctx, GLuint, GLsizei, const GLchar*const*, const GLint*);
typedef void (gl2_APIENTRY *glStencilFunc_client_proc_t) (void * ctx, GLenum, GLint, GLuint);
typedef void (gl2_APIENTRY *glStencilFuncSeparate_client_proc_t) (void * ctx, GLenum, GLenum, GLint, GLuint);
typedef void (gl2_APIENTRY *glStencilMask_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glStencilMaskSeparate_client_proc_t) (void * ctx, GLenum, GLuint);
typedef void (gl2_APIENTRY *glStencilOp_client_proc_t) (void * ctx, GLenum, GLenum, GLenum);
typedef void (gl2_APIENTRY *glStencilOpSeparate_client_proc_t) (void * ctx, GLenum, GLenum, GLenum, GLenum);
typedef void (gl2_APIENTRY *glTexImage2D_client_proc_t) (void * ctx, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
typedef void (gl2_APIENTRY *glTexParameterf_client_proc_t) (void * ctx, GLenum, GLenum, GLfloat);
typedef void (gl2_APIENTRY *glTexParameterfv_client_proc_t) (void * ctx, GLenum, GLenum, const GLfloat*);
typedef void (gl2_APIENTRY *glTexParameteri_client_proc_t) (void * ctx, GLenum, GLenum, GLint);
typedef void (gl2_APIENTRY *glTexParameteriv_client_proc_t) (void * ctx, GLenum, GLenum, const GLint*);
typedef void (gl2_APIENTRY *glTexSubImage2D_client_proc_t) (void * ctx, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
typedef void (gl2_APIENTRY *glUniform1f_client_proc_t) (void * ctx, GLint, GLfloat);
typedef void (gl2_APIENTRY *glUniform1fv_client_proc_t) (void * ctx, GLint, GLsizei, const GLfloat*);
typedef void (gl2_APIENTRY *glUniform1i_client_proc_t) (void * ctx, GLint, GLint);
typedef void (gl2_APIENTRY *glUniform1iv_client_proc_t) (void * ctx, GLint, GLsizei, const GLint*);
typedef void (gl2_APIENTRY *glUniform2f_client_proc_t) (void * ctx, GLint, GLfloat, GLfloat);
typedef void (gl2_APIENTRY *glUniform2fv_client_proc_t) (void * ctx, GLint, GLsizei, const GLfloat*);
typedef void (gl2_APIENTRY *glUniform2i_client_proc_t) (void * ctx, GLint, GLint, GLint);
typedef void (gl2_APIENTRY *glUniform2iv_client_proc_t) (void * ctx, GLint, GLsizei, const GLint*);
typedef void (gl2_APIENTRY *glUniform3f_client_proc_t) (void * ctx, GLint, GLfloat, GLfloat, GLfloat);
typedef void (gl2_APIENTRY *glUniform3fv_client_proc_t) (void * ctx, GLint, GLsizei, const GLfloat*);
typedef void (gl2_APIENTRY *glUniform3i_client_proc_t) (void * ctx, GLint, GLint, GLint, GLint);
typedef void (gl2_APIENTRY *glUniform3iv_client_proc_t) (void * ctx, GLint, GLsizei, const GLint*);
typedef void (gl2_APIENTRY *glUniform4f_client_proc_t) (void * ctx, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (gl2_APIENTRY *glUniform4fv_client_proc_t) (void * ctx, GLint, GLsizei, const GLfloat*);
typedef void (gl2_APIENTRY *glUniform4i_client_proc_t) (void * ctx, GLint, GLint, GLint, GLint, GLint);
typedef void (gl2_APIENTRY *glUniform4iv_client_proc_t) (void * ctx, GLint, GLsizei, const GLint*);
typedef void (gl2_APIENTRY *glUniformMatrix2fv_client_proc_t) (void * ctx, GLint, GLsizei, GLboolean, const GLfloat*);
typedef void (gl2_APIENTRY *glUniformMatrix3fv_client_proc_t) (void * ctx, GLint, GLsizei, GLboolean, const GLfloat*);
typedef void (gl2_APIENTRY *glUniformMatrix4fv_client_proc_t) (void * ctx, GLint, GLsizei, GLboolean, const GLfloat*);
typedef void (gl2_APIENTRY *glUseProgram_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glValidateProgram_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glVertexAttrib1f_client_proc_t) (void * ctx, GLuint, GLfloat);
typedef void (gl2_APIENTRY *glVertexAttrib1fv_client_proc_t) (void * ctx, GLuint, const GLfloat*);
typedef void (gl2_APIENTRY *glVertexAttrib2f_client_proc_t) (void * ctx, GLuint, GLfloat, GLfloat);
typedef void (gl2_APIENTRY *glVertexAttrib2fv_client_proc_t) (void * ctx, GLuint, const GLfloat*);
typedef void (gl2_APIENTRY *glVertexAttrib3f_client_proc_t) (void * ctx, GLuint, GLfloat, GLfloat, GLfloat);
typedef void (gl2_APIENTRY *glVertexAttrib3fv_client_proc_t) (void * ctx, GLuint, const GLfloat*);
typedef void (gl2_APIENTRY *glVertexAttrib4f_client_proc_t) (void * ctx, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (gl2_APIENTRY *glVertexAttrib4fv_client_proc_t) (void * ctx, GLuint, const GLfloat*);
typedef void (gl2_APIENTRY *glVertexAttribPointer_client_proc_t) (void * ctx, GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*);
typedef void (gl2_APIENTRY *glViewport_client_proc_t) (void * ctx, GLint, GLint, GLsizei, GLsizei);
typedef void (gl2_APIENTRY *glEGLImageTargetTexture2DOES_client_proc_t) (void * ctx, GLenum, GLeglImageOES);
typedef void (gl2_APIENTRY *glEGLImageTargetRenderbufferStorageOES_client_proc_t) (void * ctx, GLenum, GLeglImageOES);
typedef void (gl2_APIENTRY *glGetProgramBinaryOES_client_proc_t) (void * ctx, GLuint, GLsizei, GLsizei*, GLenum*, GLvoid*);
typedef void (gl2_APIENTRY *glProgramBinaryOES_client_proc_t) (void * ctx, GLuint, GLenum, const GLvoid*, GLint);
typedef void* (gl2_APIENTRY *glMapBufferOES_client_proc_t) (void * ctx, GLenum, GLenum);
typedef GLboolean (gl2_APIENTRY *glUnmapBufferOES_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glTexImage3DOES_client_proc_t) (void * ctx, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
typedef void (gl2_APIENTRY *glTexSubImage3DOES_client_proc_t) (void * ctx, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
typedef void (gl2_APIENTRY *glCopyTexSubImage3DOES_client_proc_t) (void * ctx, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
typedef void (gl2_APIENTRY *glCompressedTexImage3DOES_client_proc_t) (void * ctx, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
typedef void (gl2_APIENTRY *glCompressedTexSubImage3DOES_client_proc_t) (void * ctx, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
typedef void (gl2_APIENTRY *glFramebufferTexture3DOES_client_proc_t) (void * ctx, GLenum, GLenum, GLenum, GLuint, GLint, GLint);
typedef void (gl2_APIENTRY *glBindVertexArrayOES_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glDeleteVertexArraysOES_client_proc_t) (void * ctx, GLsizei, const GLuint*);
typedef void (gl2_APIENTRY *glGenVertexArraysOES_client_proc_t) (void * ctx, GLsizei, GLuint*);
typedef GLboolean (gl2_APIENTRY *glIsVertexArrayOES_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glDiscardFramebufferEXT_client_proc_t) (void * ctx, GLenum, GLsizei, const GLenum*);
typedef void (gl2_APIENTRY *glMultiDrawArraysEXT_client_proc_t) (void * ctx, GLenum, GLint*, GLsizei*, GLsizei);
typedef void (gl2_APIENTRY *glMultiDrawElementsEXT_client_proc_t) (void * ctx, GLenum, const GLsizei*, GLenum, const GLvoid**, GLsizei);
typedef void (gl2_APIENTRY *glGetPerfMonitorGroupsAMD_client_proc_t) (void * ctx, GLint*, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glGetPerfMonitorCountersAMD_client_proc_t) (void * ctx, GLuint, GLint*, GLint*, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glGetPerfMonitorGroupStringAMD_client_proc_t) (void * ctx, GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (gl2_APIENTRY *glGetPerfMonitorCounterStringAMD_client_proc_t) (void * ctx, GLuint, GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (gl2_APIENTRY *glGetPerfMonitorCounterInfoAMD_client_proc_t) (void * ctx, GLuint, GLuint, GLenum, GLvoid*);
typedef void (gl2_APIENTRY *glGenPerfMonitorsAMD_client_proc_t) (void * ctx, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glDeletePerfMonitorsAMD_client_proc_t) (void * ctx, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glSelectPerfMonitorCountersAMD_client_proc_t) (void * ctx, GLuint, GLboolean, GLuint, GLint, GLuint*);
typedef void (gl2_APIENTRY *glBeginPerfMonitorAMD_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glEndPerfMonitorAMD_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glGetPerfMonitorCounterDataAMD_client_proc_t) (void * ctx, GLuint, GLenum, GLsizei, GLuint*, GLint*);
typedef void (gl2_APIENTRY *glRenderbufferStorageMultisampleIMG_client_proc_t) (void * ctx, GLenum, GLsizei, GLenum, GLsizei, GLsizei);
typedef void (gl2_APIENTRY *glFramebufferTexture2DMultisampleIMG_client_proc_t) (void * ctx, GLenum, GLenum, GLenum, GLuint, GLint, GLsizei);
typedef void (gl2_APIENTRY *glDeleteFencesNV_client_proc_t) (void * ctx, GLsizei, const GLuint*);
typedef void (gl2_APIENTRY *glGenFencesNV_client_proc_t) (void * ctx, GLsizei, GLuint*);
typedef GLboolean (gl2_APIENTRY *glIsFenceNV_client_proc_t) (void * ctx, GLuint);
typedef GLboolean (gl2_APIENTRY *glTestFenceNV_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glGetFenceivNV_client_proc_t) (void * ctx, GLuint, GLenum, GLint*);
typedef void (gl2_APIENTRY *glFinishFenceNV_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glSetFenceNV_client_proc_t) (void * ctx, GLuint, GLenum);
typedef void (gl2_APIENTRY *glCoverageMaskNV_client_proc_t) (void * ctx, GLboolean);
typedef void (gl2_APIENTRY *glCoverageOperationNV_client_proc_t) (void * ctx, GLenum);
typedef void (gl2_APIENTRY *glGetDriverControlsQCOM_client_proc_t) (void * ctx, GLint*, GLsizei, GLuint*);
typedef void (gl2_APIENTRY *glGetDriverControlStringQCOM_client_proc_t) (void * ctx, GLuint, GLsizei, GLsizei*, GLchar*);
typedef void (gl2_APIENTRY *glEnableDriverControlQCOM_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glDisableDriverControlQCOM_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glExtGetTexturesQCOM_client_proc_t) (void * ctx, GLuint*, GLint, GLint*);
typedef void (gl2_APIENTRY *glExtGetBuffersQCOM_client_proc_t) (void * ctx, GLuint*, GLint, GLint*);
typedef void (gl2_APIENTRY *glExtGetRenderbuffersQCOM_client_proc_t) (void * ctx, GLuint*, GLint, GLint*);
typedef void (gl2_APIENTRY *glExtGetFramebuffersQCOM_client_proc_t) (void * ctx, GLuint*, GLint, GLint*);
typedef void (gl2_APIENTRY *glExtGetTexLevelParameterivQCOM_client_proc_t) (void * ctx, GLuint, GLenum, GLint, GLenum, GLint*);
typedef void (gl2_APIENTRY *glExtTexObjectStateOverrideiQCOM_client_proc_t) (void * ctx, GLenum, GLenum, GLint);
typedef void (gl2_APIENTRY *glExtGetTexSubImageQCOM_client_proc_t) (void * ctx, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLvoid*);
typedef void (gl2_APIENTRY *glExtGetBufferPointervQCOM_client_proc_t) (void * ctx, GLenum, GLvoidptr*);
typedef void (gl2_APIENTRY *glExtGetShadersQCOM_client_proc_t) (void * ctx, GLuint*, GLint, GLint*);
typedef void (gl2_APIENTRY *glExtGetProgramsQCOM_client_proc_t) (void * ctx, GLuint*, GLint, GLint*);
typedef GLboolean (gl2_APIENTRY *glExtIsProgramBinaryQCOM_client_proc_t) (void * ctx, GLuint);
typedef void (gl2_APIENTRY *glExtGetProgramBinarySourceQCOM_client_proc_t) (void * ctx, GLuint, GLenum, GLchar*, GLint*);
typedef void (gl2_APIENTRY *glStartTilingQCOM_client_proc_t) (void * ctx, GLuint, GLuint, GLuint, GLuint, GLbitfield);
typedef void (gl2_APIENTRY *glEndTilingQCOM_client_proc_t) (void * ctx, GLbitfield);
typedef void (gl2_APIENTRY *glVertexAttribPointerData_client_proc_t) (void * ctx, GLuint, GLint, GLenum, GLboolean, GLsizei, void*, GLuint);
typedef void (gl2_APIENTRY *glVertexAttribPointerOffset_client_proc_t) (void * ctx, GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint);
typedef void (gl2_APIENTRY *glDrawElementsOffset_client_proc_t) (void * ctx, GLenum, GLsizei, GLenum, GLuint);
typedef void (gl2_APIENTRY *glDrawElementsData_client_proc_t) (void * ctx, GLenum, GLsizei, GLenum, void*, GLuint);
typedef void (gl2_APIENTRY *glGetCompressedTextureFormats_client_proc_t) (void * ctx, int, GLint*);
typedef void (gl2_APIENTRY *glShaderString_client_proc_t) (void * ctx, GLuint, const GLchar*, GLsizei);
typedef int (gl2_APIENTRY *glFinishRoundTrip_client_proc_t) (void * ctx);


#endif
