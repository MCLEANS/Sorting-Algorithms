#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t file_write = 0;
uint8_t error = 0;

typedef struct{
    float nmea_longitude;
    float nmea_latitude;
    float utc_time;
    char ns, ew;

    char gll_status;

    float speed_k;

    float course_t; 
    char course_t_unit;
    float course_m; 
    char course_m_unit;
    char speed_k_unit;
    float speed_km; 
    char speed_km_unit;
} GNSS_t ;

GNSS_t GNSS;

void nmea_parse(char *nmea_sentence, FILE *log_file){   
    /* Check if sentence contains GNVTG data */ 
    if (strncmp(nmea_sentence, "$GNVTG", 6) == 0){   
        /* We are in a new block so clear all errors from previous block */    
        error = 0;
        const char ch = ',';
        char *ret = strrchr(nmea_sentence,ch); 
        /* Check for missing speed values */
        if(strncmp(",,",ret-1,2) == 0){
            error = 1;
        }
        else{
            /* Get speed values from NMEA sentence */
            sscanf(nmea_sentence,"$GNVTG,%f,%c,%f,%c,%f,%c,%f,%c*", &GNSS.course_t, &GNSS.course_t_unit, &GNSS.course_m, &GNSS.course_m_unit, &GNSS.speed_k, &GNSS.speed_k_unit, &GNSS.speed_km, &GNSS.speed_km_unit);
        }       
    }

    /* Check if sentence contains GNGLL data */ 
    else if (strncmp(nmea_sentence, "$GNGLL", 6) == 0){    
        const char ch = ',';
        char *ret = strrchr(nmea_sentence,ch); 
        /* Check for missing time values */
        if(strncmp(",,",ret-1,2) == 0){
            error = 1;
        }
        else{
            sscanf(nmea_sentence,  "$GNGLL,%f,%c,%f,%c,%f,%c*", &GNSS.nmea_latitude, &GNSS.ns, &GNSS.nmea_longitude, &GNSS.ew, &GNSS.utc_time, &GNSS.gll_status);
            /* $GNGLL is last statement in NMEA data block, activate file write flag */
            file_write = 1;
        }      

    }

    if(file_write && !error){
        fprintf(log_file,"%.2f,%lf \n", GNSS.utc_time, GNSS.speed_km);
        file_write = 0;
    }
}

int main(int argc, char* argv[]){


    char const* const data_file_name = "data/ridetest";
    char const* const log_file_name = "data/log_file.csv";

    FILE *data_file, *log_file;
    
    data_file = fopen(data_file_name, "r"); 

    if(!data_file){
        printf("\n Unable to open : %s ", data_file_name);
        return -1;
    }

    log_file = fopen(log_file_name, "w"); 

    if(!log_file){
        printf("\n Unable to open : %s ", log_file_name);
        return -1;
    }

    char line[500];
    while (fgets(line, sizeof(line), data_file)) {
        
        nmea_parse(line, log_file);
        
    }

    fclose(data_file);
    fclose(log_file);

    return 0;
}