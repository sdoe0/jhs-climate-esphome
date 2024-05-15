#pragma once

#include <cstdint>
#include <string>

#include <map>
#include <vector>
#include <array>
#include <map>
#include "esphome/core/optional.h"

using namespace esphome;

const std::array<uint8_t, 3> KEEPALIVE_PACKET{0x30, 0x00, 0x8a};
const std::array<uint8_t, 3> BUTTON_MODE{0x30, 0x02, 0x8c};
const std::array<uint8_t, 3> BUTTON_LOWER_TEMP{0x30, 0x0c, 0x96};
const std::array<uint8_t, 3> BUTTON_ON{0x30, 0x01, 0x8b};
const std::array<uint8_t, 3> BUTTON_TIMER{0x30, 0x00, 0x11};
const std::array<uint8_t, 3> BUTTON_FAN{0x30, 0x07, 0x91};
// const std::array<uint8_t, 3> BUTTON_SWING{0x30, 0x06, 0x90};
const std::array<uint8_t, 3> BUTTON_SLEEP{0x30, 0x11, 0x9b};
const std::array<uint8_t, 3> BUTTON_HIGHER_TEMP{0x30, 0x0b, 0x95};
const std::array<uint8_t, 3> BUTTON_UNIT_CHANGE{0x30, 0x00, 0x92};


///@brief Packet sent from the AC to the panel.
struct JHSAcPacket
{
    uint8_t addr = 0x90; // always 0x90
    uint8_t first_digit = 0; 
    uint8_t second_digit = 0; 
    uint8_t zero0 = 0; 
    uint8_t zero1 = 0;

    uint8_t heat : 1;       
    uint8_t dehum : 1;
    uint8_t fan_high : 1;
    uint8_t cool : 1;       
    uint8_t fan_unused : 1;      
    uint8_t fan : 1; 
    uint8_t timer : 1;      
    uint8_t unused4 : 1;      

    uint8_t fan_low : 1;    
    uint8_t sleep : 1;    
    uint8_t unused_above_timer : 1;
    uint8_t swing : 1;      
    
    uint8_t power : 1;    
    uint8_t water_full : 1;     
    uint8_t unused5 : 1;  
    uint8_t beep_length : 4;
    uint8_t beep_amount : 4;
    uint8_t wifi : 1;
    
    std::string to_string();

    void set_temp(int);
    int get_temp();
    char get_letter(char,char);
    void set_display(std::string);

    ///@brief Parses the packet and checks the checksum.
    static esphome::optional<JHSAcPacket> parse(const std::vector<uint8_t> &data);

    std::vector<uint8_t> to_wire_format();
} __attribute__((packed));
