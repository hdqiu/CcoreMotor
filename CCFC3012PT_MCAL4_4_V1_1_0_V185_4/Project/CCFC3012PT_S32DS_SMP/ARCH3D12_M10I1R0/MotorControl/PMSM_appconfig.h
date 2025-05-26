/**********************************************************************/
// File Name: {FM_project_loc}/PMSM_appconfig.h 
//
// Date:  13. February, 2024
//
// Automatically generated file by MCAT
// - static configuration of the PMSM FOC application
/**********************************************************************/

#ifndef __PMSM_APPCONFIG_H
#define __PMSM_APPCONFIG_H


//Motor Parameters                      
//----------------------------------------------------------------------
//Pole-pair number                      = 3 [-]
//Stator resistance                     = 0.376 [Ohms]
//Direct axis inductance                = 0.00022 [H]
//Quadrature axis inductance            = 0.00027 [H]
//Back-EMF constant                     = 0.0070665 [V.sec/rad]
//Drive inertia                         = 0.000001 [kg.m2]
//Nominal current                       = 10 [A]
//Nominal speed                         = 300 [rpm]

#define MOTOR_PP                        (3.0F)
#define MOTOR_PP_GAIN                   (1.0F)
#define MOTOR_PP_SHIFT                  (0)

//Application scales                    
//----------------------------------------------------------------------
#define I_MAX                           (50.0F)
#define U_DCB_MAX                       (200.0F)
#define N_MAX                           (3300.0F)
#define WEL_MAX                         (1036.73F)

//Application Fault Triggers            
//----------------------------------------------------------------------
#define U_DCB_TRIP                      (100.0F)
#define U_DCB_UNDER                     (10.0F)
#define U_DCB_OVER                      (100.0F)
#define I_PH_OVER                       (1000.1F)
#define TEMP_OVER                       (100.0F)

//DC Bus voltage IIR1 filter constants  
//----------------------------------------------------------------------
//Cut-off frequency                     = 100 [Hz]
//Sample time                           = 0.0001 [sec]
//----------------------------------------------------------------------
#define UDCB_IIR_B0                     (0.030459027951421222F)
#define UDCB_IIR_B1                     (0.030459027951421222F)
#define UDCB_IIR_A1                     (-0.9390819440971575F)
//Mechanical Alignment                  
#define ALIGN_VOLTAGE                   (0.15F)
#define ALIGN_DURATION                  (10000)

//Current Loop Control                  
//----------------------------------------------------------------------
//Loop Bandwidth                        = 400 [Hz]
//Loop Attenuation                      = 0.707 [-]
//Loop sample time                      = 0.0001 [sec]
//----------------------------------------------------------------------
//Current Controller Output Limit       
#define CLOOP_LIMIT                     (0.9F)
//D-axis Controller - Parallel type     
#define D_KP_GAIN                       (0.4058293141429703F)
#define D_KI_GAIN                       (0.0694820149836691F)
#define D_B0                            (0.25507659274780175F)
#define D_B1                            (0.0F)
#define D_A1                            (-0.7449234072521982F)
//Q-axis Controller - Parallel type     
#define Q_KP_GAIN                       (0.583517794630009F)
#define Q_KI_GAIN                       (0.08527338202541205F)
#define Q_B0                            (0.22616997720882156F)
#define Q_B1                            (0.0F)
#define Q_A1                            (-0.7738300227911784F)

//Speed Loop Control                    
//----------------------------------------------------------------------
//Loop Bandwidth                        = 5 [Hz]
//Loop Attenuation                      = 1 [-]
//Loop sample time                      = 0.001 [sec]
//----------------------------------------------------------------------
//Speed Controller - Parallel type      
#define SPEED_PI_PROP_GAIN              (0.0036110260386089574F)
#define SPEED_PI_INTEG_GAIN             (0.000028360932187038382F)//(0.0) //(0.000028360932187038382F)
#define SPEED_LOOP_HIGH_LIMIT           (5.0F)
#define SPEED_LOOP_LOW_LIMIT            (-5.0F)

#define SPEED_RAMP_UP                   (2.67035F)
#define SPEED_RAMP_DOWN                 (2.67035F)

#define SPEED_LOOP_CNTR                 (10)

#define POSPE_SPEED_FILTER_MA_LAMBDA    (0.5F)

//Position & Speed Sensors Module       
//Loop sample time                      = 0.0001 [sec]
//----------------------------------------------------------------------
//Resolver Loop Bandwidth               = 100 [Hz]
//Resolver Loop Attenuation             = 1 [-]
#define POSPE_RES_TO_CC1                (1276.376270238096F)
#define POSPE_RES_TO_CC2                (-1236.8978526337387F)
#define POSPE_RES_TO_INTEG_GAIN         (0.00005F)
#define RES_PP_GAIN                     (1.0F)

//Control Structure Module - Scalar Control
//----------------------------------------------------------------------
#define SCALAR_VHZ_FACTOR_GAIN          (0.00549084553667039F)
#define SCALAR_INTEG_GAIN               FRAC32(0.0165)
#define SCALAR_INTEG_SHIFT              (0)
#define SCALAR_RAMP_UP                  (0.26704F)
#define SCALAR_RAMP_DOWN                (0.26704F)

//FreeMASTER Scale Variables            
//----------------------------------------------------------------------
//Note: Scaled at input = 1000          
//----------------------------------------------------------------------
#define FM_SPEED_RAD_MEC_SCALE          (1000)
#define FM_SPEED_RPM_EL_SCALE           (9549)
#define FM_SPEED_RPM_MEC_SCALE          (3183)
#define FM_POSITION_DEG_SCALE           (57296)

#endif

//End of generated file                 
/**********************************************************************/
