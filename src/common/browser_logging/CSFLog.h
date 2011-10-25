/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is the Cisco Systems SIP Stack.
 *
 * The Initial Developer of the Original Code is
 * Cisco Systems (CSCO).
 * Portions created by the Initial Developer are Copyright (C) 2002
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *  Enda Mannion <emannion@cisco.com>
 *  Suhas Nandakumar <snandaku@cisco.com>
 *  Ethan Hugg <ehugg@cisco.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef CSFLOG_H
#define CSFLOG_H

#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>



typedef enum{
	CSF_LOG_CRITICAL =1,
	CSF_LOG_ERROR,
	CSF_LOG_WARNING,
	CSF_LOG_NOTICE,
	CSF_LOG_INFO,
	CSF_LOG_DEBUG
} CSFLogLevel;



/**
* CSFLogError - same as CSFLogCritical but for ERROR log level
*
*/
#define CSFLogError(tag , format, ...) CSFLog( CSF_LOG_ERROR, __FILE__ , __LINE__ , tag , format , ## __VA_ARGS__ )

/**
* CSFLogWarn - same as CSFLogCritical but for WARNING log level
*
*/
#define CSFLogWarn(tag , format, ...) CSFLog( CSF_LOG_WARNING, __FILE__ , __LINE__ , tag , format , ## __VA_ARGS__ )


/**
* CSFLogInfo - same as CSFLogCritical but for INFO log level
*
*/
#define CSFLogInfo(tag , format, ...) CSFLog( CSF_LOG_INFO, __FILE__ , __LINE__ , tag , format , ## __VA_ARGS__ )

/**
* CSFLogDebug - same as CSFLogCritical but for DEBUG level
* 
*/
#define CSFLogDebug(tag , format, ...) CSFLog(CSF_LOG_DEBUG, __FILE__ , __LINE__ , tag , format , ## __VA_ARGS__ )
#define CSFLogDebugV(tag , format, va_list_arg) CSFLogV(CSF_LOG_DEBUG, __FILE__ , __LINE__ , tag , format , va_list_arg )

	
void CSFLog( CSFLogLevel priority, const char* sourceFile, int sourceLine, const char* tag , const char* format, ...);
void CSFLogV( CSFLogLevel priority, const char* sourceFile, int sourceLine, const char* tag , const char* format, va_list args);


#define CSFLogCriticalS(tag, message)	{ std::ostringstream _oss; _oss << message << std::endl; CSFLog( CSF_LOG_CRITICAL, __FILE__ , __LINE__ , tag, _oss.str().c_str()); }
#define CSFLogErrorS(tag, message)		{ std::ostringstream _oss; _oss << message << std::endl; CSFLog( CSF_LOG_ERROR, __FILE__ , __LINE__ , tag, _oss.str().c_str()); }
#define CSFLogWarnS(tag, message)		{ std::ostringstream _oss; _oss << message << std::endl; CSFLog( CSF_LOG_WARNING, __FILE__ , __LINE__ , tag, _oss.str().c_str()); }
#define CSFLogNoticeS(tag, message)		{ std::ostringstream _oss; _oss << message << std::endl; CSFLog( CSF_LOG_NOTICE, __FILE__ , __LINE__ , tag, _oss.str().c_str()); }
#define CSFLogInfoS(tag, message)		{ std::ostringstream _oss; _oss << message << std::endl; CSFLog( CSF_LOG_INFO, __FILE__ , __LINE__ , tag, _oss.str().c_str()); }
#define CSFLogDebugS(tag, message)		{ std::ostringstream _oss; _oss << message << std::endl; CSFLog( CSF_LOG_DEBUG, __FILE__ , __LINE__ , tag, _oss.str().c_str()); }

#endif

