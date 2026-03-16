#pragma once

#include <iostream>
#include <string>
#include <plant.h>

using std::cout;

// Класс для домашних растений (наследуется от Plant)
class HousePlant : public Plant {
protected:
    string care_difficulty;
    string toxicity_level;
    string toxicity_effects;
    string positive_qualities;
public:
    HousePlant() : Plant() {
        // cout << "Create house plant" << '\n';
        this->care_difficulty = "unknown";
        this->toxicity_level = "unknown";
        this->toxicity_effects = "unknown";
        this->positive_qualities = "unknown";
    }
    // virtual ~HousePlant() {};
    virtual void water() {
        cout << "Watering the plant" << '\n';
    }
    
    virtual void eat() {
        cout << "You shouldn't eat plant!" << '\n';
    }
    
    string get_toxicity_info() {
        return "Toxicity level: " + toxicity_level + ", Effects: " + toxicity_effects;
    }
    virtual void health(){
        cout << "nothing" << '\n';
    }
    void print_info() {
        cout << "\n=== " << name << " ===\n";
        cout << "Climate: " << climate << '\n';
        cout << "Max height: " << max_height << "m\n";
        cout << "Lifetime: " << lifetime << " years\n";
        cout << "Temperature range: " << min_temp << "°C to " << max_temp << "°C\n";
        cout << "Watering every " << watering << " days\n";
        cout << "Care difficulty: " << care_difficulty << '\n';
        cout << get_toxicity_info() << '\n';
    }
};

// ==================== ЯДОВИТЫЕ РАСТЕНИЯ (3 вида) ====================

class Dieffenbachia : public HousePlant {
public:
    Dieffenbachia() {
        this->name = "Dieffenbachia";
        this->climate = "Tropical";
        this->max_height = 1.8;
        this->lifetime = 5;
        this->min_temp = 15;
        this->max_temp = 30;
        this->watering = 7;
        this->care_difficulty = "Medium";
        this->toxicity_level = "HIGH";
        this->toxicity_effects = "Swelling of tongue and throat, difficulty speaking, burning pain";
    }
    
    void touch() override {
        cout << "Beautiful variegated leaves, but be careful - it's poisonous!" << '\n';
    }
    
    void shake() override {
        cout << "The leaves rustle softly, but you better wash your hands after touching" << '\n';
    }
    
    void water() override {
        cout << "Water when top soil is dry. Avoid overwatering!" << '\n';
    }
    
    void eat() override {
        cout << "NEVER DO THIS! Dieffenbachia causes severe swelling of the mouth and throat!" << '\n';
    }
};

class Oleander : public HousePlant {
public:
    Oleander() {
        this->name = "Oleander";
        this->climate = "Subtropical";
        this->max_height = 3.0;
        this->lifetime = 20;
        this->min_temp = 5;
        this->max_temp = 35;
        this->watering = 5;
        this->care_difficulty = "Easy";
        this->toxicity_level = "EXTREME";
        this->toxicity_effects = "Cardiac problems, nausea, vomiting, can be fatal";
    }
    
    void touch() override {
        cout << "Beautiful pink flowers, but every part of this plant is highly toxic" << '\n';
    }
    
    void shake() override {
        cout << "The branches are flexible, but avoid getting sap on your skin" << '\n';
    }
    
    void water() override {
        cout << "Water regularly, but allow soil to dry between waterings" << '\n';
    }
    
    void eat() override {
        cout << "EMERGENCY! Call poison control immediately! Oleander is extremely poisonous!" << '\n';
    }
};

class Euphorbia : public HousePlant {
public:
    Euphorbia() {
        this->name = "Euphorbia";
        this->climate = "Arid/Semi-arid";
        this->max_height = 1.5;
        this->lifetime = 10;
        this->min_temp = 10;
        this->max_temp = 30;
        this->watering = 14;
        this->care_difficulty = "Easy";
        this->toxicity_level = "HIGH";
        this->toxicity_effects = "Skin irritation, eye inflammation, nausea if ingested";
    }
    
    void touch() override {
        cout << "The milky sap can cause severe skin irritation!" << '\n';
    }
    
    void shake() override {
        cout << "Better not shake it - the sap might splatter" << '\n';
    }
    
    void water() override {
        cout << "Water sparingly. Let soil dry completely between waterings" << '\n';
    }
    
    void eat() override {
        cout << "The milky sap is toxic! Causes burning in mouth and digestive issues" << '\n';
    }
};

// ==================== МЕНЕЕ ЯДОВИТЫЕ РАСТЕНИЯ (3 вида) ====================

class Spathiphyllum : public HousePlant {
public:
    Spathiphyllum() {
        this->name = "Spathiphyllum (Peace Lily)";
        this->climate = "Tropical";
        this->max_height = 0.8;
        this->lifetime = 3;
        this->min_temp = 15;
        this->max_temp = 28;
        this->watering = 5;
        this->care_difficulty = "Easy";
        this->toxicity_level = "MODERATE";
        this->toxicity_effects = "Mouth irritation, drooling, difficulty swallowing";
    }
    
    void touch() override {
        cout << "Beautiful white flowers, but keep away from pets" << '\n';
    }
    
