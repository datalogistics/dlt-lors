#ifndef __LORS_ERROR_H__
#define __LORS_ERROR_H__
/**
 * @defgroup lors_api_errors The LoRS Error List
 * @{
 */

/** @brief The operation succeeded.  */
#define LORS_SUCCESS                0x00
/** @brief If there is nothign more specific, this indicates failure. */
#define LORS_FAILURE                -1
/** @brief The operation, store or copy, partially succeeded/failed. */
#define LORS_PARTIAL                -2
/** @brief The requested offset is larger than the length of data. */ 
#define LORS_OFFSET_OUTOFBOUNDS     -3
/** @brief The requested length is larger than the length of data. */ 
#define LORS_LENGTH_OUTOFBOUNDS     -4
/** @brief The timeout expired. */ 
#define LORS_TIMEOUT_EXPIRED        -6
/** @brief The work queue is exhausted. */
#define LORS_NO_JOBS_FOUND          -7
/** @brief When calling an application that must make allocations, in the event that
 * no depots are available to satisfy the next allocation, this error is
 * returned. */
#define LORS_NO_AVAILABLE_DEPOT     -8
/** @brief The requested range (from offset to offset plus length) has a sub-range
 * without any mappings.  This can be generated by @c lorsSetCopy() or @c
 * lorsSetLoad() */
#define LORS_HAS_HOLE               -9
/** @brief There are no available depots with enough space or duration.
 * Another call to @c lorsGetDepotPool() may be necessary */
#define LORS_NO_DEPOTS_FOUND        -10
/** @brief Reserved for future use. */
#define LORS_IS_CODINGBLOCK         -11
/** @brief Reserved for future use. */
#define LORS_IS_NOT_CODINGBLOCK     -12
/** @brief The requested file does not have adequate (read or write) permissions. */
#define LORS_FILE_PERMISSIONS       -14
/** @brief Was unable to parse or generate XML. */ 
#define LORS_XML_ERROR              -15
/** @brief A requested metadata value was not found. */
#define LORS_NOTFOUND          -17
/** @brief The system failed to allocate memory for this operation. */
#define LORS_NO_MEMORY              -18
/** @brief In @c lorsSetStore() when passing less data than needed for an
 * operation. */
#define LORS_MISALINED_LENGTH       -19
/** @brief When attempting to add a Mapping to a Set where it exists already.  */
#define LORS_EXISTS                 -20
/** @brief When iterating through a metadata list, this is returned when the
 * end of the list is reached. */
#define LORS_END                    -21
/** @brief A general error to indicate than one of the parameters passed to
 * the function is invalid. */
#define LORS_INVALID_PARAMETERS     -22
/** @brief There are no available depots from which to get the data. */
#define LORS_NO_SOURCE              -23
/** @brief There are no available depots to which to send the data. */
#define LORS_NO_DESTINATION         -24
#define LORS_EOF                    -25
/** @brief The system failed to create a new thread to complete this operation. */ 
#define LORS_PTHREAD_CREATE_FAILED  -101
/** @brief The system was unable to cancel a thread working on this operation. */
#define LORS_PTHREAD_CANCELED       -102

/** @brief This error was returned by the IBP client. To determine the IBP error, 
 * add 10000 and look in ibp_protocol.h. For example, error -10042 is 
 * IBP error -42, which is IBP_E_CLIENT_TIMEOUT. */
#define LORS_IBP_FAILED       -10000

/** @brief This error was returned by the L-Bone client. To determine the
 * L-Bone error, add 20000 and look in lbone_error.h. For example, error
 * -20030 is L-Bone error 30, which is E_ALLOC. */
#define LORS_LBONE_FAILED     -20000
#define LBONE_NO_DEPOTS       -20001

/** @brief A system call has failed. */
#define LORS_SYS_FAILED       -30000

#define LORS_EBUSY                   -30
#define LORS_EAGAIN                  -31
#define LORS_ERANGE                  -32

/**
 * @}
 */

#endif
