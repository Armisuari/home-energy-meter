#pragma once

#include "PZEMDefiniton.h"

#include <PZEM004Tv30.h>

typedef struct
{
    /* data */
    float voltage[CONFIG_PZEM004T_NUM];
    float current[CONFIG_PZEM004T_NUM];
    float power[CONFIG_PZEM004T_NUM];
    float energy[CONFIG_PZEM004T_NUM];
    float frequency[CONFIG_PZEM004T_NUM];
    float pf[CONFIG_PZEM004T_NUM];

} PZEMData_t;

class PZEM004t_
{
private:
    /* data */
    TaskHandle_t _taskHandle;

    PZEM004Tv30 pzems[CONFIG_PZEM004T_NUM];

    static void _staticTaskFunc(void *pvParam);
    void _taskFunc();

public:
    PZEM004t_(/* args */);
    ~PZEM004t_();

    bool begin();
};
