/**
 * \file Cfg_PosIf.h
 * \brief Header file of position sensor interface configurations
 *
 * \license
 * You can use this file under the terms of the IFX License.
 *
 * This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the IFX License for more details (IFX_License.txt).
 *
 * This file may be used, copied, and distributed, with or without modification, provided
 * that all copyright notices are retained; that all modifications to this file are
 * prominently noted in the modified file; and that this paragraph is not modified.
 *
 * \copyright Copyright (C) 2012 Infineon Technologies AG
 * \author Dian Tresna Nugraha <Dian.Nugraha@Infineon.com>
 *
 * $Revision: 601 $
 * $Date: 2013-02-20 17:13:43 +0100 (Wed, 20 Feb 2013) $
 *
 * \defgroup configuration_pos_sensor Position sensors
 * \ingroup configuration
 *
 */

#ifndef CFG_POSIF_H_
#define CFG_POSIF_H_

#include <Sdadc_Rdc.h>

extern const Sdadc_Rdc_Config cfg_Pos_RdcDs_a;  /**< \brief Details in Cfg_PosIf_RdcDs.c */
extern const Sdadc_Rdc_Config cfg_Pos_RdcDs_b;  /**< \brief Details in Cfg_PosIf_RdcDs.c */

#endif /* CFG_POSIF_H_ */
