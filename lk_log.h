#ifndef __LK_LOG_H__
#define __LK_LOG_H__

#include <stdint.h>

/**
 * @brief 自定义配置
 *
 */
#ifndef LOG_LEVEL
#define LOG_LEVEL      LOG_VERBOSE                 // log等级，0关闭所有log
#endif

#define LOG_TIME_STAMP (rt_tick_get_millisecond()) // 时间戳

#define LOG_FILE __FILE__
// #define LOG_FUNC __FUNCTION__
#define LOG_LINE __LINE__
#define LOG_END  "\r\n"

/**
 * @brief Log字符
 *
 */
// 文件路径:行数
#define _LK_TEXT     "(%d.%03d) %s:%d:"
#define ERROR_TEXT   "E" _LK_TEXT
#define WARNING_TEXT "W" _LK_TEXT
#define INFO_TEXT    "I" _LK_TEXT
#define DEBUG_TEXT   "D" _LK_TEXT
#define VERBOSE_TEXT "V" _LK_TEXT

/**
 * @brief Log等级
 *
 */

#define LOG_NONE    0 // 关闭
#define LOG_ERROR   1 // 错误
#define LOG_WRANING 2 // 警告
#define LOG_INFO    3 // 消息
#define LOG_DEBUG   4 // 调试
#define LOG_VERBOSE 5 // 冗余

/**
 * @brief Log打印接口
 *
 */
#define logFmt(text, level, fmt, ...)                        \
    if (level <= LOG_LEVEL) {                                \
        printf(text " " fmt "" LOG_END,                      \
               LOG_TIME_STAMP / 1000, LOG_TIME_STAMP % 1000, \
               LOG_FILE, LOG_LINE, ##__VA_ARGS__);           \
    }

#define LOG_E(fmt, ...) \
    logFmt(ERROR_TEXT, LOG_ERROR, fmt, ##__VA_ARGS__)

#define LOG_W(fmt, ...) \
    logFmt(WARNING_TEXT, LOG_WRANING, fmt, ##__VA_ARGS__)

#define LOG_I(fmt, ...) \
    logFmt(INFO_TEXT, LOG_INFO, fmt, ##__VA_ARGS__)

#define LOG_D(fmt, ...) \
    logFmt(DEBUG_TEXT, LOG_DEBUG, fmt, ##__VA_ARGS__)

#define LOG_V(fmt, ...) \
    logFmt(VERBOSE_TEXT, LOG_VERBOSE, fmt, ##__VA_ARGS__)

// void bsp_log_dump(const char *buf, uint32_t size, uint32_t number);

#endif /* __LK_LOG_H__ */
