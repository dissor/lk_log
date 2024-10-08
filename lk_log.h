#ifndef __LK_LOG_H__
#define __LK_LOG_H__

#include <stdint.h>
#include <stdio.h>

/**
 * @brief 自定义配置
 *
 */
#ifndef LK_LOG_LEVEL
#define LK_LOG_LEVEL LK_LOG_VERBOSE // log等级，0关闭所有log
#endif

#define LK_LOG_TIME_STAMP (rt_tick_get_millisecond()) // 时间戳

#define LK_LOG_FILE __FILE__
// #define LK_LOG_FUNC __FUNCTION__
#define LK_LOG_LINE __LINE__
#define LK_LOG_END  "\r\n"

#define dump_print     printf
#define __is_print(ch) ((unsigned int)((ch) - ' ') < 127u - ' ')

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

#define LK_LOG_NONE    0 // 关闭
#define LK_LOG_ERROR   1 // 错误
#define LK_LOG_WRANING 2 // 警告
#define LK_LOG_INFO    3 // 消息
#define LK_LOG_DEBUG   4 // 调试
#define LK_LOG_VERBOSE 5 // 冗余

/**
 * @brief Log打印接口
 *
 */
#define logFmt(text, level, fmt, ...)                              \
    if (level <= LK_LOG_LEVEL) {                                   \
        printf(text " " fmt "" LK_LOG_END,                         \
               LK_LOG_TIME_STAMP / 1000, LK_LOG_TIME_STAMP % 1000, \
               LK_LOG_FILE, LK_LOG_LINE, ##__VA_ARGS__);           \
    }

#define LK_LOG_E(fmt, ...) \
    logFmt(ERROR_TEXT, LK_LOG_ERROR, fmt, ##__VA_ARGS__)

#define LK_LOG_W(fmt, ...) \
    logFmt(WARNING_TEXT, LK_LOG_WRANING, fmt, ##__VA_ARGS__)

#define LK_LOG_I(fmt, ...) \
    logFmt(INFO_TEXT, LK_LOG_INFO, fmt, ##__VA_ARGS__)

#define LK_LOG_D(fmt, ...) \
    logFmt(DEBUG_TEXT, LK_LOG_DEBUG, fmt, ##__VA_ARGS__)

#define LK_LOG_V(fmt, ...) \
    logFmt(VERBOSE_TEXT, LK_LOG_VERBOSE, fmt, ##__VA_ARGS__)

/**
 * @brief 16进制打印数据
 *
 * @param buf 数据区
 * @param size 数据区大小
 * @param number 每行输出数据的数量
 */
#if 0
static void LK_LOG_HEX(const char *buf, uint32_t size, uint32_t number) {
    for (uint32_t i = 0; i < size; i += number) {
        dump_print("%08X: ", i);

        for (uint32_t j = 0; j < number; j++) {
            if (j % 8 == 0) {
                dump_print(" ");
            }

            if (i + j < size)
                dump_print("%02X ", buf[i + j]);
            else
                dump_print("   ");
        }

        dump_print(" ");

        for (uint32_t j = 0; j < number; j++) {
            if (i + j < size) {
                dump_print("%c", __is_print(buf[i + j]) ? buf[i + j] : '.');
            }
        }

        dump_print("\r\n");
    }
}
#endif

// ASS
#define LOG_E LK_LOG_E
#define LOG_W LK_LOG_W
#define LOG_I LK_LOG_I
#define LOG_D LK_LOG_D
#define LOG_V LK_LOG_V

#endif /* __LK_LOG_H__ */