    void shake() override {
        cout << "The leaves are elegant and smooth" << '\n';
    }
    
    void water() override {
        cout << "Keep soil moist, but not waterlogged. Drooping leaves indicate need for water" << '\n';
    }
    
    void eat() override {
        cout << "Can cause oral irritation - not deadly but unpleasant" << '\n';
    }
};

class Sansevieria : public HousePlant {
public:
    Sansevieria() {
        this->name = "Sansevieria (Snake Plant)";
        this->climate = "Arid";
        this->max_height = 1.2;
        this->lifetime = 5;
        this->min_temp = 10;
        this->max_temp = 35;
        this->watering = 21;
        this->care_difficulty = "Very Easy";
        this->toxicity_level = "MILD TO MODERATE";
        this->toxicity_effects = "Nausea, vomiting, diarrhea if ingested";
    }
    
    void touch() override {
        cout << "Sharp, upright leaves - good air purifier but mildly toxic" << '\n';
    }
    
    void shake() override {
        cout << "The leaves are stiff, almost no movement" << '\n';
    }
    
    void water() override {
        cout << "Very drought tolerant. Water only when soil is completely dry" << '\n';
    }
    
    void eat() override {
        cout << "Contains saponins - causes gastrointestinal distress" << '\n';
    }
};

class Ivy : public HousePlant {
public:
    Ivy() {
        this->name = "Hedera helix (English Ivy)";
        this->climate = "Temperate";
        this->max_height = 2.0;
        this->lifetime = 10;
        this->min_temp = 5;
        this->max_temp = 25;
        this->watering = 7;
        this->care_difficulty = "Medium";
        this->toxicity_level = "MODERATE";
        this->toxicity_effects = "Skin irritation, stomach upset if eaten";
    }
    
    void touch() override {
        cout << "Beautiful climbing plant, but can cause skin irritation" << '\n';
    }
    
    void shake() override {
        cout << "The vines sway gently" << '\n';
    }
    
    void water() override {
        cout << "Keep soil consistently moist. Misting helps" << '\n';
    }
 
};

// ==================== БЕЗОПАСНЫЕ РАСТЕНИЯ (3 вида) ====================

class Chlorophytum : public HousePlant {
public:
    Chlorophytum() {
        this->name = "Chlorophytum (Spider Plant)";
        this->climate = "Tropical/Subtropical";
        this->max_height = 0.5;
        this->lifetime = 3;
        this->min_temp = 10;
        this->max_temp = 30;
        this->watering = 7;
        this->care_difficulty = "Easy";
        this->toxicity_level = "NONE";
        this->toxicity_effects = "Non-toxic, safe for humans and pets";
        this->positive_qualities = "they filter harmful volatile organic compounds (VOCs) such as benzene, formaldehyde, xylene, and carbon monoxide from indoor air.";
    }
    
    void touch() override {
        cout << "Long striped leaves - completely safe and great air purifier" << '\n';
    }
    
    void shake() override {
        cout << "The baby plant dangle and sway" << '\n';
    }
    
    void water() override {
        cout << "Water regularly. Brown tips indicate too much fluoride in water" << '\n';
    }
    void health() override{
        cout << positive_qualities;
    }
};

class FicusBenjamina : public HousePlant {
public:
    FicusBenjamina() {
        this->name = "Ficus benjamina (Weeping Fig)";
        this->climate = "Tropical";
        this->max_height = 3.0;
        this->lifetime = 15;
        this->min_temp = 15;
        this->max_temp = 30;
        this->watering = 7;
        this->care_difficulty = "Medium";
        this->toxicity_level = "NONE";
        this->toxicity_effects = "Non-toxic, but some people may have mild latex allergy";
    }
    
    void touch() override {
        cout << "Beautiful glossy leaves - safe for home" << '\n';
    }
    
    void shake() override {
        cout << "The branches are flexible, leaves rustle" << '\n';
    }
    
    void water() override {
        cout << "Water when top inch of soil is dry. Doesn't like to be moved" << '\n';
    }
  
};

class Rosemary : public HousePlant {
public:
    Rosemary(){
        this->name = "Rosemary (Salvia rosmarinus)";
        this->climate = "warm, dry Mediterranean";
        this->max_height = 1.8;
        this->lifetime = 15;
        this->min_temp = 20;
        this->max_temp = 30;
        this->watering = 1;
        this->care_difficulty = "Minimum, but requires full, direct sun";
        this->toxicity_level = "NONE";
        this->toxicity_effects = "Non-toxi";
        this->positive_qualities = "It can absorb harmful substances from the air. If there is smoking in the house, Rosemarys will come in handy.";
    }
    void water() override{
        cout << "Water sparingly; it is highly drought-tolerant once established." << '\n';
    }
    void health() override{
        cout << positive_qualities;
    }
};

// Функция для демонстрации растений
void demonstratePlant(HousePlant* plant) {
    plant->print_info();
    plant->touch();
    plant->shake();
    plant->water();
    plant->eat();
    plant->health();
    cout << "Survival ability score: " << plant->survivalability() << "\n";
    cout << "------------------------\n";
}