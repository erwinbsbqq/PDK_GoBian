/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2006-2010, 2012 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

#ifndef BS_ERROR_H
#define BS_ERROR_H

#include "bs_object.h"

/* max size of the error buffer log */
#define BUFFER_LOG_LEN 512

/* defined error codes */
#define BS_ERR_LP_SYNTAX_ERROR                         "L0001"
#define BS_ERR_LP_UNDEFINED_IDENTIFIER                 "L0002"
#define BS_ERR_LP_KEYWORD_RESERVED                     "L0003"
#define BS_ERR_LINK_GLOBAL_TYPE_MISMATCH               "L0001"
#define BS_ERR_LINK_GLOBAL_INITIALIZER_MISMATCH        "L0002"
#define BS_ERR_LINK_GLOBAL_PRECISION_MISMATCH          "L0003"
#define BS_ERR_LINK_TOO_MANY_ATTRIBUTES                "L0004"
#define BS_ERR_LINK_TOO_MANY_UNIFORMS                  "L0005"
#define BS_ERR_LINK_TOO_MANY_VARYINGS                  "L0006"
#define BS_ERR_LINK_FRAGMENT_SHADER_UNDECLARED_VARYING "L0007"
#define BS_ERR_LINK_VARYING_TYPE_MISMATCH              "L0008"
#define BS_ERR_LINK_NO_ENTRY_POINT                     "L0009"
#define BS_ERR_LINK_UNIFORM_TYPE_MISMATCH              "L0010"
#define BS_ERR_OUT_OF_MEMORY                           "F0001"
#define BS_ERR_INTERNAL_COMPILER_ERROR                 "F0002"
#define BS_ERR_NOTE_MESSAGE                            "M0001"

/* These error are those generated by OpenGL ES */
#define BS_ERR_WRONG_ATTACHMENT_COUNT                  "L0100"
#define BS_ERR_SHADERS_NOT_COMPILED                    "L0101"
#define BS_ERR_VALIDATE_FAILED                         "Validate: "

/**
 * @brief retrieves a copy of the log (from a bs_shader or a bs_program) into a buffer
 * @param log The log to retrieve
 * @param bufsize The size of the buffer to copy to (infolog)
 * @param length A pointer to where the length the written log should be placed. May be NULL
 * @param infolog A pointer to the output buffer. May be NULL
 */
MALI_IMPORT void bs_get_log(struct bs_log *log, u32 bufsize, int *length, char *infolog);

/**
 * @brief returns the length of the log
 * @param log The log to check the lenght for
 * @param length A pointer to where the length should be written. Should NOT be NULL.
 */
MALI_IMPORT void bs_get_log_length(struct bs_log *log, int *length);

/**
 * @brief clears the log
 * @param log The shader/program object log to clear
 * @note This is a cleanup function that will delete the log of the given object
 */
MALI_IMPORT void bs_clear_error(struct bs_log *log);

/**
 * @brief sets the log error to out of memory. This require no allocations, but erases the old log.
 * @param log The shader/program object log to to set the error for
 */
MALI_IMPORT void bs_set_error_out_of_memory(struct bs_log *log);

/**
 * @brief Reveals whether the current error log is set to the "out of memory" error.
 *        If this is the case we ran out of memory earlier while setting some
 *        error log.
 * @param log The shader/program object log to check the error log for
 * @return MALI_TRUE if we ran out of memory, otherwise MALI_FALSE
 */
MALI_IMPORT mali_bool bs_is_error_log_set_to_out_of_memory(struct bs_log *log);

/**
 * @brief sets / adds a error log message to the given log
 * @param log the shader/program object log to set the log for.
 * @param errortype An error type as defined in one of the BS_ERR_* defines above
 * @param message Any customized string describing the issue.
 * @return Will not return anything, but on failure the appropriate bs_set_*_out_of_memory
 *         function will be called. The linker/loader will detect out of memory errors by calling
 *         bs_is_*_error_log_set_to_out_of_memory prior to exiting the link/load function,
 *         and handle any memory issues appropriately.
 */
MALI_IMPORT void bs_set_error(struct bs_log* log, char* errortype, char* message );

/**
 * @brief Set an error denoting that a sampler is set to a value out of legal range.
 * @param po The program object to set the error to
 * @param samplername The sampler name that is out of range
 * @param bound_unit the unit that this sampler is bound to
 * @param max_unit The maximal unit that is allowed to bind to. (Min is 0)
 */
MALI_IMPORT void bs_set_program_validate_error_sampler_out_of_range(bs_program* po, char* samplername, unsigned int bound_unit, unsigned int max_unit );

/**
 * @brief Set an error denoting that two samplers are of different types but share a texture unit
 * @param po The program object to set the error to
 * @param samplername1 The name of the first colliding sampler
 * @param samplername2 The name of the second colliding sampler
 * @param unit the unit that they share
 */
MALI_IMPORT void bs_set_program_validate_error_sampler_of_different_types_share_unit(bs_program* po, char* samplername1, char* samplername2, unsigned int unit );

/**
 * @brief set an error denoting that an attribute has been bound so that it extends past the legal range of attribute streams
 * @param po The program object to set the error to
 * @param attributename The name of the attribute bound wrongly
 * @param usedslot The last used slot of the attribute
 * @param maxslot The last legal slot
 */
MALI_IMPORT void bs_set_program_link_error_attribute_bound_outsize_of_legal_range(bs_program* po, char* attributename, unsigned int usedslot, unsigned int maxslot);

/**
 * @brief set an error denoting that a linker error occurred because a verte shader was missing a varying
 * @param po The program object to set the error to
 * @param varyingname the varying name that we are missing in the vertex shader
 */
MALI_IMPORT void bs_set_program_link_error_missing_vertex_shader_varying(bs_program* po, char* varyingname);

/**
 * @brief set an error denoting that a linker error occurred because a varying is mismatched in type between the vertex and fragment shader
 * @param po The program object to set the error to
 * @param reason the reason why we are having a mismatch; ex: "'myVarying' differ on types (vec4 vs vec2)" or something like that.
 */
MALI_IMPORT void bs_set_program_link_error_type_mismatch_varying(bs_program* po, char* reason);

#endif /* BS_ERROR_H */

