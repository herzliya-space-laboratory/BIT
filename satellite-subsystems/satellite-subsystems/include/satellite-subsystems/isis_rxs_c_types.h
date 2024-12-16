/*
 * isis_rxs_c_types.h
 *
 * AUTOGENERATED CODE
 * Please do not perform manual edits
 * Generated using autogen v1.0.3
 *
 * Generated ICD version: 1.0
 * Generated from: isis_rxs_revc.yaml
 */

#ifndef ISIS_RXS_C_TYPES_H_
#define ISIS_RXS_C_TYPES_H_

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* DEFINES */

#define ISIS_RXS_C_GET_RX_TELEMETRY_ID {0x1A}
#define ISIS_RXS_C_GET_FRAME_COUNT_ID {0x21}
#define ISIS_RXS_C_GET_FRAME_ID {0x22}
#define ISIS_RXS_C_GET_FULL_FRAME_ID {0x23}
#define ISIS_RXS_C_REMOVE_FRAME_ID {0x24}
#define ISIS_RXS_C_GET_FRAME_COUNT_LENGTH_ID {0x25}
#define ISIS_RXS_C_REMOVE_FRAME_ALL_ID {0x26}
#define ISIS_RXS_C_SET_RX_RF_FREQ_ID {0x32}
#define ISIS_RXS_C_GET_RX_RF_FREQ_ID {0x33}
#define ISIS_RXS_C_GET_RX_RF_PLL_ERROR_ID {0x34}
#define ISIS_RXS_C_RX_UPTIME_ID {0x40}
#define ISIS_RXS_C_GET_RX_SWINFO_ID {0x42}
#define ISIS_RXS_C_GET_RX_LAST_RESET_CAUSE_ID {0x50}
#define ISIS_RXS_C_SET_BITRATE_ID {0x70}
#define ISIS_RXS_C_GET_BITRATE_ID {0x71}
#define ISIS_RXS_C_RESET_HW_RX_ID {0xAB}
#define ISIS_RXS_C_RESET_WDG_RX_ID {0xCC}

#define ISIS_RXS_C_GET_FRAME_MAX_DATA_LENGTH 200
#define ISIS_RXS_C_GET_FULL_FRAME_MAX_DATA_LENGTH 218
#define ISIS_RXS_C_GET_FRAME_COUNT_LENGTH_MAX_P_FRAME_LENGTH_LENGTH 80

/* ENUMS */

/*!
 * RXS bitrate
 */
typedef enum __attribute__ ((__packed__)) isis_rxs_c__rxs_bitrate_t
{
    isis_rxs_c__rxs_bitrate__9k6 = 0u,
    isis_rxs_c__rxs_bitrate__19k2 = 1u,
    isis_rxs_c__rxs_bitrate__38k4 = 2u,
    isis_rxs_c__rxs_bitrate__76k8 = 3u,
} isis_rxs_c__rxs_bitrate_t;

/* STRUCTS */

/*!
 *  ISIS_RXS_C instance structure
 */
typedef struct
{
    uint8_t i2cAddr; /*!< I2C address used for this instance */
    size_t maxReceiveBufferLength;
} ISIS_RXS_C_t;

/*!
 * Structure the parameters received by get_frame.
 */
typedef struct __attribute__((__packed__))
_isis_rxs_c__get_frame__from_t
{
    uint16_t length; /*!< Frame contents size */
    int16_t doppler; /*!< Raw measurement value of the instantaneous Doppler offset of the signal at the receiver port. \note conversion: eng. value = -38.1469726563 * raw + 0*/
    int16_t rssi; /*!< This field contains the measured Received Signal Strength Indicator (RSSI) at the reception time \note conversion: eng. value = -0.5 * raw + -28*/
    uint8_t* data; /*!< Frame contents (maximum length: 200 elements) */
} isis_rxs_c__get_frame__from_t;

/*!
 * Structure the parameters received by get_frame_count_length.
 */
typedef struct __attribute__((__packed__))
_isis_rxs_c__get_frame_count_length__from_t
{
    uint16_t frames_nb; /*!< Number of frames in receive buffer */
    uint16_t* p_frame_length; /*!< Frame contents size (maximum length: 80 elements) */
} isis_rxs_c__get_frame_count_length__from_t;

/*!
 * Structure the parameters received by get_full_frame.
 */
typedef struct __attribute__((__packed__))
_isis_rxs_c__get_full_frame__from_t
{
    uint16_t length; /*!< Full frame contents size */
    int16_t doppler; /*!< Raw measurement value of the instantaneous Doppler offset of the signal at the receiver port. \note conversion: eng. value = -38.1469726563 * raw + 0*/
    int16_t rssi; /*!< This field contains the measured Received Signal Strength Indicator (RSSI) at the reception time \note conversion: eng. value = -0.5 * raw + -28*/
    uint8_t* data; /*!< Frame contents (maximum length: 218 elements) */
} isis_rxs_c__get_full_frame__from_t;

/*!
 * Union for storing the parameters received by get_rx_rf_pll_error.
 */
typedef union __attribute__((__packed__)) _isis_rxs_c__get_rx_rf_pll_error__from_t
{
    unsigned char raw[4];
    struct __attribute__ ((__packed__))
    {
        uint16_t locked_errcount; /*!< RF locked error count */
        uint16_t freq_errcount; /*!< RF frequency error count */
    } fields;
} isis_rxs_c__get_rx_rf_pll_error__from_t;

/*!
 * Union for storing the parameters received by get_rx_swinfo.
 */
typedef union __attribute__((__packed__)) _isis_rxs_c__get_rx_swinfo__from_t
{
    unsigned char raw[80];
    struct __attribute__ ((__packed__))
    {
        char swinfo[80]; /*!< Firmware information */
    } fields;
} isis_rxs_c__get_rx_swinfo__from_t;

/*!
 * Union for storing the parameters received by get_rx_telemetry.
 */
typedef union __attribute__((__packed__)) _isis_rxs_c__get_rx_telemetry__from_t
{
    unsigned char raw[16];
    struct __attribute__ ((__packed__))
    {
        int16_t doppler; /*!< Raw measurement value of the instantaneous Doppler offset of the signal at the receiver port. \note conversion: eng. value = -38.1469726563 * raw + 0*/
        int16_t rssi; /*!< This field contains the measured Received Signal Strength Indicator (RSSI) at the reception time \note conversion: eng. value = -0.5 * raw + -28*/
        uint16_t voltage; /*!< Raw measurement value of the power bus voltage. \note conversion: eng. value = 0.004912686 * raw + 0.06*/
        uint16_t current_total; /*!< Raw measurement value of the total supply current. \note conversion: eng. value = 0.076312576 * raw */
        int16_t temp_rf; /*!< Raw measurement value of the RXS temperature. \note conversion: eng. value = 0.061035 * raw + -50*/
        int16_t temp_board; /*!< Raw measurement of board temperature \note conversion: eng. value = 0.061035 * raw + -50*/
        int16_t last_doppler; /*!< Last packed received Doppler offset at the receiver port. \note conversion: eng. value = -38.1469726563 * raw + 0*/
        int16_t last_rssi; /*!< Last packed received Received Signal Strength Indicator (RSSI) at the receiver port \note conversion: eng. value = -0.5 * raw + -28*/
    } fields;
} isis_rxs_c__get_rx_telemetry__from_t;

#ifdef __cplusplus
}
#endif

#endif /* ISIS_RXS_C_TYPES_H_ */

