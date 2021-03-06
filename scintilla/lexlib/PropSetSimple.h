// Scintilla source code edit control
/** @file PropSetSimple.h
 ** A basic string to string map.
 **/
// Copyright 1998-2009 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.
#pragma once

namespace Scintilla {

class PropSetSimple {
	void *impl;
	void Set(const char *keyVal);
public:
	PropSetSimple();
	~PropSetSimple();
	void Set(const char *key, const char *val, size_t lenKey = -1, size_t lenVal = -1);
	//void Set(const char *keyVal);
	//void SetMultiple(const char *s);
	const char *Get(const char *key) const;
	size_t GetExpanded(const char *key, char *result) const;
	int GetInt(const char *key, int defaultValue = 0) const;
};

}
