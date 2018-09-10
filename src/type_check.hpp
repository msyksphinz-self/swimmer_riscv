#pragma once

template<class T> struct TypeIsByte  { static const bool value = false; };
template<> struct TypeIsByte<Byte_t> { static const bool value = true; };

template<class T> struct TypeIsHWord   { static const bool value = false; };
template<> struct TypeIsHWord<HWord_t> { static const bool value = true; };

template<class T> struct TypeIsWord  { static const bool value = false; };
template<> struct TypeIsWord<Word_t> { static const bool value = true; };

template<class T> struct TypeIsDWord   { static const bool value = false; };
template<> struct TypeIsDWord<DWord_t> { static const bool value = true; };
