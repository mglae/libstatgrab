/*
 * i-scream libstatgrab
 * http://www.i-scream.org
 * Copyright (C) 2000-2004 i-scream
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307 USA
 *
 * $Id$
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>

#include "statgrab.h"

static sg_error error = SG_ERROR_NONE;

void sg_set_error(sg_error code, const char *arg) {
	error = code;
	/* FIXME do something with arg */
}

sg_error sg_get_error() {
	return error;
}

const char *sg_str_error(sg_error code) {
	switch (code) {
	case SG_ERROR_NONE:
		return "no error";
	case SG_ERROR_UNSUPPORTED:
		return "unsupported function";
	case SG_ERROR_MALLOC:
		return "malloc failed";
	case SG_ERROR_KSTAT_OPEN:
		return "failed to open kstat";
	case SG_ERROR_OPEN:
		return "failed to open file";
	case SG_ERROR_SYSCTLBYNAME:
		return "sysctlbyname failed";
	case SG_ERROR_SYSCTL:
		return "sysctl failed";
	case SG_ERROR_PARSE:
		return "failed to parse input";
	case SG_ERROR_GETMNTINFO:
		return "getmntinfo failed";
	case SG_ERROR_SETMNTENT:
		return "setmntent failed";
	case SG_ERROR_DEVSTAT_GETDEVS:
		return "devstat_getdevs failed";
	case SG_ERROR_DEVSTAT_SELECTDEVS:
		return "devstat_selectdevs failed";
	case SG_ERROR_ASPRINTF:
		return "asprintf failed";
	default:
		return "unknown error";
	}
}

