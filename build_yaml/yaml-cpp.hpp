// Auto-generated amalgamated yaml-cpp single header (含实现)
// 版本: 1.0.0 (原版 YAML-CPP: 0.8.0)
// 构建日期: 2025-04-26 01:58:04
// 构建系统: Linux LingNc 5.15.167.4-microsoft-standard-WSL2 #1 SMP Tue Nov 5 00:21:55 UTC 2024 x86_64 GNU/Linux
// 此文件包含所有 yaml-cpp 头文件和实现，可独立使用无需链接静态库
#pragma once

// ====== HEADERS ======

// ====== BEGIN yaml-cpp/include/yaml-cpp/yaml.h ======
#ifndef YAML_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define YAML_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/parser.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/parser.h ======
#ifndef PARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define PARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <ios>
#include <memory>

// Expanding include: yaml-cpp/dll.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/dll.h ======
#ifndef DLL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define DLL_H_62B23520_7C8E_11DE_8A39_0800200C9A66

// Definition YAML_CPP_STATIC_DEFINE using to building YAML-CPP as static
// library (definition created by CMake or defined manually)

// Definition yaml_cpp_EXPORTS using to building YAML-CPP as dll/so library
// (definition created by CMake or defined manually)

#ifdef YAML_CPP_STATIC_DEFINE
#  define YAML_CPP_API
#  define YAML_CPP_NO_EXPORT
#else
#  if defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__)
#    ifndef YAML_CPP_API
#      ifdef yaml_cpp_EXPORTS
         /* We are building this library */
#        define YAML_CPP_API __declspec(dllexport)
#      else
         /* We are using this library */
#        define YAML_CPP_API __declspec(dllimport)
#      endif
#    endif
#    ifndef YAML_CPP_NO_EXPORT
#      define YAML_CPP_NO_EXPORT
#    endif
#  else /* No _MSC_VER */
#    ifndef YAML_CPP_API
#      ifdef yaml_cpp_EXPORTS
         /* We are building this library */
#        define YAML_CPP_API __attribute__((visibility("default")))
#      else
         /* We are using this library */
#        define YAML_CPP_API __attribute__((visibility("default")))
#      endif
#    endif
#    ifndef YAML_CPP_NO_EXPORT
#      define YAML_CPP_NO_EXPORT __attribute__((visibility("hidden")))
#    endif
#  endif /* _MSC_VER */
#endif   /* YAML_CPP_STATIC_DEFINE */

#ifndef YAML_CPP_DEPRECATED
#  ifdef _MSC_VER
#    define YAML_CPP_DEPRECATED __declspec(deprecated)
#  else
#    define YAML_CPP_DEPRECATED __attribute__ ((__deprecated__))
#  endif
#endif

#ifndef YAML_CPP_DEPRECATED_EXPORT
#  define YAML_CPP_DEPRECATED_EXPORT YAML_CPP_API YAML_CPP_DEPRECATED
#endif

#ifndef YAML_CPP_DEPRECATED_NO_EXPORT
#  define YAML_CPP_DEPRECATED_NO_EXPORT YAML_CPP_NO_EXPORT YAML_CPP_DEPRECATED
#endif

#endif /* DLL_H_62B23520_7C8E_11DE_8A39_0800200C9A66 */
// ====== END yaml-cpp/include/yaml-cpp/dll.h ======


namespace YAML {
class EventHandler;
class Node;
class Scanner;
struct Directives;
struct Token;

/**
 * A parser turns a stream of bytes into one stream of "events" per YAML
 * document in the input stream.
 */
class YAML_CPP_API Parser {
 public:
  /** Constructs an empty parser (with no input. */
  Parser();

  Parser(const Parser&) = delete;
  Parser(Parser&&) = delete;
  Parser& operator=(const Parser&) = delete;
  Parser& operator=(Parser&&) = delete;

  /**
   * Constructs a parser from the given input stream. The input stream must
   * live as long as the parser.
   */
  explicit Parser(std::istream& in);

  ~Parser();

  /** Evaluates to true if the parser has some valid input to be read. */
  explicit operator bool() const;

  /**
   * Resets the parser with the given input stream. Any existing state is
   * erased.
   */
  void Load(std::istream& in);

  /**
   * Handles the next document by calling events on the {@code eventHandler}.
   *
   * @throw a ParserException on error.
   * @return false if there are no more documents
   */
  bool HandleNextDocument(EventHandler& eventHandler);

  void PrintTokens(std::ostream& out);

 private:
  /**
   * Reads any directives that are next in the queue, setting the internal
   * {@code m_pDirectives} state.
   */
  void ParseDirectives();

  void HandleDirective(const Token& token);

  /**
   * Handles a "YAML" directive, which should be of the form 'major.minor' (like
   * a version number).
   */
  void HandleYamlDirective(const Token& token);

  /**
   * Handles a "TAG" directive, which should be of the form 'handle prefix',
   * where 'handle' is converted to 'prefix' in the file.
   */
  void HandleTagDirective(const Token& token);

 private:
  std::unique_ptr<Scanner> m_pScanner;
  std::unique_ptr<Directives> m_pDirectives;
};
}  // namespace YAML

#endif  // PARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/parser.h ======

// Expanding include: yaml-cpp/emitter.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/emitter.h ======
#ifndef EMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include <type_traits>

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#include <string_view>
#endif

// Expanding include: yaml-cpp/binary.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/binary.h ======
#ifndef BASE64_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define BASE64_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>
#include <vector>

// Expanding include: yaml-cpp/dll.h

namespace YAML {
YAML_CPP_API std::string EncodeBase64(const unsigned char *data,
                                      std::size_t size);
YAML_CPP_API std::vector<unsigned char> DecodeBase64(const std::string &input);

class YAML_CPP_API Binary {
 public:
  Binary(const unsigned char *data_, std::size_t size_)
      : m_data{}, m_unownedData(data_), m_unownedSize(size_) {}
  Binary() : Binary(nullptr, 0) {}
  Binary(const Binary &) = default;
  Binary(Binary &&) = default;
  Binary &operator=(const Binary &) = default;
  Binary &operator=(Binary &&) = default;

  bool owned() const { return !m_unownedData; }
  std::size_t size() const { return owned() ? m_data.size() : m_unownedSize; }
  const unsigned char *data() const {
    return owned() ? &m_data[0] : m_unownedData;
  }

  void swap(std::vector<unsigned char> &rhs) {
    if (m_unownedData) {
      m_data.swap(rhs);
      rhs.clear();
      rhs.resize(m_unownedSize);
      std::copy(m_unownedData, m_unownedData + m_unownedSize, rhs.begin());
      m_unownedData = nullptr;
      m_unownedSize = 0;
    } else {
      m_data.swap(rhs);
    }
  }

  bool operator==(const Binary &rhs) const {
    const std::size_t s = size();
    if (s != rhs.size())
      return false;
    const unsigned char *d1 = data();
    const unsigned char *d2 = rhs.data();
    for (std::size_t i = 0; i < s; i++) {
      if (*d1++ != *d2++)
        return false;
    }
    return true;
  }

  bool operator!=(const Binary &rhs) const { return !(*this == rhs); }

 private:
  std::vector<unsigned char> m_data;
  const unsigned char *m_unownedData;
  std::size_t m_unownedSize;
};
}  // namespace YAML

#endif  // BASE64_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/binary.h ======

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/emitterdef.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/emitterdef.h ======
#ifndef EMITTERDEF_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EMITTERDEF_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

namespace YAML {
struct EmitterNodeType {
  enum value { NoType, Property, Scalar, FlowSeq, BlockSeq, FlowMap, BlockMap };
};
}

#endif  // EMITTERDEF_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/emitterdef.h ======

// Expanding include: yaml-cpp/emittermanip.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/emittermanip.h ======
#ifndef EMITTERMANIP_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EMITTERMANIP_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>

namespace YAML {
enum EMITTER_MANIP {
  // general manipulators
  Auto,
  TagByKind,
  Newline,

  // output character set
  EmitNonAscii,
  EscapeNonAscii,
  EscapeAsJson,

  // string manipulators
  // Auto, // duplicate
  SingleQuoted,
  DoubleQuoted,
  Literal,

  // null manipulators
  LowerNull,
  UpperNull,
  CamelNull,
  TildeNull,

  // bool manipulators
  YesNoBool,      // yes, no
  TrueFalseBool,  // true, false
  OnOffBool,      // on, off
  UpperCase,      // TRUE, N
  LowerCase,      // f, yes
  CamelCase,      // No, Off
  LongBool,       // yes, On
  ShortBool,      // y, t

  // int manipulators
  Dec,
  Hex,
  Oct,

  // document manipulators
  BeginDoc,
  EndDoc,

  // sequence manipulators
  BeginSeq,
  EndSeq,
  Flow,
  Block,

  // map manipulators
  BeginMap,
  EndMap,
  Key,
  Value,
  // Flow, // duplicate
  // Block, // duplicate
  // Auto, // duplicate
  LongKey
};

struct _Indent {
  _Indent(int value_) : value(value_) {}
  int value;
};

inline _Indent Indent(int value) { return _Indent(value); }

struct _Alias {
  _Alias(const std::string& content_) : content(content_) {}
  std::string content;
};

inline _Alias Alias(const std::string& content) { return _Alias(content); }

struct _Anchor {
  _Anchor(const std::string& content_) : content(content_) {}
  std::string content;
};

inline _Anchor Anchor(const std::string& content) { return _Anchor(content); }

struct _Tag {
  struct Type {
    enum value { Verbatim, PrimaryHandle, NamedHandle };
  };

  explicit _Tag(const std::string& prefix_, const std::string& content_,
                Type::value type_)
      : prefix(prefix_), content(content_), type(type_) {}
  std::string prefix;
  std::string content;
  Type::value type;
};

inline _Tag VerbatimTag(const std::string& content) {
  return _Tag("", content, _Tag::Type::Verbatim);
}

inline _Tag LocalTag(const std::string& content) {
  return _Tag("", content, _Tag::Type::PrimaryHandle);
}

inline _Tag LocalTag(const std::string& prefix, const std::string content) {
  return _Tag(prefix, content, _Tag::Type::NamedHandle);
}

inline _Tag SecondaryTag(const std::string& content) {
  return _Tag("", content, _Tag::Type::NamedHandle);
}

struct _Comment {
  _Comment(const std::string& content_) : content(content_) {}
  std::string content;
};

inline _Comment Comment(const std::string& content) { return _Comment(content); }

struct _Precision {
  _Precision(int floatPrecision_, int doublePrecision_)
      : floatPrecision(floatPrecision_), doublePrecision(doublePrecision_) {}

  int floatPrecision;
  int doublePrecision;
};

inline _Precision FloatPrecision(int n) { return _Precision(n, -1); }

inline _Precision DoublePrecision(int n) { return _Precision(-1, n); }

inline _Precision Precision(int n) { return _Precision(n, n); }
}

#endif  // EMITTERMANIP_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/emittermanip.h ======

// Expanding include: yaml-cpp/null.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/null.h ======
#ifndef NULL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NULL_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/dll.h
#include <cstddef>

namespace YAML {
class Node;

struct YAML_CPP_API _Null {};
inline bool operator==(const _Null&, const _Null&) { return true; }
inline bool operator!=(const _Null&, const _Null&) { return false; }

YAML_CPP_API bool IsNull(const Node& node);  // old API only
YAML_CPP_API bool IsNullString(const char* str, std::size_t size);

extern YAML_CPP_API _Null Null;
}

#endif  // NULL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/null.h ======

// Expanding include: yaml-cpp/ostream_wrapper.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/ostream_wrapper.h ======
#ifndef OSTREAM_WRAPPER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define OSTREAM_WRAPPER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>
#include <vector>

// Expanding include: yaml-cpp/dll.h

namespace YAML {
class YAML_CPP_API ostream_wrapper {
 public:
  ostream_wrapper();
  explicit ostream_wrapper(std::ostream& stream);
  ostream_wrapper(const ostream_wrapper&) = delete;
  ostream_wrapper(ostream_wrapper&&) = delete;
  ostream_wrapper& operator=(const ostream_wrapper&) = delete;
  ostream_wrapper& operator=(ostream_wrapper&&) = delete;
  ~ostream_wrapper();

  void write(const std::string& str);
  void write(const char* str, std::size_t size);

  void set_comment() { m_comment = true; }

  const char* str() const {
    if (m_pStream) {
      return nullptr;
    } else {
      m_buffer[m_pos] = '\0';
      return &m_buffer[0];
    }
  }

  std::size_t row() const { return m_row; }
  std::size_t col() const { return m_col; }
  std::size_t pos() const { return m_pos; }
  bool comment() const { return m_comment; }

 private:
  void update_pos(char ch);

 private:
  mutable std::vector<char> m_buffer;
  std::ostream* const m_pStream;

  std::size_t m_pos;
  std::size_t m_row, m_col;
  bool m_comment;
};

template <std::size_t N>
inline ostream_wrapper& operator<<(ostream_wrapper& stream,
                                   const char (&str)[N]) {
  stream.write(str, N - 1);
  return stream;
}

inline ostream_wrapper& operator<<(ostream_wrapper& stream,
                                   const std::string& str) {
  stream.write(str);
  return stream;
}

inline ostream_wrapper& operator<<(ostream_wrapper& stream, char ch) {
  stream.write(&ch, 1);
  return stream;
}
}  // namespace YAML

#endif  // OSTREAM_WRAPPER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/ostream_wrapper.h ======

// Expanding include: yaml-cpp/fptostring.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/fptostring.h ======
#ifndef YAML_H_FPTOSTRING
#define YAML_H_FPTOSTRING

// Expanding include: yaml-cpp/dll.h

#include <string>

namespace YAML {
// "precision = 0" refers to shortest known unique representation of the value
YAML_CPP_API std::string FpToString(float v, size_t precision = 0);
YAML_CPP_API std::string FpToString(double v, size_t precision = 0);
YAML_CPP_API std::string FpToString(long double v, size_t precision = 0);
}

#endif
// ====== END yaml-cpp/include/yaml-cpp/fptostring.h ======


namespace YAML {
class Binary;
struct _Null;
}  // namespace YAML

namespace YAML {
class EmitterState;

class YAML_CPP_API Emitter {
 public:
  Emitter();
  explicit Emitter(std::ostream& stream);
  Emitter(const Emitter&) = delete;
  Emitter& operator=(const Emitter&) = delete;
  ~Emitter();

  // output
  const char* c_str() const;
  std::size_t size() const;

  // state checking
  bool good() const;
  const std::string GetLastError() const;

  // global setters
  bool SetOutputCharset(EMITTER_MANIP value);
  bool SetStringFormat(EMITTER_MANIP value);
  bool SetBoolFormat(EMITTER_MANIP value);
  bool SetNullFormat(EMITTER_MANIP value);
  bool SetIntBase(EMITTER_MANIP value);
  bool SetSeqFormat(EMITTER_MANIP value);
  bool SetMapFormat(EMITTER_MANIP value);
  bool SetIndent(std::size_t n);
  bool SetPreCommentIndent(std::size_t n);
  bool SetPostCommentIndent(std::size_t n);
  bool SetFloatPrecision(std::size_t n);
  bool SetDoublePrecision(std::size_t n);
  void RestoreGlobalModifiedSettings();

  // local setters
  Emitter& SetLocalValue(EMITTER_MANIP value);
  Emitter& SetLocalIndent(const _Indent& indent);
  Emitter& SetLocalPrecision(const _Precision& precision);

  // overloads of write
  Emitter& Write(const char* str, std::size_t size);
  Emitter& Write(const std::string& str);
  Emitter& Write(bool b);
  Emitter& Write(char ch);
  Emitter& Write(const _Alias& alias);
  Emitter& Write(const _Anchor& anchor);
  Emitter& Write(const _Tag& tag);
  Emitter& Write(const _Comment& comment);
  Emitter& Write(const _Null& n);
  Emitter& Write(const Binary& binary);

  template <typename T>
  Emitter& WriteIntegralType(T value);

  template <typename T>
  Emitter& WriteStreamable(T value);

 private:
  template <typename T>
  void SetStreamablePrecision(std::stringstream&) {}
  std::size_t GetFloatPrecision() const;
  std::size_t GetDoublePrecision() const;

  void PrepareIntegralStream(std::stringstream& stream) const;
  void StartedScalar();

 private:
  void EmitBeginDoc();
  void EmitEndDoc();
  void EmitBeginSeq();
  void EmitEndSeq();
  void EmitBeginMap();
  void EmitEndMap();
  void EmitNewline();
  void EmitKindTag();
  void EmitTag(bool verbatim, const _Tag& tag);

  void PrepareNode(EmitterNodeType::value child);
  void PrepareTopNode(EmitterNodeType::value child);
  void FlowSeqPrepareNode(EmitterNodeType::value child);
  void BlockSeqPrepareNode(EmitterNodeType::value child);

  void FlowMapPrepareNode(EmitterNodeType::value child);

  void FlowMapPrepareLongKey(EmitterNodeType::value child);
  void FlowMapPrepareLongKeyValue(EmitterNodeType::value child);
  void FlowMapPrepareSimpleKey(EmitterNodeType::value child);
  void FlowMapPrepareSimpleKeyValue(EmitterNodeType::value child);

  void BlockMapPrepareNode(EmitterNodeType::value child);

  void BlockMapPrepareLongKey(EmitterNodeType::value child);
  void BlockMapPrepareLongKeyValue(EmitterNodeType::value child);
  void BlockMapPrepareSimpleKey(EmitterNodeType::value child);
  void BlockMapPrepareSimpleKeyValue(EmitterNodeType::value child);

  void SpaceOrIndentTo(bool requireSpace, std::size_t indent);

  const char* ComputeFullBoolName(bool b) const;
  const char* ComputeNullName() const;
  bool CanEmitNewline() const;

 private:
  std::unique_ptr<EmitterState> m_pState;
  ostream_wrapper m_stream;
};

template <typename T>
inline Emitter& Emitter::WriteIntegralType(T value) {
  if (!good())
    return *this;

  PrepareNode(EmitterNodeType::Scalar);

  std::stringstream stream;
  stream.imbue(std::locale("C"));
  PrepareIntegralStream(stream);
  stream << value;
  m_stream << stream.str();

  StartedScalar();

  return *this;
}

template <typename T>
inline Emitter& Emitter::WriteStreamable(T value) {
  if (!good())
    return *this;

  PrepareNode(EmitterNodeType::Scalar);

  std::stringstream stream;
  stream.imbue(std::locale("C"));
  SetStreamablePrecision<T>(stream);

  bool special = false;
  if (std::is_floating_point<T>::value) {
    if ((std::numeric_limits<T>::has_quiet_NaN ||
         std::numeric_limits<T>::has_signaling_NaN) &&
        std::isnan(value)) {
      special = true;
      stream << ".nan";
    } else if (std::numeric_limits<T>::has_infinity && std::isinf(value)) {
      special = true;
      if (std::signbit(value)) {
        stream << "-.inf";
      } else {
        stream << ".inf";
      }
    }
  }

  if (!special) {
    stream << FpToString(value, stream.precision());
  }
  m_stream << stream.str();

  StartedScalar();

  return *this;
}

template <>
inline void Emitter::SetStreamablePrecision<float>(std::stringstream& stream) {
  stream.precision(static_cast<std::streamsize>(GetFloatPrecision()));
}

template <>
inline void Emitter::SetStreamablePrecision<double>(std::stringstream& stream) {
  stream.precision(static_cast<std::streamsize>(GetDoublePrecision()));
}

// overloads of insertion
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
inline Emitter& operator<<(Emitter& emitter, const std::string_view& v) {
  return emitter.Write(v.data(), v.size());
}
#endif
inline Emitter& operator<<(Emitter& emitter, const std::string& v) {
  return emitter.Write(v.data(), v.size());
}
inline Emitter& operator<<(Emitter& emitter, bool v) {
  return emitter.Write(v);
}
inline Emitter& operator<<(Emitter& emitter, char v) {
  return emitter.Write(v);
}
inline Emitter& operator<<(Emitter& emitter, unsigned char v) {
  return emitter.Write(static_cast<char>(v));
}
inline Emitter& operator<<(Emitter& emitter, const _Alias& v) {
  return emitter.Write(v);
}
inline Emitter& operator<<(Emitter& emitter, const _Anchor& v) {
  return emitter.Write(v);
}
inline Emitter& operator<<(Emitter& emitter, const _Tag& v) {
  return emitter.Write(v);
}
inline Emitter& operator<<(Emitter& emitter, const _Comment& v) {
  return emitter.Write(v);
}
inline Emitter& operator<<(Emitter& emitter, const _Null& v) {
  return emitter.Write(v);
}
inline Emitter& operator<<(Emitter& emitter, const Binary& b) {
  return emitter.Write(b);
}

inline Emitter& operator<<(Emitter& emitter, const char* v) {
  return emitter.Write(v, std::strlen(v));
}

inline Emitter& operator<<(Emitter& emitter, int v) {
  return emitter.WriteIntegralType(v);
}
inline Emitter& operator<<(Emitter& emitter, unsigned int v) {
  return emitter.WriteIntegralType(v);
}
inline Emitter& operator<<(Emitter& emitter, short v) {
  return emitter.WriteIntegralType(v);
}
inline Emitter& operator<<(Emitter& emitter, unsigned short v) {
  return emitter.WriteIntegralType(v);
}
inline Emitter& operator<<(Emitter& emitter, long v) {
  return emitter.WriteIntegralType(v);
}
inline Emitter& operator<<(Emitter& emitter, unsigned long v) {
  return emitter.WriteIntegralType(v);
}
inline Emitter& operator<<(Emitter& emitter, long long v) {
  return emitter.WriteIntegralType(v);
}
inline Emitter& operator<<(Emitter& emitter, unsigned long long v) {
  return emitter.WriteIntegralType(v);
}

inline Emitter& operator<<(Emitter& emitter, float v) {
  return emitter.WriteStreamable(v);
}
inline Emitter& operator<<(Emitter& emitter, double v) {
  return emitter.WriteStreamable(v);
}

inline Emitter& operator<<(Emitter& emitter, EMITTER_MANIP value) {
  return emitter.SetLocalValue(value);
}

inline Emitter& operator<<(Emitter& emitter, _Indent indent) {
  return emitter.SetLocalIndent(indent);
}

inline Emitter& operator<<(Emitter& emitter, _Precision precision) {
  return emitter.SetLocalPrecision(precision);
}
}  // namespace YAML

#endif  // EMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/emitter.h ======

// Expanding include: yaml-cpp/emitterstyle.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/emitterstyle.h ======
#ifndef EMITTERSTYLE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EMITTERSTYLE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

namespace YAML {
namespace EmitterStyle {
enum value { Default, Block, Flow };
}

}

#endif  // EMITTERSTYLE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/emitterstyle.h ======

// Expanding include: yaml-cpp/stlemitter.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/stlemitter.h ======
#ifndef STLEMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define STLEMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <vector>
#include <list>
#include <set>
#include <map>

namespace YAML {
template <typename Seq>
inline Emitter& EmitSeq(Emitter& emitter, const Seq& seq) {
  emitter << BeginSeq;
  for (const auto& v : seq)
    emitter << v;
  emitter << EndSeq;
  return emitter;
}

template <typename T>
inline Emitter& operator<<(Emitter& emitter, const std::vector<T>& v) {
  return EmitSeq(emitter, v);
}

template <typename T>
inline Emitter& operator<<(Emitter& emitter, const std::list<T>& v) {
  return EmitSeq(emitter, v);
}

template <typename T>
inline Emitter& operator<<(Emitter& emitter, const std::set<T>& v) {
  return EmitSeq(emitter, v);
}

template <typename K, typename V>
inline Emitter& operator<<(Emitter& emitter, const std::map<K, V>& m) {
  emitter << BeginMap;
  for (const auto& v : m)
    emitter << Key << v.first << Value << v.second;
  emitter << EndMap;
  return emitter;
}
}

#endif  // STLEMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/stlemitter.h ======

// Expanding include: yaml-cpp/exceptions.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/exceptions.h ======
#ifndef EXCEPTIONS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EXCEPTIONS_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/mark.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/mark.h ======
#ifndef MARK_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define MARK_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/dll.h

namespace YAML {
struct YAML_CPP_API Mark {
  Mark() : pos(0), line(0), column(0) {}

  static const Mark null_mark() { return Mark(-1, -1, -1); }

  bool is_null() const { return pos == -1 && line == -1 && column == -1; }

  int pos;
  int line, column;

 private:
  Mark(int pos_, int line_, int column_)
      : pos(pos_), line(line_), column(column_) {}
};
}

#endif  // MARK_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/mark.h ======

// Expanding include: yaml-cpp/noexcept.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/noexcept.h ======
#ifndef NOEXCEPT_H_768872DA_476C_11EA_88B8_90B11C0C0FF8
#define NOEXCEPT_H_768872DA_476C_11EA_88B8_90B11C0C0FF8

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// This is here for compatibility with older versions of Visual Studio
// which don't support noexcept.
#if defined(_MSC_VER) && _MSC_VER < 1900
    #define YAML_CPP_NOEXCEPT _NOEXCEPT
#else
    #define YAML_CPP_NOEXCEPT noexcept
#endif

#endif
// ====== END yaml-cpp/include/yaml-cpp/noexcept.h ======

// Expanding include: yaml-cpp/traits.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/traits.h ======
#ifndef TRAITS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define TRAITS_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <type_traits>
#include <utility>
#include <string>
#include <sstream>

namespace YAML {
template <typename>
struct is_numeric {
  enum { value = false };
};

template <>
struct is_numeric<char> {
  enum { value = true };
};
template <>
struct is_numeric<unsigned char> {
  enum { value = true };
};
template <>
struct is_numeric<int> {
  enum { value = true };
};
template <>
struct is_numeric<unsigned int> {
  enum { value = true };
};
template <>
struct is_numeric<long int> {
  enum { value = true };
};
template <>
struct is_numeric<unsigned long int> {
  enum { value = true };
};
template <>
struct is_numeric<short int> {
  enum { value = true };
};
template <>
struct is_numeric<unsigned short int> {
  enum { value = true };
};
#if defined(_MSC_VER) && (_MSC_VER < 1310)
template <>
struct is_numeric<__int64> {
  enum { value = true };
};
template <>
struct is_numeric<unsigned __int64> {
  enum { value = true };
};
#else
template <>
struct is_numeric<long long> {
  enum { value = true };
};
template <>
struct is_numeric<unsigned long long> {
  enum { value = true };
};
#endif
template <>
struct is_numeric<float> {
  enum { value = true };
};
template <>
struct is_numeric<double> {
  enum { value = true };
};
template <>
struct is_numeric<long double> {
  enum { value = true };
};

template <bool, class T = void>
struct enable_if_c {
  using type = T;
};

template <class T>
struct enable_if_c<false, T> {};

template <class Cond, class T = void>
struct enable_if : public enable_if_c<Cond::value, T> {};

template <bool, class T = void>
struct disable_if_c {
  using type = T;
};

template <class T>
struct disable_if_c<true, T> {};

template <class Cond, class T = void>
struct disable_if : public disable_if_c<Cond::value, T> {};
}

template <typename S, typename T>
struct is_streamable {
  template <typename StreamT, typename ValueT>
  static auto test(int)
      -> decltype(std::declval<StreamT&>() << std::declval<ValueT>(), std::true_type());

  template <typename, typename>
  static auto test(...) -> std::false_type;

  static const bool value = decltype(test<S, T>(0))::value;
};

template<typename Key, bool Streamable>
struct streamable_to_string {
  static std::string impl(const Key& key) {
    std::stringstream ss;
    ss.imbue(std::locale("C"));
    ss << key;
    return ss.str();
  }
};

template<typename Key>
struct streamable_to_string<Key, false> {
  static std::string impl(const Key&) {
    return "";
  }
};
#endif  // TRAITS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/traits.h ======

#include <sstream>
#include <stdexcept>
#include <string>

namespace YAML {
// error messages
namespace ErrorMsg {
const char* const YAML_DIRECTIVE_ARGS =
    "YAML directives must have exactly one argument";
const char* const YAML_VERSION = "bad YAML version: ";
const char* const YAML_MAJOR_VERSION = "YAML major version too large";
const char* const REPEATED_YAML_DIRECTIVE = "repeated YAML directive";
const char* const TAG_DIRECTIVE_ARGS =
    "TAG directives must have exactly two arguments";
const char* const REPEATED_TAG_DIRECTIVE = "repeated TAG directive";
const char* const CHAR_IN_TAG_HANDLE =
    "illegal character found while scanning tag handle";
const char* const TAG_WITH_NO_SUFFIX = "tag handle with no suffix";
const char* const END_OF_VERBATIM_TAG = "end of verbatim tag not found";
const char* const END_OF_MAP = "end of map not found";
const char* const END_OF_MAP_FLOW = "end of map flow not found";
const char* const END_OF_SEQ = "end of sequence not found";
const char* const END_OF_SEQ_FLOW = "end of sequence flow not found";
const char* const MULTIPLE_TAGS =
    "cannot assign multiple tags to the same node";
const char* const MULTIPLE_ANCHORS =
    "cannot assign multiple anchors to the same node";
const char* const MULTIPLE_ALIASES =
    "cannot assign multiple aliases to the same node";
const char* const ALIAS_CONTENT =
    "aliases can't have any content, *including* tags";
const char* const INVALID_HEX = "bad character found while scanning hex number";
const char* const INVALID_UNICODE = "invalid unicode: ";
const char* const INVALID_ESCAPE = "unknown escape character: ";
const char* const UNKNOWN_TOKEN = "unknown token";
const char* const DOC_IN_SCALAR = "illegal document indicator in scalar";
const char* const EOF_IN_SCALAR = "illegal EOF in scalar";
const char* const CHAR_IN_SCALAR = "illegal character in scalar";
const char* const UNEXPECTED_SCALAR = "unexpected scalar";
const char* const UNEXPECTED_FLOW = "plain value cannot start with flow indicator character";
const char* const TAB_IN_INDENTATION =
    "illegal tab when looking for indentation";
const char* const FLOW_END = "illegal flow end";
const char* const BLOCK_ENTRY = "illegal block entry";
const char* const MAP_KEY = "illegal map key";
const char* const MAP_VALUE = "illegal map value";
const char* const ALIAS_NOT_FOUND = "alias not found after *";
const char* const ANCHOR_NOT_FOUND = "anchor not found after &";
const char* const CHAR_IN_ALIAS =
    "illegal character found while scanning alias";
const char* const CHAR_IN_ANCHOR =
    "illegal character found while scanning anchor";
const char* const ZERO_INDENT_IN_BLOCK =
    "cannot set zero indentation for a block scalar";
const char* const CHAR_IN_BLOCK = "unexpected character in block scalar";
const char* const AMBIGUOUS_ANCHOR =
    "cannot assign the same alias to multiple nodes";
const char* const UNKNOWN_ANCHOR = "the referenced anchor is not defined: ";

const char* const INVALID_NODE =
    "invalid node; this may result from using a map iterator as a sequence "
    "iterator, or vice-versa";
const char* const INVALID_SCALAR = "invalid scalar";
const char* const KEY_NOT_FOUND = "key not found";
const char* const BAD_CONVERSION = "bad conversion";
const char* const BAD_DEREFERENCE = "bad dereference";
const char* const BAD_SUBSCRIPT = "operator[] call on a scalar";
const char* const BAD_PUSHBACK = "appending to a non-sequence";
const char* const BAD_INSERT = "inserting in a non-convertible-to-map";

const char* const UNMATCHED_GROUP_TAG = "unmatched group tag";
const char* const UNEXPECTED_END_SEQ = "unexpected end sequence token";
const char* const UNEXPECTED_END_MAP = "unexpected end map token";
const char* const SINGLE_QUOTED_CHAR =
    "invalid character in single-quoted string";
const char* const INVALID_ANCHOR = "invalid anchor";
const char* const INVALID_ALIAS = "invalid alias";
const char* const INVALID_TAG = "invalid tag";
const char* const BAD_FILE = "bad file";

template <typename T>
inline const std::string KEY_NOT_FOUND_WITH_KEY(
    const T&, typename disable_if<is_numeric<T>>::type* = 0) {
  return KEY_NOT_FOUND;
}

inline const std::string KEY_NOT_FOUND_WITH_KEY(const std::string& key) {
  std::stringstream stream;
  stream << KEY_NOT_FOUND << ": " << key;
  return stream.str();
}

inline const std::string KEY_NOT_FOUND_WITH_KEY(const char* key) {
  std::stringstream stream;
  stream << KEY_NOT_FOUND << ": " << key;
  return stream.str();
}

template <typename T>
inline const std::string KEY_NOT_FOUND_WITH_KEY(
    const T& key, typename enable_if<is_numeric<T>>::type* = 0) {
  std::stringstream stream;
  stream << KEY_NOT_FOUND << ": " << key;
  return stream.str();
}

template <typename T>
inline const std::string BAD_SUBSCRIPT_WITH_KEY(
    const T&, typename disable_if<is_numeric<T>>::type* = nullptr) {
  return BAD_SUBSCRIPT;
}

inline const std::string BAD_SUBSCRIPT_WITH_KEY(const std::string& key) {
  std::stringstream stream;
  stream << BAD_SUBSCRIPT << " (key: \"" << key << "\")";
  return stream.str();
}

inline const std::string BAD_SUBSCRIPT_WITH_KEY(const char* key) {
  std::stringstream stream;
  stream << BAD_SUBSCRIPT << " (key: \"" << key << "\")";
  return stream.str();
}

template <typename T>
inline const std::string BAD_SUBSCRIPT_WITH_KEY(
    const T& key, typename enable_if<is_numeric<T>>::type* = nullptr) {
  std::stringstream stream;
  stream << BAD_SUBSCRIPT << " (key: \"" << key << "\")";
  return stream.str();
}

inline const std::string INVALID_NODE_WITH_KEY(const std::string& key) {
  std::stringstream stream;
  if (key.empty()) {
    return INVALID_NODE;
  }
  stream << "invalid node; first invalid key: \"" << key << "\"";
  return stream.str();
}
}  // namespace ErrorMsg

class YAML_CPP_API Exception : public std::runtime_error {
 public:
  Exception(const Mark& mark_, const std::string& msg_)
      : std::runtime_error(build_what(mark_, msg_)), mark(mark_), msg(msg_) {}
  ~Exception() YAML_CPP_NOEXCEPT override;

  Exception(const Exception&) = default;

  Mark mark;
  std::string msg;

 private:
  static const std::string build_what(const Mark& mark,
                                      const std::string& msg) {
    if (mark.is_null()) {
      return msg;
    }

    std::stringstream output;
    output << "yaml-cpp: error at line " << mark.line + 1 << ", column "
           << mark.column + 1 << ": " << msg;
    return output.str();
  }
};

class YAML_CPP_API ParserException : public Exception {
 public:
  ParserException(const Mark& mark_, const std::string& msg_)
      : Exception(mark_, msg_) {}
  ParserException(const ParserException&) = default;
  ~ParserException() YAML_CPP_NOEXCEPT override;
};

class YAML_CPP_API RepresentationException : public Exception {
 public:
  RepresentationException(const Mark& mark_, const std::string& msg_)
      : Exception(mark_, msg_) {}
  RepresentationException(const RepresentationException&) = default;
  ~RepresentationException() YAML_CPP_NOEXCEPT override;
};

// representation exceptions
class YAML_CPP_API InvalidScalar : public RepresentationException {
 public:
  InvalidScalar(const Mark& mark_)
      : RepresentationException(mark_, ErrorMsg::INVALID_SCALAR) {}
  InvalidScalar(const InvalidScalar&) = default;
  ~InvalidScalar() YAML_CPP_NOEXCEPT override;
};

class YAML_CPP_API KeyNotFound : public RepresentationException {
 public:
  template <typename T>
  KeyNotFound(const Mark& mark_, const T& key_)
      : RepresentationException(mark_, ErrorMsg::KEY_NOT_FOUND_WITH_KEY(key_)) {
  }
  KeyNotFound(const KeyNotFound&) = default;
  ~KeyNotFound() YAML_CPP_NOEXCEPT override;
};

template <typename T>
class YAML_CPP_API TypedKeyNotFound : public KeyNotFound {
 public:
  TypedKeyNotFound(const Mark& mark_, const T& key_)
      : KeyNotFound(mark_, key_), key(key_) {}
  ~TypedKeyNotFound() YAML_CPP_NOEXCEPT override = default;

  T key;
};

template <typename T>
inline TypedKeyNotFound<T> MakeTypedKeyNotFound(const Mark& mark,
                                                const T& key) {
  return TypedKeyNotFound<T>(mark, key);
}

class YAML_CPP_API InvalidNode : public RepresentationException {
 public:
  InvalidNode(const std::string& key)
      : RepresentationException(Mark::null_mark(),
                                ErrorMsg::INVALID_NODE_WITH_KEY(key)) {}
  InvalidNode(const InvalidNode&) = default;
  ~InvalidNode() YAML_CPP_NOEXCEPT override;
};

class YAML_CPP_API BadConversion : public RepresentationException {
 public:
  explicit BadConversion(const Mark& mark_)
      : RepresentationException(mark_, ErrorMsg::BAD_CONVERSION) {}
  BadConversion(const BadConversion&) = default;
  ~BadConversion() YAML_CPP_NOEXCEPT override;
};

template <typename T>
class TypedBadConversion : public BadConversion {
 public:
  explicit TypedBadConversion(const Mark& mark_) : BadConversion(mark_) {}
};

class YAML_CPP_API BadDereference : public RepresentationException {
 public:
  BadDereference()
      : RepresentationException(Mark::null_mark(), ErrorMsg::BAD_DEREFERENCE) {}
  BadDereference(const BadDereference&) = default;
  ~BadDereference() YAML_CPP_NOEXCEPT override;
};

class YAML_CPP_API BadSubscript : public RepresentationException {
 public:
  template <typename Key>
  BadSubscript(const Mark& mark_, const Key& key)
      : RepresentationException(mark_, ErrorMsg::BAD_SUBSCRIPT_WITH_KEY(key)) {}
  BadSubscript(const BadSubscript&) = default;
  ~BadSubscript() YAML_CPP_NOEXCEPT override;
};

class YAML_CPP_API BadPushback : public RepresentationException {
 public:
  BadPushback()
      : RepresentationException(Mark::null_mark(), ErrorMsg::BAD_PUSHBACK) {}
  BadPushback(const BadPushback&) = default;
  ~BadPushback() YAML_CPP_NOEXCEPT override;
};

class YAML_CPP_API BadInsert : public RepresentationException {
 public:
  BadInsert()
      : RepresentationException(Mark::null_mark(), ErrorMsg::BAD_INSERT) {}
  BadInsert(const BadInsert&) = default;
  ~BadInsert() YAML_CPP_NOEXCEPT override;
};

class YAML_CPP_API EmitterException : public Exception {
 public:
  EmitterException(const std::string& msg_)
      : Exception(Mark::null_mark(), msg_) {}
  EmitterException(const EmitterException&) = default;
  ~EmitterException() YAML_CPP_NOEXCEPT override;
};

class YAML_CPP_API BadFile : public Exception {
 public:
  explicit BadFile(const std::string& filename)
      : Exception(Mark::null_mark(),
                  std::string(ErrorMsg::BAD_FILE) + ": " + filename) {}
  BadFile(const BadFile&) = default;
  ~BadFile() YAML_CPP_NOEXCEPT override;
};
}  // namespace YAML

#endif  // EXCEPTIONS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/exceptions.h ======


// Expanding include: yaml-cpp/node/node.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/node.h ======
#ifndef NODE_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <stdexcept>
#include <string>

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/emitterstyle.h
// Expanding include: yaml-cpp/mark.h
// Expanding include: yaml-cpp/node/detail/iterator_fwd.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/iterator_fwd.h ======
#ifndef VALUE_DETAIL_ITERATOR_FWD_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_ITERATOR_FWD_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/dll.h
#include <list>
#include <utility>
#include <vector>

namespace YAML {

namespace detail {
struct iterator_value;
template <typename V>
class iterator_base;
}

using iterator = detail::iterator_base<detail::iterator_value>;
using const_iterator = detail::iterator_base<const detail::iterator_value>;
}

#endif  // VALUE_DETAIL_ITERATOR_FWD_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/detail/iterator_fwd.h ======

// Expanding include: yaml-cpp/node/ptr.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/ptr.h ======
#ifndef VALUE_PTR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_PTR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <memory>

namespace YAML {
namespace detail {
class node;
class node_ref;
class node_data;
class memory;
class memory_holder;

using shared_node = std::shared_ptr<node>;
using shared_node_ref = std::shared_ptr<node_ref>;
using shared_node_data = std::shared_ptr<node_data>;
using shared_memory_holder = std::shared_ptr<memory_holder>;
using shared_memory = std::shared_ptr<memory>;
}
}

#endif  // VALUE_PTR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/ptr.h ======

// Expanding include: yaml-cpp/node/type.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/type.h ======
#ifndef VALUE_TYPE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_TYPE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

namespace YAML {
namespace NodeType {
enum value { Undefined, Null, Scalar, Sequence, Map };
}

}

#endif  // VALUE_TYPE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/type.h ======


namespace YAML {
namespace detail {
class node;
class node_data;
struct iterator_value;
}  // namespace detail
}  // namespace YAML

namespace YAML {
class YAML_CPP_API Node {
 public:
  friend class NodeBuilder;
  friend class NodeEvents;
  friend struct detail::iterator_value;
  friend class detail::node;
  friend class detail::node_data;
  template <typename>
  friend class detail::iterator_base;
  template <typename T, typename S>
  friend struct as_if;

  using iterator = YAML::iterator;
  using const_iterator = YAML::const_iterator;

  Node();
  explicit Node(NodeType::value type);
  template <typename T>
  explicit Node(const T& rhs);
  explicit Node(const detail::iterator_value& rhs);
  Node(const Node& rhs);
  ~Node();

  YAML::Mark Mark() const;
  NodeType::value Type() const;
  bool IsDefined() const;
  bool IsNull() const { return Type() == NodeType::Null; }
  bool IsScalar() const { return Type() == NodeType::Scalar; }
  bool IsSequence() const { return Type() == NodeType::Sequence; }
  bool IsMap() const { return Type() == NodeType::Map; }

  // bool conversions
  explicit operator bool() const { return IsDefined(); }
  bool operator!() const { return !IsDefined(); }

  // access
  template <typename T>
  T as() const;
  template <typename T, typename S>
  T as(const S& fallback) const;
  const std::string& Scalar() const;

  const std::string& Tag() const;
  void SetTag(const std::string& tag);

  // style
  // WARNING: This API might change in future releases.
  EmitterStyle::value Style() const;
  void SetStyle(EmitterStyle::value style);

  // assignment
  bool is(const Node& rhs) const;
  template <typename T>
  Node& operator=(const T& rhs);
  Node& operator=(const Node& rhs);
  void reset(const Node& rhs = Node());

  // size/iterator
  std::size_t size() const;

  const_iterator begin() const;
  iterator begin();

  const_iterator end() const;
  iterator end();

  // sequence
  template <typename T>
  void push_back(const T& rhs);
  void push_back(const Node& rhs);

  // indexing
  template <typename Key>
  const Node operator[](const Key& key) const;
  template <typename Key>
  Node operator[](const Key& key);
  template <typename Key>
  bool remove(const Key& key);

  const Node operator[](const Node& key) const;
  Node operator[](const Node& key);
  bool remove(const Node& key);

  // map
  template <typename Key, typename Value>
  void force_insert(const Key& key, const Value& value);

 private:
  enum Zombie { ZombieNode };
  explicit Node(Zombie);
  explicit Node(Zombie, const std::string&);
  explicit Node(detail::node& node, detail::shared_memory_holder pMemory);

  void EnsureNodeExists() const;

  template <typename T>
  void Assign(const T& rhs);
  void Assign(const char* rhs);
  void Assign(char* rhs);

  void AssignData(const Node& rhs);
  void AssignNode(const Node& rhs);

 private:
  bool m_isValid;
  // String representation of invalid key, if the node is invalid.
  std::string m_invalidKey;
  mutable detail::shared_memory_holder m_pMemory;
  mutable detail::node* m_pNode;
};

YAML_CPP_API bool operator==(const Node& lhs, const Node& rhs);

YAML_CPP_API Node Clone(const Node& node);

template <typename T>
struct convert;
}

#endif  // NODE_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/node.h ======

// Expanding include: yaml-cpp/node/impl.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/impl.h ======
#ifndef NODE_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/exceptions.h
// Expanding include: yaml-cpp/node/detail/memory.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/memory.h ======
#ifndef VALUE_DETAIL_MEMORY_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_MEMORY_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <set>

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/node/ptr.h

namespace YAML {
namespace detail {
class node;
}  // namespace detail
}  // namespace YAML

namespace YAML {
namespace detail {
class YAML_CPP_API memory {
 public:
  memory() : m_nodes{} {}
  node& create_node();
  void merge(const memory& rhs);

 private:
  using Nodes = std::set<shared_node>;
  Nodes m_nodes;
};

class YAML_CPP_API memory_holder {
 public:
  memory_holder() : m_pMemory(new memory) {}

  node& create_node() { return m_pMemory->create_node(); }
  void merge(memory_holder& rhs);

 private:
  shared_memory m_pMemory;
};
}  // namespace detail
}  // namespace YAML

#endif  // VALUE_DETAIL_MEMORY_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/detail/memory.h ======

// Expanding include: yaml-cpp/node/detail/node.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/node.h ======
#ifndef NODE_DETAIL_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_DETAIL_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/emitterstyle.h
// Expanding include: yaml-cpp/node/detail/node_ref.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/node_ref.h ======
#ifndef VALUE_DETAIL_NODE_REF_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_NODE_REF_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/node/type.h
// Expanding include: yaml-cpp/node/ptr.h
// Expanding include: yaml-cpp/node/detail/node_data.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/node_data.h ======
#ifndef VALUE_DETAIL_NODE_DATA_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_NODE_DATA_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/node/detail/node_iterator.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/node_iterator.h ======
#ifndef VALUE_DETAIL_NODE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_NODE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/node/ptr.h
#include <cstddef>
#include <iterator>
#include <memory>
#include <map>
#include <utility>
#include <vector>

namespace YAML {
namespace detail {
struct iterator_type {
  enum value { NoneType, Sequence, Map };
};

template <typename V>
struct node_iterator_value : public std::pair<V*, V*> {
  using kv = std::pair<V*, V*>;

  node_iterator_value() : kv(), pNode(nullptr) {}
  explicit node_iterator_value(V& rhs) : kv(), pNode(&rhs) {}
  explicit node_iterator_value(V& key, V& value) : kv(&key, &value), pNode(nullptr) {}

  V& operator*() const { return *pNode; }
  V& operator->() const { return *pNode; }

  V* pNode;
};

using node_seq = std::vector<node *>;
using node_map = std::vector<std::pair<node*, node*>>;

template <typename V>
struct node_iterator_type {
  using seq = node_seq::iterator;
  using map = node_map::iterator;
};

template <typename V>
struct node_iterator_type<const V> {
  using seq = node_seq::const_iterator;
  using map = node_map::const_iterator;
};

template <typename V>
class node_iterator_base {
 private:
  struct enabler {};

  struct proxy {
    explicit proxy(const node_iterator_value<V>& x) : m_ref(x) {}
    node_iterator_value<V>* operator->() { return std::addressof(m_ref); }
    operator node_iterator_value<V>*() { return std::addressof(m_ref); }

    node_iterator_value<V> m_ref;
  };

 public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = node_iterator_value<V>;
  using difference_type = std::ptrdiff_t;
  using pointer = node_iterator_value<V>*;
  using reference = node_iterator_value<V>&;
  using SeqIter = typename node_iterator_type<V>::seq;
  using MapIter = typename node_iterator_type<V>::map;

  node_iterator_base()
      : m_type(iterator_type::NoneType), m_seqIt(), m_mapIt(), m_mapEnd() {}
  explicit node_iterator_base(SeqIter seqIt)
      : m_type(iterator_type::Sequence),
        m_seqIt(seqIt),
        m_mapIt(),
        m_mapEnd() {}
  explicit node_iterator_base(MapIter mapIt, MapIter mapEnd)
      : m_type(iterator_type::Map),
        m_seqIt(),
        m_mapIt(mapIt),
        m_mapEnd(mapEnd) {
    m_mapIt = increment_until_defined(m_mapIt);
  }

  template <typename W>
  node_iterator_base(const node_iterator_base<W>& rhs,
                     typename std::enable_if<std::is_convertible<W*, V*>::value,
                                             enabler>::type = enabler())
      : m_type(rhs.m_type),
        m_seqIt(rhs.m_seqIt),
        m_mapIt(rhs.m_mapIt),
        m_mapEnd(rhs.m_mapEnd) {}

  template <typename>
  friend class node_iterator_base;

  template <typename W>
  bool operator==(const node_iterator_base<W>& rhs) const {
    if (m_type != rhs.m_type)
      return false;

    switch (m_type) {
      case iterator_type::NoneType:
        return true;
      case iterator_type::Sequence:
        return m_seqIt == rhs.m_seqIt;
      case iterator_type::Map:
        return m_mapIt == rhs.m_mapIt;
    }
    return true;
  }

  template <typename W>
  bool operator!=(const node_iterator_base<W>& rhs) const {
    return !(*this == rhs);
  }

  node_iterator_base<V>& operator++() {
    switch (m_type) {
      case iterator_type::NoneType:
        break;
      case iterator_type::Sequence:
        ++m_seqIt;
        break;
      case iterator_type::Map:
        ++m_mapIt;
        m_mapIt = increment_until_defined(m_mapIt);
        break;
    }
    return *this;
  }

  node_iterator_base<V> operator++(int) {
    node_iterator_base<V> iterator_pre(*this);
    ++(*this);
    return iterator_pre;
  }

  value_type operator*() const {
    switch (m_type) {
      case iterator_type::NoneType:
        return value_type();
      case iterator_type::Sequence:
        return value_type(**m_seqIt);
      case iterator_type::Map:
        return value_type(*m_mapIt->first, *m_mapIt->second);
    }
    return value_type();
  }

  proxy operator->() const { return proxy(**this); }

  MapIter increment_until_defined(MapIter it) {
    while (it != m_mapEnd && !is_defined(it))
      ++it;
    return it;
  }

  bool is_defined(MapIter it) const {
    return it->first->is_defined() && it->second->is_defined();
  }

 private:
  typename iterator_type::value m_type;

  SeqIter m_seqIt;
  MapIter m_mapIt, m_mapEnd;
};

using node_iterator = node_iterator_base<node>;
using const_node_iterator = node_iterator_base<const node>;
}
}

#endif  // VALUE_DETAIL_NODE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/detail/node_iterator.h ======

// Expanding include: yaml-cpp/node/iterator.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/iterator.h ======
#ifndef VALUE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/node/node.h
// Expanding include: yaml-cpp/node/detail/iterator_fwd.h
// Expanding include: yaml-cpp/node/detail/iterator.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/iterator.h ======
#ifndef VALUE_DETAIL_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/dll.h
// Expanding include: yaml-cpp/node/detail/node_iterator.h
// Expanding include: yaml-cpp/node/node.h
// Expanding include: yaml-cpp/node/ptr.h
#include <cstddef>
#include <iterator>


namespace YAML {
namespace detail {
struct iterator_value;

template <typename V>
class iterator_base {

 private:
  template <typename>
  friend class iterator_base;
  struct enabler {};
  using base_type = node_iterator;

  struct proxy {
    explicit proxy(const V& x) : m_ref(x) {}
    V* operator->() { return std::addressof(m_ref); }
    operator V*() { return std::addressof(m_ref); }

    V m_ref;
  };

 public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = V;
  using difference_type = std::ptrdiff_t;
  using pointer = V*;
  using reference = V&;

 public:
  iterator_base() : m_iterator(), m_pMemory() {}
  explicit iterator_base(base_type rhs, shared_memory_holder pMemory)
      : m_iterator(rhs), m_pMemory(pMemory) {}

  template <class W>
  iterator_base(const iterator_base<W>& rhs,
                typename std::enable_if<std::is_convertible<W*, V*>::value,
                                        enabler>::type = enabler())
      : m_iterator(rhs.m_iterator), m_pMemory(rhs.m_pMemory) {}

  iterator_base<V>& operator++() {
    ++m_iterator;
    return *this;
  }

  iterator_base<V> operator++(int) {
    iterator_base<V> iterator_pre(*this);
    ++(*this);
    return iterator_pre;
  }

  template <typename W>
  bool operator==(const iterator_base<W>& rhs) const {
    return m_iterator == rhs.m_iterator;
  }

  template <typename W>
  bool operator!=(const iterator_base<W>& rhs) const {
    return m_iterator != rhs.m_iterator;
  }

  value_type operator*() const {
    const typename base_type::value_type& v = *m_iterator;
    if (v.pNode)
      return value_type(Node(*v, m_pMemory));
    if (v.first && v.second)
      return value_type(Node(*v.first, m_pMemory), Node(*v.second, m_pMemory));
    return value_type();
  }

  proxy operator->() const { return proxy(**this); }

 private:
  base_type m_iterator;
  shared_memory_holder m_pMemory;
};
}  // namespace detail
}  // namespace YAML

#endif  // VALUE_DETAIL_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/detail/iterator.h ======

#include <list>
#include <utility>
#include <vector>

// Assert in place so gcc + libc++ combination properly builds
static_assert(std::is_constructible<YAML::Node, const YAML::Node&>::value, "Node must be copy constructable");

namespace YAML {
namespace detail {
struct iterator_value : public Node, std::pair<Node, Node> {
  iterator_value() = default;
  explicit iterator_value(const Node& rhs)
      : Node(rhs),
        std::pair<Node, Node>(Node(Node::ZombieNode), Node(Node::ZombieNode)) {}
  explicit iterator_value(const Node& key, const Node& value)
      : Node(Node::ZombieNode), std::pair<Node, Node>(key, value) {}
};
}
}

#endif  // VALUE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/iterator.h ======

// Expanding include: yaml-cpp/node/ptr.h
// Expanding include: yaml-cpp/node/type.h

namespace YAML {
namespace detail {
class node;
}  // namespace detail
}  // namespace YAML

namespace YAML {
namespace detail {
class YAML_CPP_API node_data {
 public:
  node_data();
  node_data(const node_data&) = delete;
  node_data& operator=(const node_data&) = delete;

  void mark_defined();
  void set_mark(const Mark& mark);
  void set_type(NodeType::value type);
  void set_tag(const std::string& tag);
  void set_null();
  void set_scalar(const std::string& scalar);
  void set_style(EmitterStyle::value style);

  bool is_defined() const { return m_isDefined; }
  const Mark& mark() const { return m_mark; }
  NodeType::value type() const {
    return m_isDefined ? m_type : NodeType::Undefined;
  }
  const std::string& scalar() const { return m_scalar; }
  const std::string& tag() const { return m_tag; }
  EmitterStyle::value style() const { return m_style; }

  // size/iterator
  std::size_t size() const;

  const_node_iterator begin() const;
  node_iterator begin();

  const_node_iterator end() const;
  node_iterator end();

  // sequence
  void push_back(node& node, const shared_memory_holder& pMemory);
  void insert(node& key, node& value, const shared_memory_holder& pMemory);

  // indexing
  template <typename Key>
  node* get(const Key& key, shared_memory_holder pMemory) const;
  template <typename Key>
  node& get(const Key& key, shared_memory_holder pMemory);
  template <typename Key>
  bool remove(const Key& key, shared_memory_holder pMemory);

  node* get(node& key, const shared_memory_holder& pMemory) const;
  node& get(node& key, const shared_memory_holder& pMemory);
  bool remove(node& key, const shared_memory_holder& pMemory);

  // map
  template <typename Key, typename Value>
  void force_insert(const Key& key, const Value& value,
                    shared_memory_holder pMemory);

 public:
  static const std::string& empty_scalar();

 private:
  void compute_seq_size() const;
  void compute_map_size() const;

  void reset_sequence();
  void reset_map();

  void insert_map_pair(node& key, node& value);
  void convert_to_map(const shared_memory_holder& pMemory);
  void convert_sequence_to_map(const shared_memory_holder& pMemory);

  template <typename T>
  static node& convert_to_node(const T& rhs, shared_memory_holder pMemory);

 private:
  bool m_isDefined;
  Mark m_mark;
  NodeType::value m_type;
  std::string m_tag;
  EmitterStyle::value m_style;

  // scalar
  std::string m_scalar;

  // sequence
  using node_seq = std::vector<node *>;
  node_seq m_sequence;

  mutable std::size_t m_seqSize;

  // map
  using node_map = std::vector<std::pair<node*, node*>>;
  node_map m_map;

  using kv_pair = std::pair<node*, node*>;
  using kv_pairs = std::list<kv_pair>;
  mutable kv_pairs m_undefinedPairs;
};
}
}

#endif  // VALUE_DETAIL_NODE_DATA_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/detail/node_data.h ======


namespace YAML {
namespace detail {
class node_ref {
 public:
  node_ref() : m_pData(new node_data) {}
  node_ref(const node_ref&) = delete;
  node_ref& operator=(const node_ref&) = delete;

  bool is_defined() const { return m_pData->is_defined(); }
  const Mark& mark() const { return m_pData->mark(); }
  NodeType::value type() const { return m_pData->type(); }
  const std::string& scalar() const { return m_pData->scalar(); }
  const std::string& tag() const { return m_pData->tag(); }
  EmitterStyle::value style() const { return m_pData->style(); }

  void mark_defined() { m_pData->mark_defined(); }
  void set_data(const node_ref& rhs) { m_pData = rhs.m_pData; }

  void set_mark(const Mark& mark) { m_pData->set_mark(mark); }
  void set_type(NodeType::value type) { m_pData->set_type(type); }
  void set_tag(const std::string& tag) { m_pData->set_tag(tag); }
  void set_null() { m_pData->set_null(); }
  void set_scalar(const std::string& scalar) { m_pData->set_scalar(scalar); }
  void set_style(EmitterStyle::value style) { m_pData->set_style(style); }

  // size/iterator
  std::size_t size() const { return m_pData->size(); }

  const_node_iterator begin() const {
    return static_cast<const node_data&>(*m_pData).begin();
  }
  node_iterator begin() { return m_pData->begin(); }

  const_node_iterator end() const {
    return static_cast<const node_data&>(*m_pData).end();
  }
  node_iterator end() { return m_pData->end(); }

  // sequence
  void push_back(node& node, shared_memory_holder pMemory) {
    m_pData->push_back(node, pMemory);
  }
  void insert(node& key, node& value, shared_memory_holder pMemory) {
    m_pData->insert(key, value, pMemory);
  }

  // indexing
  template <typename Key>
  node* get(const Key& key, shared_memory_holder pMemory) const {
    return static_cast<const node_data&>(*m_pData).get(key, pMemory);
  }
  template <typename Key>
  node& get(const Key& key, shared_memory_holder pMemory) {
    return m_pData->get(key, pMemory);
  }
  template <typename Key>
  bool remove(const Key& key, shared_memory_holder pMemory) {
    return m_pData->remove(key, pMemory);
  }

  node* get(node& key, shared_memory_holder pMemory) const {
    return static_cast<const node_data&>(*m_pData).get(key, pMemory);
  }
  node& get(node& key, shared_memory_holder pMemory) {
    return m_pData->get(key, pMemory);
  }
  bool remove(node& key, shared_memory_holder pMemory) {
    return m_pData->remove(key, pMemory);
  }

  // map
  template <typename Key, typename Value>
  void force_insert(const Key& key, const Value& value,
                    shared_memory_holder pMemory) {
    m_pData->force_insert(key, value, pMemory);
  }

 private:
  shared_node_data m_pData;
};
}
}

#endif  // VALUE_DETAIL_NODE_REF_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/detail/node_ref.h ======

// Expanding include: yaml-cpp/node/ptr.h
// Expanding include: yaml-cpp/node/type.h
#include <set>
#include <atomic>

namespace YAML {
namespace detail {
class node {
 private:
  struct less {
    bool operator ()(const node* l, const node* r) const {return l->m_index < r->m_index;}
  };

 public:
  node() : m_pRef(new node_ref), m_dependencies{}, m_index{} {}
  node(const node&) = delete;
  node& operator=(const node&) = delete;

  bool is(const node& rhs) const { return m_pRef == rhs.m_pRef; }
  const node_ref* ref() const { return m_pRef.get(); }

  bool is_defined() const { return m_pRef->is_defined(); }
  const Mark& mark() const { return m_pRef->mark(); }
  NodeType::value type() const { return m_pRef->type(); }

  const std::string& scalar() const { return m_pRef->scalar(); }
  const std::string& tag() const { return m_pRef->tag(); }
  EmitterStyle::value style() const { return m_pRef->style(); }

  template <typename T>
  bool equals(const T& rhs, shared_memory_holder pMemory);
  bool equals(const char* rhs, shared_memory_holder pMemory);

  void mark_defined() {
    if (is_defined())
      return;

    m_pRef->mark_defined();
    for (node* dependency : m_dependencies)
      dependency->mark_defined();
    m_dependencies.clear();
  }

  void add_dependency(node& rhs) {
    if (is_defined())
      rhs.mark_defined();
    else
      m_dependencies.insert(&rhs);
  }

  void set_ref(const node& rhs) {
    if (rhs.is_defined())
      mark_defined();
    m_pRef = rhs.m_pRef;
  }
  void set_data(const node& rhs) {
    if (rhs.is_defined())
      mark_defined();
    m_pRef->set_data(*rhs.m_pRef);
  }

  void set_mark(const Mark& mark) { m_pRef->set_mark(mark); }

  void set_type(NodeType::value type) {
    if (type != NodeType::Undefined)
      mark_defined();
    m_pRef->set_type(type);
  }
  void set_null() {
    mark_defined();
    m_pRef->set_null();
  }
  void set_scalar(const std::string& scalar) {
    mark_defined();
    m_pRef->set_scalar(scalar);
  }
  void set_tag(const std::string& tag) {
    mark_defined();
    m_pRef->set_tag(tag);
  }

  // style
  void set_style(EmitterStyle::value style) {
    mark_defined();
    m_pRef->set_style(style);
  }

  // size/iterator
  std::size_t size() const { return m_pRef->size(); }

  const_node_iterator begin() const {
    return static_cast<const node_ref&>(*m_pRef).begin();
  }
  node_iterator begin() { return m_pRef->begin(); }

  const_node_iterator end() const {
    return static_cast<const node_ref&>(*m_pRef).end();
  }
  node_iterator end() { return m_pRef->end(); }

  // sequence
  void push_back(node& input, shared_memory_holder pMemory) {
    m_pRef->push_back(input, pMemory);
    input.add_dependency(*this);
    m_index = m_amount.fetch_add(1);
  }
  void insert(node& key, node& value, shared_memory_holder pMemory) {
    m_pRef->insert(key, value, pMemory);
    key.add_dependency(*this);
    value.add_dependency(*this);
  }

  // indexing
  template <typename Key>
  node* get(const Key& key, shared_memory_holder pMemory) const {
    // NOTE: this returns a non-const node so that the top-level Node can wrap
    // it, and returns a pointer so that it can be nullptr (if there is no such
    // key).
    return static_cast<const node_ref&>(*m_pRef).get(key, pMemory);
  }
  template <typename Key>
  node& get(const Key& key, shared_memory_holder pMemory) {
    node& value = m_pRef->get(key, pMemory);
    value.add_dependency(*this);
    return value;
  }
  template <typename Key>
  bool remove(const Key& key, shared_memory_holder pMemory) {
    return m_pRef->remove(key, pMemory);
  }

  node* get(node& key, shared_memory_holder pMemory) const {
    // NOTE: this returns a non-const node so that the top-level Node can wrap
    // it, and returns a pointer so that it can be nullptr (if there is no such
    // key).
    return static_cast<const node_ref&>(*m_pRef).get(key, pMemory);
  }
  node& get(node& key, shared_memory_holder pMemory) {
    node& value = m_pRef->get(key, pMemory);
    key.add_dependency(*this);
    value.add_dependency(*this);
    return value;
  }
  bool remove(node& key, shared_memory_holder pMemory) {
    return m_pRef->remove(key, pMemory);
  }

  // map
  template <typename Key, typename Value>
  void force_insert(const Key& key, const Value& value,
                    shared_memory_holder pMemory) {
    m_pRef->force_insert(key, value, pMemory);
  }

 private:
  shared_node_ref m_pRef;
  using nodes = std::set<node*, less>;
  nodes m_dependencies;
  size_t m_index;
  static YAML_CPP_API std::atomic<size_t> m_amount;
};
}  // namespace detail
}  // namespace YAML

#endif  // NODE_DETAIL_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/detail/node.h ======

// Expanding include: yaml-cpp/node/iterator.h
// Expanding include: yaml-cpp/node/node.h
#include <sstream>
#include <string>

namespace YAML {
inline Node::Node()
    : m_isValid(true), m_invalidKey{}, m_pMemory(nullptr), m_pNode(nullptr) {}

inline Node::Node(NodeType::value type)
    : m_isValid(true),
      m_invalidKey{},
      m_pMemory(new detail::memory_holder),
      m_pNode(&m_pMemory->create_node()) {
  m_pNode->set_type(type);
}

template <typename T>
inline Node::Node(const T& rhs)
    : m_isValid(true),
      m_invalidKey{},
      m_pMemory(new detail::memory_holder),
      m_pNode(&m_pMemory->create_node()) {
  Assign(rhs);
}

inline Node::Node(const detail::iterator_value& rhs)
    : m_isValid(rhs.m_isValid),
      m_invalidKey(rhs.m_invalidKey),
      m_pMemory(rhs.m_pMemory),
      m_pNode(rhs.m_pNode) {}

inline Node::Node(const Node&) = default;

inline Node::Node(Zombie)
    : m_isValid(false), m_invalidKey{}, m_pMemory{}, m_pNode(nullptr) {}

inline Node::Node(Zombie, const std::string& key)
    : m_isValid(false), m_invalidKey(key), m_pMemory{}, m_pNode(nullptr) {}

inline Node::Node(detail::node& node, detail::shared_memory_holder pMemory)
    : m_isValid(true), m_invalidKey{}, m_pMemory(pMemory), m_pNode(&node) {}

inline Node::~Node() = default;

inline void Node::EnsureNodeExists() const {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  if (!m_pNode) {
    m_pMemory.reset(new detail::memory_holder);
    m_pNode = &m_pMemory->create_node();
    m_pNode->set_null();
  }
}

inline bool Node::IsDefined() const {
  if (!m_isValid) {
    return false;
  }
  return m_pNode ? m_pNode->is_defined() : true;
}

inline Mark Node::Mark() const {
  if (!m_isValid) {
    throw InvalidNode(m_invalidKey);
  }
  return m_pNode ? m_pNode->mark() : Mark::null_mark();
}

inline NodeType::value Node::Type() const {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  return m_pNode ? m_pNode->type() : NodeType::Null;
}

// access

// template helpers
template <typename T, typename S>
struct as_if {
  explicit as_if(const Node& node_) : node(node_) {}
  const Node& node;

  T operator()(const S& fallback) const {
    if (!node.m_pNode)
      return fallback;

    T t = fallback;
    if (convert<T>::decode(node, t))
      return t;
    return fallback;
  }
};

template <typename S>
struct as_if<std::string, S> {
  explicit as_if(const Node& node_) : node(node_) {}
  const Node& node;

  std::string operator()(const S& fallback) const {
    if (node.Type() == NodeType::Null)
      return "null";
    if (node.Type() != NodeType::Scalar)
      return fallback;
    return node.Scalar();
  }
};

template <typename T>
struct as_if<T, void> {
  explicit as_if(const Node& node_) : node(node_) {}
  const Node& node;

  T operator()() const {
    if (!node.m_pNode) // no fallback
      throw InvalidNode(node.m_invalidKey);

    T t;
    if (convert<T>::decode(node, t))
      return t;
    throw TypedBadConversion<T>(node.Mark());
  }
};

template <>
struct as_if<std::string, void> {
  explicit as_if(const Node& node_) : node(node_) {}
  const Node& node;

  std::string operator()() const {
    if (node.Type() == NodeType::Undefined) // no fallback
      throw InvalidNode(node.m_invalidKey);
    if (node.Type() == NodeType::Null)
      return "null";
    if (node.Type() != NodeType::Scalar)
      throw TypedBadConversion<std::string>(node.Mark());
    return node.Scalar();
  }
};

// access functions
template <typename T>
inline T Node::as() const {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  return as_if<T, void>(*this)();
}

template <typename T, typename S>
inline T Node::as(const S& fallback) const {
  if (!m_isValid)
    return fallback;
  return as_if<T, S>(*this)(fallback);
}

inline const std::string& Node::Scalar() const {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  return m_pNode ? m_pNode->scalar() : detail::node_data::empty_scalar();
}

inline const std::string& Node::Tag() const {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  return m_pNode ? m_pNode->tag() : detail::node_data::empty_scalar();
}

inline void Node::SetTag(const std::string& tag) {
  EnsureNodeExists();
  m_pNode->set_tag(tag);
}

inline EmitterStyle::value Node::Style() const {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  return m_pNode ? m_pNode->style() : EmitterStyle::Default;
}

inline void Node::SetStyle(EmitterStyle::value style) {
  EnsureNodeExists();
  m_pNode->set_style(style);
}

// assignment
inline bool Node::is(const Node& rhs) const {
  if (!m_isValid || !rhs.m_isValid)
    throw InvalidNode(m_invalidKey);
  if (!m_pNode || !rhs.m_pNode)
    return false;
  return m_pNode->is(*rhs.m_pNode);
}

template <typename T>
inline Node& Node::operator=(const T& rhs) {
  Assign(rhs);
  return *this;
}

inline Node& Node::operator=(const Node& rhs) {
  if (is(rhs))
    return *this;
  AssignNode(rhs);
  return *this;
}

inline void Node::reset(const YAML::Node& rhs) {
  if (!m_isValid || !rhs.m_isValid)
    throw InvalidNode(m_invalidKey);
  m_pMemory = rhs.m_pMemory;
  m_pNode = rhs.m_pNode;
}

template <typename T>
inline void Node::Assign(const T& rhs) {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  AssignData(convert<T>::encode(rhs));
}

template <>
inline void Node::Assign(const std::string& rhs) {
  EnsureNodeExists();
  m_pNode->set_scalar(rhs);
}

inline void Node::Assign(const char* rhs) {
  EnsureNodeExists();
  m_pNode->set_scalar(rhs);
}

inline void Node::Assign(char* rhs) {
  EnsureNodeExists();
  m_pNode->set_scalar(rhs);
}

inline void Node::AssignData(const Node& rhs) {
  EnsureNodeExists();
  rhs.EnsureNodeExists();

  m_pNode->set_data(*rhs.m_pNode);
  m_pMemory->merge(*rhs.m_pMemory);
}

inline void Node::AssignNode(const Node& rhs) {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  rhs.EnsureNodeExists();

  if (!m_pNode) {
    m_pNode = rhs.m_pNode;
    m_pMemory = rhs.m_pMemory;
    return;
  }

  m_pNode->set_ref(*rhs.m_pNode);
  m_pMemory->merge(*rhs.m_pMemory);
  m_pNode = rhs.m_pNode;
}

// size/iterator
inline std::size_t Node::size() const {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  return m_pNode ? m_pNode->size() : 0;
}

inline const_iterator Node::begin() const {
  if (!m_isValid)
    return const_iterator();
  return m_pNode ? const_iterator(m_pNode->begin(), m_pMemory)
                 : const_iterator();
}

inline iterator Node::begin() {
  if (!m_isValid)
    return iterator();
  return m_pNode ? iterator(m_pNode->begin(), m_pMemory) : iterator();
}

inline const_iterator Node::end() const {
  if (!m_isValid)
    return const_iterator();
  return m_pNode ? const_iterator(m_pNode->end(), m_pMemory) : const_iterator();
}

inline iterator Node::end() {
  if (!m_isValid)
    return iterator();
  return m_pNode ? iterator(m_pNode->end(), m_pMemory) : iterator();
}

// sequence
template <typename T>
inline void Node::push_back(const T& rhs) {
  if (!m_isValid)
    throw InvalidNode(m_invalidKey);
  push_back(Node(rhs));
}

inline void Node::push_back(const Node& rhs) {
  EnsureNodeExists();
  rhs.EnsureNodeExists();

  m_pNode->push_back(*rhs.m_pNode, m_pMemory);
  m_pMemory->merge(*rhs.m_pMemory);
}

template<typename Key>
std::string key_to_string(const Key& key) {
  return streamable_to_string<Key, is_streamable<std::stringstream, Key>::value>().impl(key);
}

// indexing
template <typename Key>
inline const Node Node::operator[](const Key& key) const {
  EnsureNodeExists();
  detail::node* value =
      static_cast<const detail::node&>(*m_pNode).get(key, m_pMemory);
  if (!value) {
    return Node(ZombieNode, key_to_string(key));
  }
  return Node(*value, m_pMemory);
}

template <typename Key>
inline Node Node::operator[](const Key& key) {
  EnsureNodeExists();
  detail::node& value = m_pNode->get(key, m_pMemory);
  return Node(value, m_pMemory);
}

template <typename Key>
inline bool Node::remove(const Key& key) {
  EnsureNodeExists();
  return m_pNode->remove(key, m_pMemory);
}

inline const Node Node::operator[](const Node& key) const {
  EnsureNodeExists();
  key.EnsureNodeExists();
  m_pMemory->merge(*key.m_pMemory);
  detail::node* value =
      static_cast<const detail::node&>(*m_pNode).get(*key.m_pNode, m_pMemory);
  if (!value) {
    return Node(ZombieNode, key_to_string(key));
  }
  return Node(*value, m_pMemory);
}

inline Node Node::operator[](const Node& key) {
  EnsureNodeExists();
  key.EnsureNodeExists();
  m_pMemory->merge(*key.m_pMemory);
  detail::node& value = m_pNode->get(*key.m_pNode, m_pMemory);
  return Node(value, m_pMemory);
}

inline bool Node::remove(const Node& key) {
  EnsureNodeExists();
  key.EnsureNodeExists();
  return m_pNode->remove(*key.m_pNode, m_pMemory);
}

// map
template <typename Key, typename Value>
inline void Node::force_insert(const Key& key, const Value& value) {
  EnsureNodeExists();
  m_pNode->force_insert(key, value, m_pMemory);
}

// free functions
inline bool operator==(const Node& lhs, const Node& rhs) { return lhs.is(rhs); }
}  // namespace YAML

#endif  // NODE_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/impl.h ======

// Expanding include: yaml-cpp/node/convert.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/convert.h ======
#ifndef NODE_CONVERT_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_CONVERT_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <array>
#include <cmath>
#include <limits>
#include <list>
#include <map>
#include <unordered_map>
#include <sstream>
#include <type_traits>
#include <valarray>
#include <vector>

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#include <string_view>
#endif

// Expanding include: yaml-cpp/binary.h
// Expanding include: yaml-cpp/node/impl.h
// Expanding include: yaml-cpp/node/iterator.h
// Expanding include: yaml-cpp/node/node.h
// Expanding include: yaml-cpp/node/type.h
// Expanding include: yaml-cpp/null.h
// Expanding include: yaml-cpp/fptostring.h


namespace YAML {
class Binary;
struct _Null;
template <typename T>
struct convert;
}  // namespace YAML

namespace YAML {
namespace conversion {
inline bool IsInfinity(const std::string& input) {
  return input == ".inf" || input == ".Inf" || input == ".INF" ||
         input == "+.inf" || input == "+.Inf" || input == "+.INF";
}

inline bool IsNegativeInfinity(const std::string& input) {
  return input == "-.inf" || input == "-.Inf" || input == "-.INF";
}

inline bool IsNaN(const std::string& input) {
  return input == ".nan" || input == ".NaN" || input == ".NAN";
}
}

// Node
template <>
struct convert<Node> {
  static Node encode(const Node& rhs) { return rhs; }

  static bool decode(const Node& node, Node& rhs) {
    rhs.reset(node);
    return true;
  }
};

// std::string
template <>
struct convert<std::string> {
  static Node encode(const std::string& rhs) { return Node(rhs); }

  static bool decode(const Node& node, std::string& rhs) {
    if (!node.IsScalar())
      return false;
    rhs = node.Scalar();
    return true;
  }
};

// C-strings can only be encoded
template <>
struct convert<const char*> {
  static Node encode(const char* rhs) { return Node(rhs); }
};

template <>
struct convert<char*> {
  static Node encode(const char* rhs) { return Node(rhs); }
};

template <std::size_t N>
struct convert<char[N]> {
  static Node encode(const char* rhs) { return Node(rhs); }
};

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
template <>
struct convert<std::string_view> {
  static Node encode(std::string_view rhs) { return Node(std::string(rhs)); }

  static bool decode(const Node& node, std::string_view& rhs) {
    if (!node.IsScalar())
      return false;
    rhs = node.Scalar();
    return true;
  }
};
#endif

template <>
struct convert<_Null> {
  static Node encode(const _Null& /* rhs */) { return Node(); }

  static bool decode(const Node& node, _Null& /* rhs */) {
    return node.IsNull();
  }
};

namespace conversion {
template <typename T>
typename std::enable_if< std::is_floating_point<T>::value, void>::type
inner_encode(const T& rhs, std::stringstream& stream){
  if (std::isnan(rhs)) {
    stream << ".nan";
  } else if (std::isinf(rhs)) {
    if (std::signbit(rhs)) {
      stream << "-.inf";
    } else {
      stream << ".inf";
    }
  } else {
    stream << FpToString(rhs, stream.precision());
  }
}

template <typename T>
typename std::enable_if<!std::is_floating_point<T>::value, void>::type
inner_encode(const T& rhs, std::stringstream& stream){
  stream << rhs;
}

template <typename T>
typename std::enable_if<(std::is_same<T, unsigned char>::value ||
                         std::is_same<T, signed char>::value), bool>::type
ConvertStreamTo(std::stringstream& stream, T& rhs) {
  int num;
  if ((stream >> std::noskipws >> num) && (stream >> std::ws).eof()) {
    if (num >= (std::numeric_limits<T>::min)() &&
        num <= (std::numeric_limits<T>::max)()) {
      rhs = static_cast<T>(num);
      return true;
    }
  }
  return false;
}

template <typename T>
typename std::enable_if<!(std::is_same<T, unsigned char>::value ||
                          std::is_same<T, signed char>::value), bool>::type
ConvertStreamTo(std::stringstream& stream, T& rhs) {
  if ((stream >> std::noskipws >> rhs) && (stream >> std::ws).eof()) {
    return true;
  }
  return false;
}
}

#define YAML_DEFINE_CONVERT_STREAMABLE(type, negative_op)                  \
  template <>                                                              \
  struct convert<type> {                                                   \
                                                                           \
    static Node encode(const type& rhs) {                                  \
      std::stringstream stream;                                            \
      stream.imbue(std::locale("C"));                                       \
      stream.precision(std::numeric_limits<type>::max_digits10);           \
      conversion::inner_encode(rhs, stream);                               \
      return Node(stream.str());                                           \
    }                                                                      \
                                                                           \
    static bool decode(const Node& node, type& rhs) {                      \
      if (node.Type() != NodeType::Scalar) {                               \
        return false;                                                      \
      }                                                                    \
      const std::string& input = node.Scalar();                            \
      std::stringstream stream(input);                                     \
      stream.imbue(std::locale("C"));                                       \
      stream.unsetf(std::ios::dec);                                        \
      if ((stream.peek() == '-') && std::is_unsigned<type>::value) {       \
        return false;                                                      \
      }                                                                    \
      if (conversion::ConvertStreamTo(stream, rhs)) {                      \
        return true;                                                       \
      }                                                                    \
      if (std::numeric_limits<type>::has_infinity) {                       \
        if (conversion::IsInfinity(input)) {                               \
          rhs = std::numeric_limits<type>::infinity();                     \
          return true;                                                     \
        } else if (conversion::IsNegativeInfinity(input)) {                \
          rhs = negative_op std::numeric_limits<type>::infinity();         \
          return true;                                                     \
        }                                                                  \
      }                                                                    \
                                                                           \
      if (std::numeric_limits<type>::has_quiet_NaN) {                      \
        if (conversion::IsNaN(input)) {                                    \
          rhs = std::numeric_limits<type>::quiet_NaN();                    \
          return true;                                                     \
        }                                                                  \
      }                                                                    \
                                                                           \
      return false;                                                        \
    }                                                                      \
  }

#define YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(type) \
  YAML_DEFINE_CONVERT_STREAMABLE(type, -)

#define YAML_DEFINE_CONVERT_STREAMABLE_UNSIGNED(type) \
  YAML_DEFINE_CONVERT_STREAMABLE(type, +)

YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(int);
YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(short);
YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(long);
YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(long long);
YAML_DEFINE_CONVERT_STREAMABLE_UNSIGNED(unsigned);
YAML_DEFINE_CONVERT_STREAMABLE_UNSIGNED(unsigned short);
YAML_DEFINE_CONVERT_STREAMABLE_UNSIGNED(unsigned long);
YAML_DEFINE_CONVERT_STREAMABLE_UNSIGNED(unsigned long long);

YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(char);
YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(signed char);
YAML_DEFINE_CONVERT_STREAMABLE_UNSIGNED(unsigned char);

YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(float);
YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(double);
YAML_DEFINE_CONVERT_STREAMABLE_SIGNED(long double);

#undef YAML_DEFINE_CONVERT_STREAMABLE_SIGNED
#undef YAML_DEFINE_CONVERT_STREAMABLE_UNSIGNED
#undef YAML_DEFINE_CONVERT_STREAMABLE

// bool
template <>
struct convert<bool> {
  static Node encode(bool rhs) { return rhs ? Node("true") : Node("false"); }

  YAML_CPP_API static bool decode(const Node& node, bool& rhs);
};

// std::map
template <typename K, typename V, typename C, typename A>
struct convert<std::map<K, V, C, A>> {
  static Node encode(const std::map<K, V, C, A>& rhs) {
    Node node(NodeType::Map);
    for (const auto& element : rhs)
      node.force_insert(element.first, element.second);
    return node;
  }

  static bool decode(const Node& node, std::map<K, V, C, A>& rhs) {
    if (!node.IsMap())
      return false;

    rhs.clear();
    for (const auto& element : node)
#if defined(__GNUC__) && __GNUC__ < 4
      // workaround for GCC 3:
      rhs[element.first.template as<K>()] = element.second.template as<V>();
#else
      rhs[element.first.as<K>()] = element.second.as<V>();
#endif
    return true;
  }
};

// std::unordered_map
template <typename K, typename V, typename H, typename P, typename A>
struct convert<std::unordered_map<K, V, H, P, A>> {
  static Node encode(const std::unordered_map<K, V, H, P, A>& rhs) {
    Node node(NodeType::Map);
    for (const auto& element : rhs)
      node.force_insert(element.first, element.second);
    return node;
  }

  static bool decode(const Node& node, std::unordered_map<K, V, H, P, A>& rhs) {
    if (!node.IsMap())
      return false;

    rhs.clear();
    for (const auto& element : node)
#if defined(__GNUC__) && __GNUC__ < 4
      // workaround for GCC 3:
      rhs[element.first.template as<K>()] = element.second.template as<V>();
#else
      rhs[element.first.as<K>()] = element.second.as<V>();
#endif
    return true;
  }
};

// std::vector
template <typename T, typename A>
struct convert<std::vector<T, A>> {
  static Node encode(const std::vector<T, A>& rhs) {
    Node node(NodeType::Sequence);
    for (const auto& element : rhs)
      node.push_back(element);
    return node;
  }

  static bool decode(const Node& node, std::vector<T, A>& rhs) {
    if (!node.IsSequence())
      return false;

    rhs.clear();
    for (const auto& element : node)
#if defined(__GNUC__) && __GNUC__ < 4
      // workaround for GCC 3:
      rhs.push_back(element.template as<T>());
#else
      rhs.push_back(element.as<T>());
#endif
    return true;
  }
};

// std::list
template <typename T, typename A>
struct convert<std::list<T,A>> {
  static Node encode(const std::list<T,A>& rhs) {
    Node node(NodeType::Sequence);
    for (const auto& element : rhs)
      node.push_back(element);
    return node;
  }

  static bool decode(const Node& node, std::list<T,A>& rhs) {
    if (!node.IsSequence())
      return false;

    rhs.clear();
    for (const auto& element : node)
#if defined(__GNUC__) && __GNUC__ < 4
      // workaround for GCC 3:
      rhs.push_back(element.template as<T>());
#else
      rhs.push_back(element.as<T>());
#endif
    return true;
  }
};

// std::array
template <typename T, std::size_t N>
struct convert<std::array<T, N>> {
  static Node encode(const std::array<T, N>& rhs) {
    Node node(NodeType::Sequence);
    for (const auto& element : rhs) {
      node.push_back(element);
    }
    return node;
  }

  static bool decode(const Node& node, std::array<T, N>& rhs) {
    if (!isNodeValid(node)) {
      return false;
    }

    for (auto i = 0u; i < node.size(); ++i) {
#if defined(__GNUC__) && __GNUC__ < 4
      // workaround for GCC 3:
      rhs[i] = node[i].template as<T>();
#else
      rhs[i] = node[i].as<T>();
#endif
    }
    return true;
  }

 private:
  static bool isNodeValid(const Node& node) {
    return node.IsSequence() && node.size() == N;
  }
};


// std::valarray
template <typename T>
struct convert<std::valarray<T>> {
  static Node encode(const std::valarray<T>& rhs) {
    Node node(NodeType::Sequence);
    for (const auto& element : rhs) {
      node.push_back(element);
    }
    return node;
  }

  static bool decode(const Node& node, std::valarray<T>& rhs) {
    if (!node.IsSequence()) {
      return false;
    }

    rhs.resize(node.size());
    for (auto i = 0u; i < node.size(); ++i) {
#if defined(__GNUC__) && __GNUC__ < 4
      // workaround for GCC 3:
      rhs[i] = node[i].template as<T>();
#else
      rhs[i] = node[i].as<T>();
#endif
    }
    return true;
  }
};


// std::pair
template <typename T, typename U>
struct convert<std::pair<T, U>> {
  static Node encode(const std::pair<T, U>& rhs) {
    Node node(NodeType::Sequence);
    node.push_back(rhs.first);
    node.push_back(rhs.second);
    return node;
  }

  static bool decode(const Node& node, std::pair<T, U>& rhs) {
    if (!node.IsSequence())
      return false;
    if (node.size() != 2)
      return false;

#if defined(__GNUC__) && __GNUC__ < 4
    // workaround for GCC 3:
    rhs.first = node[0].template as<T>();
#else
    rhs.first = node[0].as<T>();
#endif
#if defined(__GNUC__) && __GNUC__ < 4
    // workaround for GCC 3:
    rhs.second = node[1].template as<U>();
#else
    rhs.second = node[1].as<U>();
#endif
    return true;
  }
};

// binary
template <>
struct convert<Binary> {
  static Node encode(const Binary& rhs) {
    return Node(EncodeBase64(rhs.data(), rhs.size()));
  }

  static bool decode(const Node& node, Binary& rhs) {
    if (!node.IsScalar())
      return false;

    std::vector<unsigned char> data = DecodeBase64(node.Scalar());
    if (data.empty() && !node.Scalar().empty())
      return false;

    rhs.swap(data);
    return true;
  }
};
}

#endif  // NODE_CONVERT_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/convert.h ======

// Expanding include: yaml-cpp/node/iterator.h
// Expanding include: yaml-cpp/node/detail/impl.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/impl.h ======
#ifndef NODE_DETAIL_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_DETAIL_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/node/detail/node.h
// Expanding include: yaml-cpp/node/detail/node_data.h

#include <algorithm>
#include <type_traits>

namespace YAML {
namespace detail {
template <typename Key, typename Enable = void>
struct get_idx {
  static node* get(const std::vector<node*>& /* sequence */,
                   const Key& /* key */, shared_memory_holder /* pMemory */) {
    return nullptr;
  }
};

template <typename Key>
struct get_idx<Key,
               typename std::enable_if<std::is_unsigned<Key>::value &&
                                       !std::is_same<Key, bool>::value>::type> {
  static node* get(const std::vector<node*>& sequence, const Key& key,
                   shared_memory_holder /* pMemory */) {
    return key < sequence.size() ? sequence[key] : nullptr;
  }

  static node* get(std::vector<node*>& sequence, const Key& key,
                   shared_memory_holder pMemory) {
    if (key > sequence.size() || (key > 0 && !sequence[key - 1]->is_defined()))
      return nullptr;
    if (key == sequence.size())
      sequence.push_back(&pMemory->create_node());
    return sequence[key];
  }
};

template <typename Key>
struct get_idx<Key, typename std::enable_if<std::is_signed<Key>::value>::type> {
  static node* get(const std::vector<node*>& sequence, const Key& key,
                   shared_memory_holder pMemory) {
    return key >= 0 ? get_idx<std::size_t>::get(
                          sequence, static_cast<std::size_t>(key), pMemory)
                    : nullptr;
  }
  static node* get(std::vector<node*>& sequence, const Key& key,
                   shared_memory_holder pMemory) {
    return key >= 0 ? get_idx<std::size_t>::get(
                          sequence, static_cast<std::size_t>(key), pMemory)
                    : nullptr;
  }
};

template <typename Key, typename Enable = void>
struct remove_idx {
  static bool remove(std::vector<node*>&, const Key&, std::size_t&) {
    return false;
  }
};

template <typename Key>
struct remove_idx<
    Key, typename std::enable_if<std::is_unsigned<Key>::value &&
                                 !std::is_same<Key, bool>::value>::type> {

  static bool remove(std::vector<node*>& sequence, const Key& key,
                     std::size_t& seqSize) {
    if (key >= sequence.size()) {
      return false;
    } else {
      sequence.erase(sequence.begin() + key);
      if (seqSize > key) {
          --seqSize;
      }
      return true;
    }
  }
};

template <typename Key>
struct remove_idx<Key,
                  typename std::enable_if<std::is_signed<Key>::value>::type> {

  static bool remove(std::vector<node*>& sequence, const Key& key,
                     std::size_t& seqSize) {
    return key >= 0 ? remove_idx<std::size_t>::remove(
                          sequence, static_cast<std::size_t>(key), seqSize)
                    : false;
  }
};

template <typename T>
inline bool node::equals(const T& rhs, shared_memory_holder pMemory) {
  T lhs;
  if (convert<T>::decode(Node(*this, pMemory), lhs)) {
    return lhs == rhs;
  }
  return false;
}

inline bool node::equals(const char* rhs, shared_memory_holder pMemory) {
  std::string lhs;
  if (convert<std::string>::decode(Node(*this, std::move(pMemory)), lhs)) {
    return lhs == rhs;
  }
  return false;
}

// indexing
template <typename Key>
inline node* node_data::get(const Key& key,
                            shared_memory_holder pMemory) const {
  switch (m_type) {
    case NodeType::Map:
      break;
    case NodeType::Undefined:
    case NodeType::Null:
      return nullptr;
    case NodeType::Sequence:
      if (node* pNode = get_idx<Key>::get(m_sequence, key, pMemory))
        return pNode;
      return nullptr;
    case NodeType::Scalar:
      throw BadSubscript(m_mark, key);
  }

  auto it = std::find_if(m_map.begin(), m_map.end(), [&](const kv_pair m) {
    return m.first->equals(key, pMemory);
  });

  return it != m_map.end() ? it->second : nullptr;
}

template <typename Key>
inline node& node_data::get(const Key& key, shared_memory_holder pMemory) {
  switch (m_type) {
    case NodeType::Map:
      break;
    case NodeType::Undefined:
    case NodeType::Null:
    case NodeType::Sequence:
      if (node* pNode = get_idx<Key>::get(m_sequence, key, pMemory)) {
        m_type = NodeType::Sequence;
        return *pNode;
      }

      convert_to_map(pMemory);
      break;
    case NodeType::Scalar:
      throw BadSubscript(m_mark, key);
  }

  auto it = std::find_if(m_map.begin(), m_map.end(), [&](const kv_pair m) {
    return m.first->equals(key, pMemory);
  });

  if (it != m_map.end()) {
    return *it->second;
  }

  node& k = convert_to_node(key, pMemory);
  node& v = pMemory->create_node();
  insert_map_pair(k, v);
  return v;
}

template <typename Key>
inline bool node_data::remove(const Key& key, shared_memory_holder pMemory) {
  if (m_type == NodeType::Sequence) {
    return remove_idx<Key>::remove(m_sequence, key, m_seqSize);
  }

  if (m_type == NodeType::Map) {
    kv_pairs::iterator it = m_undefinedPairs.begin();
    while (it != m_undefinedPairs.end()) {
      kv_pairs::iterator jt = std::next(it);
      if (it->first->equals(key, pMemory)) {
        m_undefinedPairs.erase(it);
      }
      it = jt;
    }

    auto iter = std::find_if(m_map.begin(), m_map.end(), [&](const kv_pair m) {
      return m.first->equals(key, pMemory);
    });

    if (iter != m_map.end()) {
      m_map.erase(iter);
      return true;
    }
  }

  return false;
}

// map
template <typename Key, typename Value>
inline void node_data::force_insert(const Key& key, const Value& value,
                                    shared_memory_holder pMemory) {
  switch (m_type) {
    case NodeType::Map:
      break;
    case NodeType::Undefined:
    case NodeType::Null:
    case NodeType::Sequence:
      convert_to_map(pMemory);
      break;
    case NodeType::Scalar:
      throw BadInsert();
  }

  node& k = convert_to_node(key, pMemory);
  node& v = convert_to_node(value, pMemory);
  insert_map_pair(k, v);
}

template <typename T>
inline node& node_data::convert_to_node(const T& rhs,
                                        shared_memory_holder pMemory) {
  Node value = convert<T>::encode(rhs);
  value.EnsureNodeExists();
  pMemory->merge(*value.m_pMemory);
  return *value.m_pNode;
}
}
}

#endif  // NODE_DETAIL_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/detail/impl.h ======

// Expanding include: yaml-cpp/node/parse.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/parse.h ======
#ifndef VALUE_PARSE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_PARSE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <iosfwd>
#include <string>
#include <vector>

// Expanding include: yaml-cpp/dll.h

namespace YAML {
class Node;

/**
 * Loads the input string as a single YAML document.
 *
 * @throws {@link ParserException} if it is malformed.
 */
YAML_CPP_API Node Load(const std::string& input);

/**
 * Loads the input string as a single YAML document.
 *
 * @throws {@link ParserException} if it is malformed.
 */
YAML_CPP_API Node Load(const char* input);

/**
 * Loads the input stream as a single YAML document.
 *
 * @throws {@link ParserException} if it is malformed.
 */
YAML_CPP_API Node Load(std::istream& input);

/**
 * Loads the input file as a single YAML document.
 *
 * @throws {@link ParserException} if it is malformed.
 * @throws {@link BadFile} if the file cannot be loaded.
 */
YAML_CPP_API Node LoadFile(const std::string& filename);

/**
 * Loads the input string as a list of YAML documents.
 *
 * @throws {@link ParserException} if it is malformed.
 */
YAML_CPP_API std::vector<Node> LoadAll(const std::string& input);

/**
 * Loads the input string as a list of YAML documents.
 *
 * @throws {@link ParserException} if it is malformed.
 */
YAML_CPP_API std::vector<Node> LoadAll(const char* input);

/**
 * Loads the input stream as a list of YAML documents.
 *
 * @throws {@link ParserException} if it is malformed.
 */
YAML_CPP_API std::vector<Node> LoadAll(std::istream& input);

/**
 * Loads the input file as a list of YAML documents.
 *
 * @throws {@link ParserException} if it is malformed.
 * @throws {@link BadFile} if the file cannot be loaded.
 */
YAML_CPP_API std::vector<Node> LoadAllFromFile(const std::string& filename);
}  // namespace YAML

#endif  // VALUE_PARSE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/parse.h ======

// Expanding include: yaml-cpp/node/emit.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/emit.h ======
#ifndef NODE_EMIT_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_EMIT_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>
#include <iosfwd>

// Expanding include: yaml-cpp/dll.h

namespace YAML {
class Emitter;
class Node;

/**
 * Emits the node to the given {@link Emitter}. If there is an error in writing,
 * {@link Emitter#good} will return false.
 */
YAML_CPP_API Emitter& operator<<(Emitter& out, const Node& node);

/** Emits the node to the given output stream. */
YAML_CPP_API std::ostream& operator<<(std::ostream& out, const Node& node);

/** Converts the node to a YAML string. */
YAML_CPP_API std::string Dump(const Node& node);
}  // namespace YAML

#endif  // NODE_EMIT_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/node/emit.h ======


#endif  // YAML_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/yaml.h ======


// ====== IMPLEMENTATION ======

// ====== BEGIN yaml-cpp/src/binary.cpp ======
// Expanding include: yaml-cpp/binary.h

#include <cctype>

namespace YAML {
static const char encoding[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string EncodeBase64(const unsigned char *data, std::size_t size) {
  const char PAD = '=';

  std::string ret;
  ret.resize(4 * size / 3 + 3);
  char *out = &ret[0];

  std::size_t chunks = size / 3;
  std::size_t remainder = size % 3;

  for (std::size_t i = 0; i < chunks; i++, data += 3) {
    *out++ = encoding[data[0] >> 2];
    *out++ = encoding[((data[0] & 0x3) << 4) | (data[1] >> 4)];
    *out++ = encoding[((data[1] & 0xf) << 2) | (data[2] >> 6)];
    *out++ = encoding[data[2] & 0x3f];
  }

  switch (remainder) {
    case 0:
      break;
    case 1:
      *out++ = encoding[data[0] >> 2];
      *out++ = encoding[((data[0] & 0x3) << 4)];
      *out++ = PAD;
      *out++ = PAD;
      break;
    case 2:
      *out++ = encoding[data[0] >> 2];
      *out++ = encoding[((data[0] & 0x3) << 4) | (data[1] >> 4)];
      *out++ = encoding[((data[1] & 0xf) << 2)];
      *out++ = PAD;
      break;
  }

  ret.resize(out - &ret[0]);
  return ret;
}

static const unsigned char decoding[] = {
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 62,  255,
    255, 255, 63,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  255, 255,
    255, 0,   255, 255, 255, 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,
    10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,
    25,  255, 255, 255, 255, 255, 255, 26,  27,  28,  29,  30,  31,  32,  33,
    34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,
    49,  50,  51,  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255,
};

std::vector<unsigned char> DecodeBase64(const std::string &input) {
  using ret_type = std::vector<unsigned char>;
  if (input.empty())
    return ret_type();

  ret_type ret(3 * input.size() / 4 + 1);
  unsigned char *out = &ret[0];

  unsigned value = 0;
  for (std::size_t i = 0, cnt = 0; i < input.size(); i++) {
    if (std::isspace(static_cast<unsigned char>(input[i]))) {
      // skip newlines
      continue;
    }
    unsigned char d = decoding[static_cast<unsigned char>(input[i])];
    if (d == 255)
      return ret_type();

    value = (value << 6) | d;
    if (cnt % 4 == 3) {
      *out++ = value >> 16;
      if (i > 0 && input[i - 1] != '=')
        *out++ = value >> 8;
      if (input[i] != '=')
        *out++ = value;
    }
    ++cnt;
  }

  ret.resize(out - &ret[0]);
  return ret;
}
}  // namespace YAML
// ====== END yaml-cpp/src/binary.cpp ======


// ====== BEGIN yaml-cpp/src/contrib/graphbuilderadapter.cpp ======
// Expanding include: graphbuilderadapter.h

// ====== BEGIN yaml-cpp/src/contrib/graphbuilderadapter.h ======
#ifndef GRAPHBUILDERADAPTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define GRAPHBUILDERADAPTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <cstdlib>
#include <map>
#include <stack>

// Expanding include: yaml-cpp/anchor.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/anchor.h ======
#ifndef ANCHOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define ANCHOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <cstddef>

namespace YAML {
using anchor_t = std::size_t;
const anchor_t NullAnchor = 0;
}

#endif  // ANCHOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/anchor.h ======

// Expanding include: yaml-cpp/contrib/anchordict.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/contrib/anchordict.h ======
#ifndef ANCHORDICT_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define ANCHORDICT_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <vector>

// Expanding include: ../anchor.h

namespace YAML {
/**
 * An object that stores and retrieves values correlating to {@link anchor_t}
 * values.
 *
 * <p>Efficient implementation that can make assumptions about how
 * {@code anchor_t} values are assigned by the {@link Parser} class.
 */
template <class T>
class AnchorDict {
 public:
  AnchorDict() : m_data{} {}
  void Register(anchor_t anchor, T value) {
    if (anchor > m_data.size()) {
      m_data.resize(anchor);
    }
    m_data[anchor - 1] = value;
  }

  T Get(anchor_t anchor) const { return m_data[anchor - 1]; }

 private:
  std::vector<T> m_data;
};
}  // namespace YAML

#endif  // ANCHORDICT_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/contrib/anchordict.h ======

// Expanding include: yaml-cpp/emitterstyle.h
// Expanding include: yaml-cpp/eventhandler.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/eventhandler.h ======
#ifndef EVENTHANDLER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EVENTHANDLER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>

// Expanding include: yaml-cpp/anchor.h
// Expanding include: yaml-cpp/emitterstyle.h

namespace YAML {
struct Mark;

class EventHandler {
 public:
  virtual ~EventHandler() = default;

  virtual void OnDocumentStart(const Mark& mark) = 0;
  virtual void OnDocumentEnd() = 0;

  virtual void OnNull(const Mark& mark, anchor_t anchor) = 0;
  virtual void OnAlias(const Mark& mark, anchor_t anchor) = 0;
  virtual void OnScalar(const Mark& mark, const std::string& tag,
                        anchor_t anchor, const std::string& value) = 0;

  virtual void OnSequenceStart(const Mark& mark, const std::string& tag,
                               anchor_t anchor, EmitterStyle::value style) = 0;
  virtual void OnSequenceEnd() = 0;

  virtual void OnMapStart(const Mark& mark, const std::string& tag,
                          anchor_t anchor, EmitterStyle::value style) = 0;
  virtual void OnMapEnd() = 0;

  virtual void OnAnchor(const Mark& /*mark*/,
                        const std::string& /*anchor_name*/) {
    // empty default implementation for compatibility
  }
};
}  // namespace YAML

#endif  // EVENTHANDLER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/eventhandler.h ======


namespace YAML {
class GraphBuilderInterface;
struct Mark;
}  // namespace YAML

namespace YAML {
class GraphBuilderAdapter : public EventHandler {
 public:
  GraphBuilderAdapter(GraphBuilderInterface& builder)
      : m_builder(builder),
        m_containers{},
        m_anchors{},
        m_pRootNode(nullptr),
        m_pKeyNode(nullptr) {}
  GraphBuilderAdapter(const GraphBuilderAdapter&) = delete;
  GraphBuilderAdapter(GraphBuilderAdapter&&) = delete;
  GraphBuilderAdapter& operator=(const GraphBuilderAdapter&) = delete;
  GraphBuilderAdapter& operator=(GraphBuilderAdapter&&) = delete;

  virtual void OnDocumentStart(const Mark& mark) { (void)mark; }
  virtual void OnDocumentEnd() {}

  virtual void OnNull(const Mark& mark, anchor_t anchor);
  virtual void OnAlias(const Mark& mark, anchor_t anchor);
  virtual void OnScalar(const Mark& mark, const std::string& tag,
                        anchor_t anchor, const std::string& value);

  virtual void OnSequenceStart(const Mark& mark, const std::string& tag,
                               anchor_t anchor, EmitterStyle::value style);
  virtual void OnSequenceEnd();

  virtual void OnMapStart(const Mark& mark, const std::string& tag,
                          anchor_t anchor, EmitterStyle::value style);
  virtual void OnMapEnd();

  void* RootNode() const { return m_pRootNode; }

 private:
  struct ContainerFrame {
    ContainerFrame(void* pSequence)
        : pContainer(pSequence), pPrevKeyNode(&sequenceMarker) {}
    ContainerFrame(void* pMap, void* pPreviousKeyNode)
        : pContainer(pMap), pPrevKeyNode(pPreviousKeyNode) {}

    void* pContainer;
    void* pPrevKeyNode;

    bool isMap() const { return pPrevKeyNode != &sequenceMarker; }

   private:
    static int sequenceMarker;
  };
  typedef std::stack<ContainerFrame> ContainerStack;
  typedef AnchorDict<void*> AnchorMap;

  GraphBuilderInterface& m_builder;
  ContainerStack m_containers;
  AnchorMap m_anchors;
  void* m_pRootNode;
  void* m_pKeyNode;

  void* GetCurrentParent() const;
  void RegisterAnchor(anchor_t anchor, void* pNode);
  void DispositionNode(void* pNode);
};
}  // namespace YAML

#endif  // GRAPHBUILDERADAPTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/contrib/graphbuilderadapter.h ======

// Expanding include: yaml-cpp/contrib/graphbuilder.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/contrib/graphbuilder.h ======
#ifndef GRAPHBUILDER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define GRAPHBUILDER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/mark.h
#include <string>

namespace YAML {
class Parser;

// GraphBuilderInterface
// . Abstraction of node creation
// . pParentNode is always nullptr or the return value of one of the NewXXX()
//   functions.
class GraphBuilderInterface {
 public:
  virtual ~GraphBuilderInterface() = 0;

  // Create and return a new node with a null value.
  virtual void *NewNull(const Mark &mark, void *pParentNode) = 0;

  // Create and return a new node with the given tag and value.
  virtual void *NewScalar(const Mark &mark, const std::string &tag,
                          void *pParentNode, const std::string &value) = 0;

  // Create and return a new sequence node
  virtual void *NewSequence(const Mark &mark, const std::string &tag,
                            void *pParentNode) = 0;

  // Add pNode to pSequence.  pNode was created with one of the NewXxx()
  // functions and pSequence with NewSequence().
  virtual void AppendToSequence(void *pSequence, void *pNode) = 0;

  // Note that no moew entries will be added to pSequence
  virtual void SequenceComplete(void *pSequence) { (void)pSequence; }

  // Create and return a new map node
  virtual void *NewMap(const Mark &mark, const std::string &tag,
                       void *pParentNode) = 0;

  // Add the pKeyNode => pValueNode mapping to pMap.  pKeyNode and pValueNode
  // were created with one of the NewXxx() methods and pMap with NewMap().
  virtual void AssignInMap(void *pMap, void *pKeyNode, void *pValueNode) = 0;

  // Note that no more assignments will be made in pMap
  virtual void MapComplete(void *pMap) { (void)pMap; }

  // Return the node that should be used in place of an alias referencing
  // pNode (pNode by default)
  virtual void *AnchorReference(const Mark &mark, void *pNode) {
    (void)mark;
    return pNode;
  }
};

// Typesafe wrapper for GraphBuilderInterface.  Assumes that Impl defines
// Node, Sequence, and Map types.  Sequence and Map must derive from Node
// (unless Node is defined as void).  Impl must also implement function with
// all of the same names as the virtual functions in GraphBuilderInterface
// -- including the ones with default implementations -- but with the
// prototypes changed to accept an explicit Node*, Sequence*, or Map* where
// appropriate.
template <class Impl>
class GraphBuilder : public GraphBuilderInterface {
 public:
  typedef typename Impl::Node Node;
  typedef typename Impl::Sequence Sequence;
  typedef typename Impl::Map Map;

  GraphBuilder(Impl &impl) : m_impl(impl) {
    Map *pMap = nullptr;
    Sequence *pSeq = nullptr;
    Node *pNode = nullptr;

    // Type consistency checks
    pNode = pMap;
    pNode = pSeq;
  }

  GraphBuilderInterface &AsBuilderInterface() { return *this; }

  virtual void *NewNull(const Mark &mark, void *pParentNode) {
    return CheckType<Node>(m_impl.NewNull(mark, AsNode(pParentNode)));
  }

  virtual void *NewScalar(const Mark &mark, const std::string &tag,
                          void *pParentNode, const std::string &value) {
    return CheckType<Node>(
        m_impl.NewScalar(mark, tag, AsNode(pParentNode), value));
  }

  virtual void *NewSequence(const Mark &mark, const std::string &tag,
                            void *pParentNode) {
    return CheckType<Sequence>(
        m_impl.NewSequence(mark, tag, AsNode(pParentNode)));
  }
  virtual void AppendToSequence(void *pSequence, void *pNode) {
    m_impl.AppendToSequence(AsSequence(pSequence), AsNode(pNode));
  }
  virtual void SequenceComplete(void *pSequence) {
    m_impl.SequenceComplete(AsSequence(pSequence));
  }

  virtual void *NewMap(const Mark &mark, const std::string &tag,
                       void *pParentNode) {
    return CheckType<Map>(m_impl.NewMap(mark, tag, AsNode(pParentNode)));
  }
  virtual void AssignInMap(void *pMap, void *pKeyNode, void *pValueNode) {
    m_impl.AssignInMap(AsMap(pMap), AsNode(pKeyNode), AsNode(pValueNode));
  }
  virtual void MapComplete(void *pMap) { m_impl.MapComplete(AsMap(pMap)); }

  virtual void *AnchorReference(const Mark &mark, void *pNode) {
    return CheckType<Node>(m_impl.AnchorReference(mark, AsNode(pNode)));
  }

 private:
  Impl &m_impl;

  // Static check for pointer to T
  template <class T, class U>
  static T *CheckType(U *p) {
    return p;
  }

  static Node *AsNode(void *pNode) { return static_cast<Node *>(pNode); }
  static Sequence *AsSequence(void *pSeq) {
    return static_cast<Sequence *>(pSeq);
  }
  static Map *AsMap(void *pMap) { return static_cast<Map *>(pMap); }
};

void *BuildGraphOfNextDocument(Parser &parser,
                               GraphBuilderInterface &graphBuilder);

template <class Impl>
typename Impl::Node *BuildGraphOfNextDocument(Parser &parser, Impl &impl) {
  GraphBuilder<Impl> graphBuilder(impl);
  return static_cast<typename Impl::Node *>(
      BuildGraphOfNextDocument(parser, graphBuilder));
}
}

#endif  // GRAPHBUILDER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/contrib/graphbuilder.h ======


namespace YAML {
struct Mark;

int GraphBuilderAdapter::ContainerFrame::sequenceMarker;

void GraphBuilderAdapter::OnNull(const Mark &mark, anchor_t anchor) {
  void *pParent = GetCurrentParent();
  void *pNode = m_builder.NewNull(mark, pParent);
  RegisterAnchor(anchor, pNode);

  DispositionNode(pNode);
}

void GraphBuilderAdapter::OnAlias(const Mark &mark, anchor_t anchor) {
  void *pReffedNode = m_anchors.Get(anchor);
  DispositionNode(m_builder.AnchorReference(mark, pReffedNode));
}

void GraphBuilderAdapter::OnScalar(const Mark &mark, const std::string &tag,
                                   anchor_t anchor, const std::string &value) {
  void *pParent = GetCurrentParent();
  void *pNode = m_builder.NewScalar(mark, tag, pParent, value);
  RegisterAnchor(anchor, pNode);

  DispositionNode(pNode);
}

void GraphBuilderAdapter::OnSequenceStart(const Mark &mark,
                                          const std::string &tag,
                                          anchor_t anchor,
                                          EmitterStyle::value /* style */) {
  void *pNode = m_builder.NewSequence(mark, tag, GetCurrentParent());
  m_containers.push(ContainerFrame(pNode));
  RegisterAnchor(anchor, pNode);
}

void GraphBuilderAdapter::OnSequenceEnd() {
  void *pSequence = m_containers.top().pContainer;
  m_containers.pop();

  DispositionNode(pSequence);
}

void GraphBuilderAdapter::OnMapStart(const Mark &mark, const std::string &tag,
                                     anchor_t anchor,
                                     EmitterStyle::value /* style */) {
  void *pNode = m_builder.NewMap(mark, tag, GetCurrentParent());
  m_containers.push(ContainerFrame(pNode, m_pKeyNode));
  m_pKeyNode = nullptr;
  RegisterAnchor(anchor, pNode);
}

void GraphBuilderAdapter::OnMapEnd() {
  void *pMap = m_containers.top().pContainer;
  m_pKeyNode = m_containers.top().pPrevKeyNode;
  m_containers.pop();
  DispositionNode(pMap);
}

void *GraphBuilderAdapter::GetCurrentParent() const {
  if (m_containers.empty()) {
    return nullptr;
  }
  return m_containers.top().pContainer;
}

void GraphBuilderAdapter::RegisterAnchor(anchor_t anchor, void *pNode) {
  if (anchor) {
    m_anchors.Register(anchor, pNode);
  }
}

void GraphBuilderAdapter::DispositionNode(void *pNode) {
  if (m_containers.empty()) {
    m_pRootNode = pNode;
    return;
  }

  void *pContainer = m_containers.top().pContainer;
  if (m_containers.top().isMap()) {
    if (m_pKeyNode) {
      m_builder.AssignInMap(pContainer, m_pKeyNode, pNode);
      m_pKeyNode = nullptr;
    } else {
      m_pKeyNode = pNode;
    }
  } else {
    m_builder.AppendToSequence(pContainer, pNode);
  }
}
}  // namespace YAML
// ====== END yaml-cpp/src/contrib/graphbuilderadapter.cpp ======


// ====== BEGIN yaml-cpp/src/contrib/graphbuilder.cpp ======
// Expanding include: graphbuilderadapter.h

// Expanding include: yaml-cpp/parser.h

namespace YAML {
class GraphBuilderInterface;

void* BuildGraphOfNextDocument(Parser& parser,
                               GraphBuilderInterface& graphBuilder) {
  GraphBuilderAdapter eventHandler(graphBuilder);
  if (parser.HandleNextDocument(eventHandler)) {
    return eventHandler.RootNode();
  }
  return nullptr;
}
}  // namespace YAML
// ====== END yaml-cpp/src/contrib/graphbuilder.cpp ======


// ====== BEGIN yaml-cpp/src/convert.cpp ======
#include <algorithm>

// Expanding include: yaml-cpp/node/convert.h

namespace {
// we're not gonna mess with the mess that is all the isupper/etc. functions
bool IsLower(char ch) { return 'a' <= ch && ch <= 'z'; }
bool IsUpper(char ch) { return 'A' <= ch && ch <= 'Z'; }
char ToLower(char ch) { return IsUpper(ch) ? ch + 'a' - 'A' : ch; }

std::string tolower(const std::string& str) {
  std::string s(str);
  std::transform(s.begin(), s.end(), s.begin(), ToLower);
  return s;
}

template <typename T>
bool IsEntirely(const std::string& str, T func) {
  return std::all_of(str.begin(), str.end(), [=](char ch) { return func(ch); });
}

// IsFlexibleCase
// . Returns true if 'str' is:
//   . UPPERCASE
//   . lowercase
//   . Capitalized
bool IsFlexibleCase(const std::string& str) {
  if (str.empty())
    return true;

  if (IsEntirely(str, IsLower))
    return true;

  bool firstcaps = IsUpper(str[0]);
  std::string rest = str.substr(1);
  return firstcaps && (IsEntirely(rest, IsLower) || IsEntirely(rest, IsUpper));
}
}  // namespace

namespace YAML {
bool convert<bool>::decode(const Node& node, bool& rhs) {
  if (!node.IsScalar())
    return false;

  // we can't use iostream bool extraction operators as they don't
  // recognize all possible values in the table below (taken from
  // http://yaml.org/type/bool.html)
  static const struct {
    std::string truename, falsename;
  } names[] = {
      {"y", "n"},
      {"yes", "no"},
      {"true", "false"},
      {"on", "off"},
  };

  if (!IsFlexibleCase(node.Scalar()))
    return false;

  for (const auto& name : names) {
    if (name.truename == tolower(node.Scalar())) {
      rhs = true;
      return true;
    }

    if (name.falsename == tolower(node.Scalar())) {
      rhs = false;
      return true;
    }
  }

  return false;
}
}  // namespace YAML
// ====== END yaml-cpp/src/convert.cpp ======


// ====== BEGIN yaml-cpp/src/depthguard.cpp ======
// Expanding include: yaml-cpp/depthguard.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/depthguard.h ======
#ifndef DEPTH_GUARD_H_00000000000000000000000000000000000000000000000000000000
#define DEPTH_GUARD_H_00000000000000000000000000000000000000000000000000000000

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: exceptions.h

namespace YAML {

/**
 * @brief The DeepRecursion class
 *  An exception class which is thrown by DepthGuard. Ideally it should be
 * a member of DepthGuard. However, DepthGuard is a templated class which means
 * that any catch points would then need to know the template parameters. It is
 * simpler for clients to not have to know at the catch point what was the
 * maximum depth.
 */
class DeepRecursion : public ParserException {
public:
  virtual ~DeepRecursion() = default;

  DeepRecursion(int depth, const Mark& mark_, const std::string& msg_);

  // Returns the recursion depth when the exception was thrown
  int depth() const {
    return m_depth;
  }

private:
  int m_depth = 0;
};

/**
 * @brief The DepthGuard class
 *  DepthGuard takes a reference to an integer. It increments the integer upon
 * construction of DepthGuard and decrements the integer upon destruction.
 *
 * If the integer would be incremented past max_depth, then an exception is
 * thrown. This is ideally geared toward guarding against deep recursion.
 *
 * @param max_depth
 *  compile-time configurable maximum depth.
 */
template <int max_depth = 2000>
class DepthGuard final {
public:
  DepthGuard(int & depth_, const Mark& mark_, const std::string& msg_) : m_depth(depth_) {
    ++m_depth;
    if ( max_depth <= m_depth ) {
        throw DeepRecursion{m_depth, mark_, msg_};
    }
  }

  DepthGuard(const DepthGuard & copy_ctor) = delete;
  DepthGuard(DepthGuard && move_ctor) = delete;
  DepthGuard & operator=(const DepthGuard & copy_assign) = delete;
  DepthGuard & operator=(DepthGuard && move_assign) = delete;

  ~DepthGuard() {
    --m_depth;
  }

  int current_depth() const {
    return m_depth;
  }

private:
    int & m_depth;
};

} // namespace YAML

#endif // DEPTH_GUARD_H_00000000000000000000000000000000000000000000000000000000
// ====== END yaml-cpp/include/yaml-cpp/depthguard.h ======


namespace YAML {

DeepRecursion::DeepRecursion(int depth, const Mark& mark_,
                             const std::string& msg_)
    : ParserException(mark_, msg_), m_depth(depth) {}

}  // namespace YAML
// ====== END yaml-cpp/src/depthguard.cpp ======


// ====== BEGIN yaml-cpp/src/directives.cpp ======
// Expanding include: directives.h

// ====== BEGIN yaml-cpp/src/directives.h ======
#ifndef DIRECTIVES_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define DIRECTIVES_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>
#include <map>

namespace YAML {
struct Version {
  bool isDefault;
  int major, minor;
};

struct Directives {
  Directives();

  std::string TranslateTagHandle(const std::string& handle) const;

  Version version;
  std::map<std::string, std::string> tags;
};
}

#endif  // DIRECTIVES_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/directives.h ======


namespace YAML {
Directives::Directives() : version{true, 1, 2}, tags{} {}

std::string Directives::TranslateTagHandle(
    const std::string& handle) const {
  auto it = tags.find(handle);
  if (it == tags.end()) {
    if (handle == "!!")
      return "tag:yaml.org,2002:";
    return handle;
  }

  return it->second;
}
}  // namespace YAML
// ====== END yaml-cpp/src/directives.cpp ======


// ====== BEGIN yaml-cpp/src/emit.cpp ======
// Expanding include: yaml-cpp/node/emit.h
// Expanding include: nodeevents.h

// ====== BEGIN yaml-cpp/src/nodeevents.h ======
#ifndef NODE_NODEEVENTS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_NODEEVENTS_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <map>
#include <vector>

// Expanding include: yaml-cpp/anchor.h
// Expanding include: yaml-cpp/node/ptr.h

namespace YAML {
namespace detail {
class node;
}  // namespace detail
}  // namespace YAML

namespace YAML {
class EventHandler;
class Node;

class NodeEvents {
 public:
  explicit NodeEvents(const Node& node);
  NodeEvents(const NodeEvents&) = delete;
  NodeEvents(NodeEvents&&) = delete;
  NodeEvents& operator=(const NodeEvents&) = delete;
  NodeEvents& operator=(NodeEvents&&) = delete;

  void Emit(EventHandler& handler);

 private:
  class AliasManager {
   public:
    AliasManager() : m_anchorByIdentity{}, m_curAnchor(0) {}

    void RegisterReference(const detail::node& node);
    anchor_t LookupAnchor(const detail::node& node) const;

   private:
    anchor_t _CreateNewAnchor() { return ++m_curAnchor; }

   private:
    using AnchorByIdentity = std::map<const detail::node_ref*, anchor_t>;
    AnchorByIdentity m_anchorByIdentity;

    anchor_t m_curAnchor;
  };

  void Setup(const detail::node& node);
  void Emit(const detail::node& node, EventHandler& handler,
            AliasManager& am) const;
  bool IsAliased(const detail::node& node) const;

 private:
  detail::shared_memory_holder m_pMemory;
  detail::node* m_root;

  using RefCount = std::map<const detail::node_ref*, int>;
  RefCount m_refCount;
};
}  // namespace YAML

#endif  // NODE_NODEEVENTS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/nodeevents.h ======

// Expanding include: yaml-cpp/emitfromevents.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/emitfromevents.h ======
#ifndef EMITFROMEVENTS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EMITFROMEVENTS_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <stack>

// Expanding include: yaml-cpp/anchor.h
// Expanding include: yaml-cpp/emitterstyle.h
// Expanding include: yaml-cpp/eventhandler.h

namespace YAML {
struct Mark;
}  // namespace YAML

namespace YAML {
class Emitter;

class EmitFromEvents : public EventHandler {
 public:
  EmitFromEvents(Emitter& emitter);
  ~EmitFromEvents() override = default;

  void OnDocumentStart(const Mark& mark) override;
  void OnDocumentEnd() override;

  void OnNull(const Mark& mark, anchor_t anchor) override;
  void OnAlias(const Mark& mark, anchor_t anchor) override;
  void OnScalar(const Mark& mark, const std::string& tag,
                        anchor_t anchor, const std::string& value) override;

  void OnSequenceStart(const Mark& mark, const std::string& tag,
                               anchor_t anchor, EmitterStyle::value style) override;
  void OnSequenceEnd() override;

  void OnMapStart(const Mark& mark, const std::string& tag,
                          anchor_t anchor, EmitterStyle::value style) override;
  void OnMapEnd() override;

 private:
  void BeginNode();
  void EmitProps(const std::string& tag, anchor_t anchor);

 private:
  Emitter& m_emitter;

  struct State {
    enum value { WaitingForSequenceEntry, WaitingForKey, WaitingForValue };
  };
  std::stack<State::value> m_stateStack;
};
}

#endif  // EMITFROMEVENTS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/include/yaml-cpp/emitfromevents.h ======

// Expanding include: yaml-cpp/emitter.h

namespace YAML {
Emitter& operator<<(Emitter& out, const Node& node) {
  EmitFromEvents emitFromEvents(out);
  NodeEvents events(node);
  events.Emit(emitFromEvents);
  return out;
}

std::ostream& operator<<(std::ostream& out, const Node& node) {
  Emitter emitter(out);
  emitter << node;
  return out;
}

std::string Dump(const Node& node) {
  Emitter emitter;
  emitter << node;
  return emitter.c_str();
}
}  // namespace YAML
// ====== END yaml-cpp/src/emit.cpp ======


// ====== BEGIN yaml-cpp/src/emitfromevents.cpp ======
#include <cassert>
#include <sstream>

// Expanding include: yaml-cpp/emitfromevents.h
// Expanding include: yaml-cpp/emitter.h
// Expanding include: yaml-cpp/emittermanip.h
// Expanding include: yaml-cpp/null.h

namespace YAML {
struct Mark;
}  // namespace YAML

namespace {
std::string ToString(YAML::anchor_t anchor) {
  std::stringstream stream;
  stream << anchor;
  return stream.str();
}
}  // namespace

namespace YAML {
EmitFromEvents::EmitFromEvents(Emitter& emitter)
    : m_emitter(emitter), m_stateStack{} {}

void EmitFromEvents::OnDocumentStart(const Mark&) {}

void EmitFromEvents::OnDocumentEnd() {}

void EmitFromEvents::OnNull(const Mark&, anchor_t anchor) {
  BeginNode();
  EmitProps("", anchor);
  m_emitter << Null;
}

void EmitFromEvents::OnAlias(const Mark&, anchor_t anchor) {
  BeginNode();
  m_emitter << Alias(ToString(anchor));
}

void EmitFromEvents::OnScalar(const Mark&, const std::string& tag,
                              anchor_t anchor, const std::string& value) {
  BeginNode();
  EmitProps(tag, anchor);
  m_emitter << value;
}

void EmitFromEvents::OnSequenceStart(const Mark&, const std::string& tag,
                                     anchor_t anchor,
                                     EmitterStyle::value style) {
  BeginNode();
  EmitProps(tag, anchor);
  switch (style) {
    case EmitterStyle::Block:
      m_emitter << Block;
      break;
    case EmitterStyle::Flow:
      m_emitter << Flow;
      break;
    default:
      break;
  }
  // Restore the global settings to eliminate the override from node style
  m_emitter.RestoreGlobalModifiedSettings();
  m_emitter << BeginSeq;
  m_stateStack.push(State::WaitingForSequenceEntry);
}

void EmitFromEvents::OnSequenceEnd() {
  m_emitter << EndSeq;
  assert(m_stateStack.top() == State::WaitingForSequenceEntry);
  m_stateStack.pop();
}

void EmitFromEvents::OnMapStart(const Mark&, const std::string& tag,
                                anchor_t anchor, EmitterStyle::value style) {
  BeginNode();
  EmitProps(tag, anchor);
  switch (style) {
    case EmitterStyle::Block:
      m_emitter << Block;
      break;
    case EmitterStyle::Flow:
      m_emitter << Flow;
      break;
    default:
      break;
  }
  // Restore the global settings to eliminate the override from node style
  m_emitter.RestoreGlobalModifiedSettings();
  m_emitter << BeginMap;
  m_stateStack.push(State::WaitingForKey);
}

void EmitFromEvents::OnMapEnd() {
  m_emitter << EndMap;
  assert(m_stateStack.top() == State::WaitingForKey);
  m_stateStack.pop();
}

void EmitFromEvents::BeginNode() {
  if (m_stateStack.empty())
    return;

  switch (m_stateStack.top()) {
    case State::WaitingForKey:
      m_emitter << Key;
      m_stateStack.top() = State::WaitingForValue;
      break;
    case State::WaitingForValue:
      m_emitter << Value;
      m_stateStack.top() = State::WaitingForKey;
      break;
    default:
      break;
  }
}

void EmitFromEvents::EmitProps(const std::string& tag, anchor_t anchor) {
  if (!tag.empty() && tag != "?" && tag != "!"){
      if (tag[0] == '!') {
        m_emitter << LocalTag(std::string(tag.begin()+1, tag.end()));
      } else {
        m_emitter << VerbatimTag(tag);
      }
  }
  if (anchor)
    m_emitter << Anchor(ToString(anchor));
}
}  // namespace YAML
// ====== END yaml-cpp/src/emitfromevents.cpp ======


// ====== BEGIN yaml-cpp/src/emitter.cpp ======
#include <sstream>

// Expanding include: emitterutils.h

// ====== BEGIN yaml-cpp/src/emitterutils.h ======
#ifndef EMITTERUTILS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EMITTERUTILS_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>

// Expanding include: emitterstate.h

// ====== BEGIN yaml-cpp/src/emitterstate.h ======
#ifndef EMITTERSTATE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EMITTERSTATE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: setting.h

// ====== BEGIN yaml-cpp/src/setting.h ======
#ifndef SETTING_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define SETTING_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/noexcept.h
#include <memory>
#include <utility>
#include <vector>

namespace YAML {

class SettingChangeBase {
 public:
  virtual ~SettingChangeBase() = default;
  virtual void pop() = 0;
};

template <typename T>
class Setting {
 public:
  Setting() : m_value() {}
  Setting(const T& value) : m_value() { set(value); }

  const T get() const { return m_value; }
  std::unique_ptr<SettingChangeBase> set(const T& value);
  void restore(const Setting<T>& oldSetting) { m_value = oldSetting.get(); }

 private:
  T m_value;
};

template <typename T>
class SettingChange : public SettingChangeBase {
 public:
  SettingChange(Setting<T>* pSetting)
      : m_pCurSetting(pSetting),
        m_oldSetting(*pSetting)  // copy old setting to save its state
  {}
  SettingChange(const SettingChange&) = delete;
  SettingChange(SettingChange&&) = delete;
  SettingChange& operator=(const SettingChange&) = delete;
  SettingChange& operator=(SettingChange&&) = delete;

  void pop() override { m_pCurSetting->restore(m_oldSetting); }

 private:
  Setting<T>* m_pCurSetting;
  Setting<T> m_oldSetting;
};

template <typename T>
inline std::unique_ptr<SettingChangeBase> Setting<T>::set(const T& value) {
  std::unique_ptr<SettingChangeBase> pChange(new SettingChange<T>(this));
  m_value = value;
  return pChange;
}

class SettingChanges {
 public:
  SettingChanges() : m_settingChanges{} {}
  SettingChanges(const SettingChanges&) = delete;
  SettingChanges(SettingChanges&&) YAML_CPP_NOEXCEPT = default;
  SettingChanges& operator=(const SettingChanges&) = delete;
  SettingChanges& operator=(SettingChanges&& rhs) YAML_CPP_NOEXCEPT {
    if (this == &rhs)
      return *this;

    clear();
    std::swap(m_settingChanges, rhs.m_settingChanges);

    return *this;
  }
  ~SettingChanges() { clear(); }

  void clear() YAML_CPP_NOEXCEPT {
    restore();
    m_settingChanges.clear();
  }

  void restore() YAML_CPP_NOEXCEPT {
    for (const auto& setting : m_settingChanges)
      setting->pop();
  }

  void push(std::unique_ptr<SettingChangeBase> pSettingChange) {
    m_settingChanges.push_back(std::move(pSettingChange));
  }

 private:
  using setting_changes = std::vector<std::unique_ptr<SettingChangeBase>>;
  setting_changes m_settingChanges;
};
}  // namespace YAML

#endif  // SETTING_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/setting.h ======

// Expanding include: yaml-cpp/emitterdef.h
// Expanding include: yaml-cpp/emittermanip.h

#include <cassert>
#include <memory>
#include <stack>
#include <stdexcept>
#include <vector>

namespace YAML {
struct FmtScope {
  enum value { Local, Global };
};
struct GroupType {
  enum value { NoType, Seq, Map };
};
struct FlowType {
  enum value { NoType, Flow, Block };
};

class EmitterState {
 public:
  EmitterState();
  ~EmitterState();

  // basic state checking
  bool good() const { return m_isGood; }
  const std::string GetLastError() const { return m_lastError; }
  void SetError(const std::string& error) {
    m_isGood = false;
    m_lastError = error;
  }

  // node handling
  void SetAnchor();
  void SetAlias();
  void SetTag();
  void SetNonContent();
  void SetLongKey();
  void ForceFlow();
  void StartedDoc();
  void EndedDoc();
  void StartedScalar();
  void StartedGroup(GroupType::value type);
  void EndedGroup(GroupType::value type);

  EmitterNodeType::value NextGroupType(GroupType::value type) const;
  EmitterNodeType::value CurGroupNodeType() const;

  GroupType::value CurGroupType() const;
  FlowType::value CurGroupFlowType() const;
  std::size_t CurGroupIndent() const;
  std::size_t CurGroupChildCount() const;
  bool CurGroupLongKey() const;

  std::size_t LastIndent() const;
  std::size_t CurIndent() const { return m_curIndent; }
  bool HasAnchor() const { return m_hasAnchor; }
  bool HasAlias() const { return m_hasAlias; }
  bool HasTag() const { return m_hasTag; }
  bool HasBegunNode() const {
    return m_hasAnchor || m_hasTag || m_hasNonContent;
  }
  bool HasBegunContent() const { return m_hasAnchor || m_hasTag; }

  void ClearModifiedSettings();
  void RestoreGlobalModifiedSettings();

  // formatters
  void SetLocalValue(EMITTER_MANIP value);

  bool SetOutputCharset(EMITTER_MANIP value, FmtScope::value scope);
  EMITTER_MANIP GetOutputCharset() const { return m_charset.get(); }

  bool SetStringFormat(EMITTER_MANIP value, FmtScope::value scope);
  EMITTER_MANIP GetStringFormat() const { return m_strFmt.get(); }

  bool SetBoolFormat(EMITTER_MANIP value, FmtScope::value scope);
  EMITTER_MANIP GetBoolFormat() const { return m_boolFmt.get(); }

  bool SetBoolLengthFormat(EMITTER_MANIP value, FmtScope::value scope);
  EMITTER_MANIP GetBoolLengthFormat() const { return m_boolLengthFmt.get(); }

  bool SetBoolCaseFormat(EMITTER_MANIP value, FmtScope::value scope);
  EMITTER_MANIP GetBoolCaseFormat() const { return m_boolCaseFmt.get(); }

  bool SetNullFormat(EMITTER_MANIP value, FmtScope::value scope);
  EMITTER_MANIP GetNullFormat() const { return m_nullFmt.get(); }

  bool SetIntFormat(EMITTER_MANIP value, FmtScope::value scope);
  EMITTER_MANIP GetIntFormat() const { return m_intFmt.get(); }

  bool SetIndent(std::size_t value, FmtScope::value scope);
  std::size_t GetIndent() const { return m_indent.get(); }

  bool SetPreCommentIndent(std::size_t value, FmtScope::value scope);
  std::size_t GetPreCommentIndent() const { return m_preCommentIndent.get(); }
  bool SetPostCommentIndent(std::size_t value, FmtScope::value scope);
  std::size_t GetPostCommentIndent() const { return m_postCommentIndent.get(); }

  bool SetFlowType(GroupType::value groupType, EMITTER_MANIP value,
                   FmtScope::value scope);
  EMITTER_MANIP GetFlowType(GroupType::value groupType) const;

  bool SetMapKeyFormat(EMITTER_MANIP value, FmtScope::value scope);
  EMITTER_MANIP GetMapKeyFormat() const { return m_mapKeyFmt.get(); }

  bool SetFloatPrecision(std::size_t value, FmtScope::value scope);
  std::size_t GetFloatPrecision() const { return m_floatPrecision.get(); }
  bool SetDoublePrecision(std::size_t value, FmtScope::value scope);
  std::size_t GetDoublePrecision() const { return m_doublePrecision.get(); }

 private:
  template <typename T>
  void _Set(Setting<T>& fmt, T value, FmtScope::value scope);

  void StartedNode();

 private:
  // basic state ok?
  bool m_isGood;
  std::string m_lastError;

  // other state
  Setting<EMITTER_MANIP> m_charset;
  Setting<EMITTER_MANIP> m_strFmt;
  Setting<EMITTER_MANIP> m_boolFmt;
  Setting<EMITTER_MANIP> m_boolLengthFmt;
  Setting<EMITTER_MANIP> m_boolCaseFmt;
  Setting<EMITTER_MANIP> m_nullFmt;
  Setting<EMITTER_MANIP> m_intFmt;
  Setting<std::size_t> m_indent;
  Setting<std::size_t> m_preCommentIndent, m_postCommentIndent;
  Setting<EMITTER_MANIP> m_seqFmt;
  Setting<EMITTER_MANIP> m_mapFmt;
  Setting<EMITTER_MANIP> m_mapKeyFmt;
  Setting<std::size_t> m_floatPrecision;
  Setting<std::size_t> m_doublePrecision;

  SettingChanges m_modifiedSettings;
  SettingChanges m_globalModifiedSettings;

  struct Group {
    explicit Group(GroupType::value type_)
        : type(type_),
          flowType{},
          indent(0),
          childCount(0),
          longKey(false),
          modifiedSettings{} {}

    GroupType::value type;
    FlowType::value flowType;
    std::size_t indent;
    std::size_t childCount;
    bool longKey;

    SettingChanges modifiedSettings;

    EmitterNodeType::value NodeType() const {
      if (type == GroupType::Seq) {
        if (flowType == FlowType::Flow)
          return EmitterNodeType::FlowSeq;
        else
          return EmitterNodeType::BlockSeq;
      } else {
        if (flowType == FlowType::Flow)
          return EmitterNodeType::FlowMap;
        else
          return EmitterNodeType::BlockMap;
      }

      // can't get here
      assert(false);
      return EmitterNodeType::NoType;
    }
  };

  std::vector<std::unique_ptr<Group>> m_groups;
  std::size_t m_curIndent;
  bool m_hasAnchor;
  bool m_hasAlias;
  bool m_hasTag;
  bool m_hasNonContent;
  std::size_t m_docCount;
};

template <typename T>
void EmitterState::_Set(Setting<T>& fmt, T value, FmtScope::value scope) {
  switch (scope) {
    case FmtScope::Local:
      m_modifiedSettings.push(fmt.set(value));
      break;
    case FmtScope::Global:
      fmt.set(value);
      m_globalModifiedSettings.push(
          fmt.set(value));  // this pushes an identity set, so when we restore,
      // it restores to the value here, and not the previous one
      break;
    default:
      assert(false);
  }
}
}  // namespace YAML

#endif  // EMITTERSTATE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/emitterstate.h ======

// Expanding include: yaml-cpp/emittermanip.h
// Expanding include: yaml-cpp/ostream_wrapper.h

namespace YAML {
class ostream_wrapper;
}  // namespace YAML

namespace YAML {
class Binary;

struct StringFormat {
  enum value { Plain, SingleQuoted, DoubleQuoted, Literal };
};

struct StringEscaping {
  enum value { None, NonAscii, JSON };
};

namespace Utils {
StringFormat::value ComputeStringFormat(const char* str, std::size_t size,
                                        EMITTER_MANIP strFormat,
                                        FlowType::value flowType,
                                        bool escapeNonAscii);

bool WriteSingleQuotedString(ostream_wrapper& out, const char* str, std::size_t size);
bool WriteDoubleQuotedString(ostream_wrapper& out, const char* str, std::size_t size,
                             StringEscaping::value stringEscaping);
bool WriteLiteralString(ostream_wrapper& out, const char* str, std::size_t size,
                        std::size_t indent);
bool WriteChar(ostream_wrapper& out, char ch,
               StringEscaping::value stringEscapingStyle);
bool WriteComment(ostream_wrapper& out, const char* str, std::size_t size,
                  std::size_t postCommentIndent);
bool WriteAlias(ostream_wrapper& out, const char* str, std::size_t size);
bool WriteAnchor(ostream_wrapper& out, const char* str, std::size_t size);
bool WriteTag(ostream_wrapper& out, const std::string& str, bool verbatim);
bool WriteTagWithPrefix(ostream_wrapper& out, const std::string& prefix,
                        const std::string& tag);
bool WriteBinary(ostream_wrapper& out, const Binary& binary);
}
}

#endif  // EMITTERUTILS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/emitterutils.h ======

// Expanding include: indentation.h

// ====== BEGIN yaml-cpp/src/indentation.h ======
#ifndef INDENTATION_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define INDENTATION_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <cstddef>

// Expanding include: yaml-cpp/ostream_wrapper.h

namespace YAML {
struct Indentation {
  Indentation(std::size_t n_) : n(n_) {}
  std::size_t n;
};

inline ostream_wrapper& operator<<(ostream_wrapper& out,
                                   const Indentation& indent) {
  for (std::size_t i = 0; i < indent.n; i++)
    out << ' ';
  return out;
}

struct IndentTo {
  IndentTo(std::size_t n_) : n(n_) {}
  std::size_t n;
};

inline ostream_wrapper& operator<<(ostream_wrapper& out,
                                   const IndentTo& indent) {
  while (out.col() < indent.n)
    out << ' ';
  return out;
}
}

#endif  // INDENTATION_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/indentation.h ======

// Expanding include: yaml-cpp/emitter.h
// Expanding include: yaml-cpp/emitterdef.h
// Expanding include: yaml-cpp/emittermanip.h
// Expanding include: yaml-cpp/exceptions.h

namespace YAML {
class Binary;
struct _Null;

Emitter::Emitter() : m_pState(new EmitterState), m_stream{} {}

Emitter::Emitter(std::ostream& stream)
    : m_pState(new EmitterState), m_stream(stream) {}

Emitter::~Emitter() = default;

const char* Emitter::c_str() const { return m_stream.str(); }

std::size_t Emitter::size() const { return m_stream.pos(); }

// state checking
bool Emitter::good() const { return m_pState->good(); }

const std::string Emitter::GetLastError() const {
  return m_pState->GetLastError();
}

// global setters
bool Emitter::SetOutputCharset(EMITTER_MANIP value) {
  return m_pState->SetOutputCharset(value, FmtScope::Global);
}

bool Emitter::SetStringFormat(EMITTER_MANIP value) {
  return m_pState->SetStringFormat(value, FmtScope::Global);
}

bool Emitter::SetBoolFormat(EMITTER_MANIP value) {
  bool ok = false;
  if (m_pState->SetBoolFormat(value, FmtScope::Global))
    ok = true;
  if (m_pState->SetBoolCaseFormat(value, FmtScope::Global))
    ok = true;
  if (m_pState->SetBoolLengthFormat(value, FmtScope::Global))
    ok = true;
  return ok;
}

bool Emitter::SetNullFormat(EMITTER_MANIP value) {
  return m_pState->SetNullFormat(value, FmtScope::Global);
}

bool Emitter::SetIntBase(EMITTER_MANIP value) {
  return m_pState->SetIntFormat(value, FmtScope::Global);
}

bool Emitter::SetSeqFormat(EMITTER_MANIP value) {
  return m_pState->SetFlowType(GroupType::Seq, value, FmtScope::Global);
}

bool Emitter::SetMapFormat(EMITTER_MANIP value) {
  bool ok = false;
  if (m_pState->SetFlowType(GroupType::Map, value, FmtScope::Global))
    ok = true;
  if (m_pState->SetMapKeyFormat(value, FmtScope::Global))
    ok = true;
  return ok;
}

bool Emitter::SetIndent(std::size_t n) {
  return m_pState->SetIndent(n, FmtScope::Global);
}

bool Emitter::SetPreCommentIndent(std::size_t n) {
  return m_pState->SetPreCommentIndent(n, FmtScope::Global);
}

bool Emitter::SetPostCommentIndent(std::size_t n) {
  return m_pState->SetPostCommentIndent(n, FmtScope::Global);
}

bool Emitter::SetFloatPrecision(std::size_t n) {
  return m_pState->SetFloatPrecision(n, FmtScope::Global);
}

bool Emitter::SetDoublePrecision(std::size_t n) {
  return m_pState->SetDoublePrecision(n, FmtScope::Global);
}

void Emitter::RestoreGlobalModifiedSettings() {
  m_pState->RestoreGlobalModifiedSettings();
}

// SetLocalValue
// . Either start/end a group, or set a modifier locally
Emitter& Emitter::SetLocalValue(EMITTER_MANIP value) {
  if (!good())
    return *this;

  switch (value) {
    case BeginDoc:
      EmitBeginDoc();
      break;
    case EndDoc:
      EmitEndDoc();
      break;
    case BeginSeq:
      EmitBeginSeq();
      break;
    case EndSeq:
      EmitEndSeq();
      break;
    case BeginMap:
      EmitBeginMap();
      break;
    case EndMap:
      EmitEndMap();
      break;
    case Key:
    case Value:
      // deprecated (these can be deduced by the parity of nodes in a map)
      break;
    case TagByKind:
      EmitKindTag();
      break;
    case Newline:
      EmitNewline();
      break;
    default:
      m_pState->SetLocalValue(value);
      break;
  }
  return *this;
}

Emitter& Emitter::SetLocalIndent(const _Indent& indent) {
  m_pState->SetIndent(indent.value, FmtScope::Local);
  return *this;
}

Emitter& Emitter::SetLocalPrecision(const _Precision& precision) {
  if (precision.floatPrecision >= 0)
    m_pState->SetFloatPrecision(precision.floatPrecision, FmtScope::Local);
  if (precision.doublePrecision >= 0)
    m_pState->SetDoublePrecision(precision.doublePrecision, FmtScope::Local);
  return *this;
}

// EmitBeginDoc
void Emitter::EmitBeginDoc() {
  if (!good())
    return;

  if (m_pState->CurGroupType() != GroupType::NoType) {
    m_pState->SetError("Unexpected begin document");
    return;
  }

  if (m_pState->HasAnchor() || m_pState->HasTag()) {
    m_pState->SetError("Unexpected begin document");
    return;
  }

  if (m_stream.col() > 0)
    m_stream << "\n";
  m_stream << "---\n";

  m_pState->StartedDoc();
}

// EmitEndDoc
void Emitter::EmitEndDoc() {
  if (!good())
    return;

  if (m_pState->CurGroupType() != GroupType::NoType) {
    m_pState->SetError("Unexpected begin document");
    return;
  }

  if (m_pState->HasAnchor() || m_pState->HasTag()) {
    m_pState->SetError("Unexpected begin document");
    return;
  }

  if (m_stream.col() > 0)
    m_stream << "\n";
  m_stream << "...\n";
}

// EmitBeginSeq
void Emitter::EmitBeginSeq() {
  if (!good())
    return;

  PrepareNode(m_pState->NextGroupType(GroupType::Seq));

  m_pState->StartedGroup(GroupType::Seq);
}

// EmitEndSeq
void Emitter::EmitEndSeq() {
  if (!good())
    return;
  FlowType::value originalType = m_pState->CurGroupFlowType();

  if (m_pState->CurGroupChildCount() == 0)
    m_pState->ForceFlow();

  if (m_pState->CurGroupFlowType() == FlowType::Flow) {
    if (m_stream.comment())
      m_stream << "\n";
    if (originalType == FlowType::Block || m_pState->HasBegunNode())
      m_stream << IndentTo(m_pState->CurIndent());
    if (originalType == FlowType::Block) {
      m_stream << "[";
    } else {
      if (m_pState->CurGroupChildCount() == 0 && !m_pState->HasBegunNode())
        m_stream << "[";
    }
    m_stream << "]";
  }

  m_pState->EndedGroup(GroupType::Seq);
}

// EmitBeginMap
void Emitter::EmitBeginMap() {
  if (!good())
    return;

  PrepareNode(m_pState->NextGroupType(GroupType::Map));

  m_pState->StartedGroup(GroupType::Map);
}

// EmitEndMap
void Emitter::EmitEndMap() {
  if (!good())
    return;
  FlowType::value originalType = m_pState->CurGroupFlowType();

  if (m_pState->CurGroupChildCount() == 0)
    m_pState->ForceFlow();

  if (m_pState->CurGroupFlowType() == FlowType::Flow) {
    if (m_stream.comment())
      m_stream << "\n";
    m_stream << IndentTo(m_pState->CurIndent());
    if (originalType == FlowType::Block) {
      m_stream << "{";
    } else {
      if (m_pState->CurGroupChildCount() == 0 && !m_pState->HasBegunNode())
        m_stream << "{";
    }
    m_stream << "}";
  }

  m_pState->EndedGroup(GroupType::Map);
}

// EmitNewline
void Emitter::EmitNewline() {
  if (!good())
    return;

  PrepareNode(EmitterNodeType::NoType);
  m_stream << "\n";
  m_pState->SetNonContent();
}

bool Emitter::CanEmitNewline() const { return true; }

// Put the stream in a state so we can simply write the next node
// E.g., if we're in a sequence, write the "- "
void Emitter::PrepareNode(EmitterNodeType::value child) {
  switch (m_pState->CurGroupNodeType()) {
    case EmitterNodeType::NoType:
      PrepareTopNode(child);
      break;
    case EmitterNodeType::FlowSeq:
      FlowSeqPrepareNode(child);
      break;
    case EmitterNodeType::BlockSeq:
      BlockSeqPrepareNode(child);
      break;
    case EmitterNodeType::FlowMap:
      FlowMapPrepareNode(child);
      break;
    case EmitterNodeType::BlockMap:
      BlockMapPrepareNode(child);
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
      assert(false);
      break;
  }
}

void Emitter::PrepareTopNode(EmitterNodeType::value child) {
  if (child == EmitterNodeType::NoType)
    return;

  if (m_pState->CurGroupChildCount() > 0 && m_stream.col() > 0)
    EmitBeginDoc();

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      // TODO: if we were writing null, and
      // we wanted it blank, we wouldn't want a space
      SpaceOrIndentTo(m_pState->HasBegunContent(), 0);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      if (m_pState->HasBegunNode())
        m_stream << "\n";
      break;
  }
}

void Emitter::FlowSeqPrepareNode(EmitterNodeType::value child) {
  const std::size_t lastIndent = m_pState->LastIndent();

  if (!m_pState->HasBegunNode()) {
    if (m_stream.comment())
      m_stream << "\n";
    m_stream << IndentTo(lastIndent);
    if (m_pState->CurGroupChildCount() == 0)
      m_stream << "[";
    else
      m_stream << ",";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(
          m_pState->HasBegunContent() || m_pState->CurGroupChildCount() > 0,
          lastIndent);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      assert(false);
      break;
  }
}

void Emitter::BlockSeqPrepareNode(EmitterNodeType::value child) {
  const std::size_t curIndent = m_pState->CurIndent();
  const std::size_t nextIndent = curIndent + m_pState->CurGroupIndent();

  if (child == EmitterNodeType::NoType)
    return;

  if (!m_pState->HasBegunContent()) {
    if (m_pState->CurGroupChildCount() > 0 || m_stream.comment()) {
      m_stream << "\n";
    }
    m_stream << IndentTo(curIndent);
    m_stream << "-";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(m_pState->HasBegunContent(), nextIndent);
      break;
    case EmitterNodeType::BlockSeq:
      m_stream << "\n";
      break;
    case EmitterNodeType::BlockMap:
      if (m_pState->HasBegunContent() || m_stream.comment())
        m_stream << "\n";
      break;
  }
}

void Emitter::FlowMapPrepareNode(EmitterNodeType::value child) {
  if (m_pState->CurGroupChildCount() % 2 == 0) {
    if (m_pState->GetMapKeyFormat() == LongKey)
      m_pState->SetLongKey();

    if (m_pState->CurGroupLongKey())
      FlowMapPrepareLongKey(child);
    else
      FlowMapPrepareSimpleKey(child);
  } else {
    if (m_pState->CurGroupLongKey())
      FlowMapPrepareLongKeyValue(child);
    else
      FlowMapPrepareSimpleKeyValue(child);
  }
}

void Emitter::FlowMapPrepareLongKey(EmitterNodeType::value child) {
  const std::size_t lastIndent = m_pState->LastIndent();

  if (!m_pState->HasBegunNode()) {
    if (m_stream.comment())
      m_stream << "\n";
    m_stream << IndentTo(lastIndent);
    if (m_pState->CurGroupChildCount() == 0)
      m_stream << "{ ?";
    else
      m_stream << ", ?";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(
          m_pState->HasBegunContent() || m_pState->CurGroupChildCount() > 0,
          lastIndent);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      assert(false);
      break;
  }
}

void Emitter::FlowMapPrepareLongKeyValue(EmitterNodeType::value child) {
  const std::size_t lastIndent = m_pState->LastIndent();

  if (!m_pState->HasBegunNode()) {
    if (m_stream.comment())
      m_stream << "\n";
    m_stream << IndentTo(lastIndent);
    m_stream << ":";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(
          m_pState->HasBegunContent() || m_pState->CurGroupChildCount() > 0,
          lastIndent);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      assert(false);
      break;
  }
}

void Emitter::FlowMapPrepareSimpleKey(EmitterNodeType::value child) {
  const std::size_t lastIndent = m_pState->LastIndent();

  if (!m_pState->HasBegunNode()) {
    if (m_stream.comment())
      m_stream << "\n";
    m_stream << IndentTo(lastIndent);
    if (m_pState->CurGroupChildCount() == 0)
      m_stream << "{";
    else
      m_stream << ",";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(
          m_pState->HasBegunContent() || m_pState->CurGroupChildCount() > 0,
          lastIndent);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      assert(false);
      break;
  }
}

void Emitter::FlowMapPrepareSimpleKeyValue(EmitterNodeType::value child) {
  const std::size_t lastIndent = m_pState->LastIndent();

  if (!m_pState->HasBegunNode()) {
    if (m_stream.comment())
      m_stream << "\n";
    m_stream << IndentTo(lastIndent);
    if (m_pState->HasAlias()) {
      m_stream << " ";
    }
    m_stream << ":";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(
          m_pState->HasBegunContent() || m_pState->CurGroupChildCount() > 0,
          lastIndent);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      assert(false);
      break;
  }
}

void Emitter::BlockMapPrepareNode(EmitterNodeType::value child) {
  if (m_pState->CurGroupChildCount() % 2 == 0) {
    if (m_pState->GetMapKeyFormat() == LongKey)
      m_pState->SetLongKey();
    if (child == EmitterNodeType::BlockSeq ||
        child == EmitterNodeType::BlockMap ||
        child == EmitterNodeType::Property)
      m_pState->SetLongKey();

    if (m_pState->CurGroupLongKey())
      BlockMapPrepareLongKey(child);
    else
      BlockMapPrepareSimpleKey(child);
  } else {
    if (m_pState->CurGroupLongKey())
      BlockMapPrepareLongKeyValue(child);
    else
      BlockMapPrepareSimpleKeyValue(child);
  }
}

void Emitter::BlockMapPrepareLongKey(EmitterNodeType::value child) {
  const std::size_t curIndent = m_pState->CurIndent();
  const std::size_t childCount = m_pState->CurGroupChildCount();

  if (child == EmitterNodeType::NoType)
    return;

  if (!m_pState->HasBegunContent()) {
    if (childCount > 0) {
      m_stream << "\n";
    }
    if (m_stream.comment()) {
      m_stream << "\n";
    }
    m_stream << IndentTo(curIndent);
    m_stream << "?";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(true, curIndent + 1);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      if (m_pState->HasBegunContent())
        m_stream << "\n";
      break;
  }
}

void Emitter::BlockMapPrepareLongKeyValue(EmitterNodeType::value child) {
  const std::size_t curIndent = m_pState->CurIndent();

  if (child == EmitterNodeType::NoType)
    return;

  if (!m_pState->HasBegunContent()) {
    m_stream << "\n";
    m_stream << IndentTo(curIndent);
    m_stream << ":";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(true, curIndent + 1);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      if (m_pState->HasBegunContent())
        m_stream << "\n";
      SpaceOrIndentTo(true, curIndent + 1);
      break;
  }
}

void Emitter::BlockMapPrepareSimpleKey(EmitterNodeType::value child) {
  const std::size_t curIndent = m_pState->CurIndent();
  const std::size_t childCount = m_pState->CurGroupChildCount();

  if (child == EmitterNodeType::NoType)
    return;

  if (!m_pState->HasBegunNode()) {
    if (childCount > 0) {
      m_stream << "\n";
    }
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(m_pState->HasBegunContent(), curIndent);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      break;
  }
}

void Emitter::BlockMapPrepareSimpleKeyValue(EmitterNodeType::value child) {
  const std::size_t curIndent = m_pState->CurIndent();
  const std::size_t nextIndent = curIndent + m_pState->CurGroupIndent();

  if (!m_pState->HasBegunNode()) {
    if (m_pState->HasAlias()) {
      m_stream << " ";
    }
    m_stream << ":";
  }

  switch (child) {
    case EmitterNodeType::NoType:
      break;
    case EmitterNodeType::Property:
    case EmitterNodeType::Scalar:
    case EmitterNodeType::FlowSeq:
    case EmitterNodeType::FlowMap:
      SpaceOrIndentTo(true, nextIndent);
      break;
    case EmitterNodeType::BlockSeq:
    case EmitterNodeType::BlockMap:
      m_stream << "\n";
      break;
  }
}

// SpaceOrIndentTo
// . Prepares for some more content by proper spacing
void Emitter::SpaceOrIndentTo(bool requireSpace, std::size_t indent) {
  if (m_stream.comment())
    m_stream << "\n";
  if (m_stream.col() > 0 && requireSpace)
    m_stream << " ";
  m_stream << IndentTo(indent);
}

void Emitter::PrepareIntegralStream(std::stringstream& stream) const {

  switch (m_pState->GetIntFormat()) {
    case Dec:
      stream << std::dec;
      break;
    case Hex:
      stream << "0x";
      stream << std::hex;
      break;
    case Oct:
      stream << "0";
      stream << std::oct;
      break;
    default:
      assert(false);
  }
}

void Emitter::StartedScalar() { m_pState->StartedScalar(); }

// *******************************************************************************************
// overloads of Write

StringEscaping::value GetStringEscapingStyle(const EMITTER_MANIP emitterManip) {
  switch (emitterManip) {
    case EscapeNonAscii:
      return StringEscaping::NonAscii;
    case EscapeAsJson:
      return StringEscaping::JSON;
    default:
      return StringEscaping::None;
      break;
  }
}

Emitter& Emitter::Write(const char* str, std::size_t size) {
  if (!good())
    return *this;

  StringEscaping::value stringEscaping = GetStringEscapingStyle(m_pState->GetOutputCharset());

  const StringFormat::value strFormat =
      Utils::ComputeStringFormat(str, size, m_pState->GetStringFormat(),
                                 m_pState->CurGroupFlowType(), stringEscaping == StringEscaping::NonAscii);

  if (strFormat == StringFormat::Literal || size > 1024)
    m_pState->SetMapKeyFormat(YAML::LongKey, FmtScope::Local);

  PrepareNode(EmitterNodeType::Scalar);

  switch (strFormat) {
    case StringFormat::Plain:
      m_stream.write(str, size);
      break;
    case StringFormat::SingleQuoted:
      Utils::WriteSingleQuotedString(m_stream, str, size);
      break;
    case StringFormat::DoubleQuoted:
      Utils::WriteDoubleQuotedString(m_stream, str, size, stringEscaping);
      break;
    case StringFormat::Literal:
      Utils::WriteLiteralString(m_stream, str, size,
                                m_pState->CurIndent() + m_pState->GetIndent());
      break;
  }

  StartedScalar();

  return *this;
}

Emitter& Emitter::Write(const std::string& str) {
  return Write(str.data(), str.size());
}

std::size_t Emitter::GetFloatPrecision() const {
  return m_pState->GetFloatPrecision();
}

std::size_t Emitter::GetDoublePrecision() const {
  return m_pState->GetDoublePrecision();
}

const char* Emitter::ComputeFullBoolName(bool b) const {
  const EMITTER_MANIP mainFmt = (m_pState->GetBoolLengthFormat() == ShortBool
                                     ? YesNoBool
                                     : m_pState->GetBoolFormat());
  const EMITTER_MANIP caseFmt = m_pState->GetBoolCaseFormat();
  switch (mainFmt) {
    case YesNoBool:
      switch (caseFmt) {
        case UpperCase:
          return b ? "YES" : "NO";
        case CamelCase:
          return b ? "Yes" : "No";
        case LowerCase:
          return b ? "yes" : "no";
        default:
          break;
      }
      break;
    case OnOffBool:
      switch (caseFmt) {
        case UpperCase:
          return b ? "ON" : "OFF";
        case CamelCase:
          return b ? "On" : "Off";
        case LowerCase:
          return b ? "on" : "off";
        default:
          break;
      }
      break;
    case TrueFalseBool:
      switch (caseFmt) {
        case UpperCase:
          return b ? "TRUE" : "FALSE";
        case CamelCase:
          return b ? "True" : "False";
        case LowerCase:
          return b ? "true" : "false";
        default:
          break;
      }
      break;
    default:
      break;
  }
  return b ? "y" : "n";  // should never get here, but it can't hurt to give
                         // these answers
}

const char* Emitter::ComputeNullName() const {
  switch (m_pState->GetNullFormat()) {
    case LowerNull:
      return "null";
    case UpperNull:
      return "NULL";
    case CamelNull:
      return "Null";
    case TildeNull:
      // fallthrough
    default:
      return "~";
  }
}

Emitter& Emitter::Write(bool b) {
  if (!good())
    return *this;

  PrepareNode(EmitterNodeType::Scalar);

  const char* name = ComputeFullBoolName(b);
  if (m_pState->GetBoolLengthFormat() == ShortBool)
    m_stream << name[0];
  else
    m_stream << name;

  StartedScalar();

  return *this;
}

Emitter& Emitter::Write(char ch) {
  if (!good())
    return *this;



  PrepareNode(EmitterNodeType::Scalar);
  Utils::WriteChar(m_stream, ch, GetStringEscapingStyle(m_pState->GetOutputCharset()));
  StartedScalar();

  return *this;
}

Emitter& Emitter::Write(const _Alias& alias) {
  if (!good())
    return *this;

  if (m_pState->HasAnchor() || m_pState->HasTag()) {
    m_pState->SetError(ErrorMsg::INVALID_ALIAS);
    return *this;
  }

  PrepareNode(EmitterNodeType::Scalar);

  if (!Utils::WriteAlias(m_stream, alias.content.data(), alias.content.size())) {
    m_pState->SetError(ErrorMsg::INVALID_ALIAS);
    return *this;
  }

  StartedScalar();

  m_pState->SetAlias();

  return *this;
}

Emitter& Emitter::Write(const _Anchor& anchor) {
  if (!good())
    return *this;

  if (m_pState->HasAnchor()) {
    m_pState->SetError(ErrorMsg::INVALID_ANCHOR);
    return *this;
  }

  PrepareNode(EmitterNodeType::Property);

  if (!Utils::WriteAnchor(m_stream, anchor.content.data(), anchor.content.size())) {
    m_pState->SetError(ErrorMsg::INVALID_ANCHOR);
    return *this;
  }

  m_pState->SetAnchor();

  return *this;
}

Emitter& Emitter::Write(const _Tag& tag) {
  if (!good())
    return *this;

  if (m_pState->HasTag()) {
    m_pState->SetError(ErrorMsg::INVALID_TAG);
    return *this;
  }

  PrepareNode(EmitterNodeType::Property);

  bool success = false;
  if (tag.type == _Tag::Type::Verbatim)
    success = Utils::WriteTag(m_stream, tag.content, true);
  else if (tag.type == _Tag::Type::PrimaryHandle)
    success = Utils::WriteTag(m_stream, tag.content, false);
  else
    success = Utils::WriteTagWithPrefix(m_stream, tag.prefix, tag.content);

  if (!success) {
    m_pState->SetError(ErrorMsg::INVALID_TAG);
    return *this;
  }

  m_pState->SetTag();

  return *this;
}

void Emitter::EmitKindTag() { Write(LocalTag("")); }

Emitter& Emitter::Write(const _Comment& comment) {
  if (!good())
    return *this;

  PrepareNode(EmitterNodeType::NoType);

  if (m_stream.col() > 0)
    m_stream << Indentation(m_pState->GetPreCommentIndent());
  Utils::WriteComment(m_stream, comment.content.data(), comment.content.size(),
                      m_pState->GetPostCommentIndent());

  m_pState->SetNonContent();

  return *this;
}

Emitter& Emitter::Write(const _Null& /*null*/) {
  if (!good())
    return *this;

  PrepareNode(EmitterNodeType::Scalar);

  m_stream << ComputeNullName();

  StartedScalar();

  return *this;
}

Emitter& Emitter::Write(const Binary& binary) {
  Write(SecondaryTag("binary"));

  if (!good())
    return *this;

  PrepareNode(EmitterNodeType::Scalar);
  Utils::WriteBinary(m_stream, binary);
  StartedScalar();

  return *this;
}
}  // namespace YAML
// ====== END yaml-cpp/src/emitter.cpp ======


// ====== BEGIN yaml-cpp/src/emitterstate.cpp ======
#include <limits>

// Expanding include: emitterstate.h
// Expanding include: yaml-cpp/exceptions.h

namespace YAML {
EmitterState::EmitterState()
    : m_isGood(true),
      m_lastError{},
      // default global manipulators
      m_charset(EmitNonAscii),
      m_strFmt(Auto),
      m_boolFmt(TrueFalseBool),
      m_boolLengthFmt(LongBool),
      m_boolCaseFmt(LowerCase),
      m_nullFmt(TildeNull),
      m_intFmt(Dec),
      m_indent(2),
      m_preCommentIndent(2),
      m_postCommentIndent(1),
      m_seqFmt(Block),
      m_mapFmt(Block),
      m_mapKeyFmt(Auto),
      m_floatPrecision(std::numeric_limits<float>::max_digits10),
      m_doublePrecision(std::numeric_limits<double>::max_digits10),
      //
      m_modifiedSettings{},
      m_globalModifiedSettings{},
      m_groups{},
      m_curIndent(0),
      m_hasAnchor(false),
      m_hasAlias(false),
      m_hasTag(false),
      m_hasNonContent(false),
      m_docCount(0) {}

EmitterState::~EmitterState() = default;

// SetLocalValue
// . We blindly tries to set all possible formatters to this value
// . Only the ones that make sense will be accepted
void EmitterState::SetLocalValue(EMITTER_MANIP value) {
  SetOutputCharset(value, FmtScope::Local);
  SetStringFormat(value, FmtScope::Local);
  SetBoolFormat(value, FmtScope::Local);
  SetBoolCaseFormat(value, FmtScope::Local);
  SetBoolLengthFormat(value, FmtScope::Local);
  SetNullFormat(value, FmtScope::Local);
  SetIntFormat(value, FmtScope::Local);
  SetFlowType(GroupType::Seq, value, FmtScope::Local);
  SetFlowType(GroupType::Map, value, FmtScope::Local);
  SetMapKeyFormat(value, FmtScope::Local);
}

void EmitterState::SetAnchor() { m_hasAnchor = true; }

void EmitterState::SetAlias() { m_hasAlias = true; }

void EmitterState::SetTag() { m_hasTag = true; }

void EmitterState::SetNonContent() { m_hasNonContent = true; }

void EmitterState::SetLongKey() {
  assert(!m_groups.empty());
  if (m_groups.empty()) {
    return;
  }

  assert(m_groups.back()->type == GroupType::Map);
  m_groups.back()->longKey = true;
}

void EmitterState::ForceFlow() {
  assert(!m_groups.empty());
  if (m_groups.empty()) {
    return;
  }

  m_groups.back()->flowType = FlowType::Flow;
}

void EmitterState::StartedNode() {
  if (m_groups.empty()) {
    m_docCount++;
  } else {
    m_groups.back()->childCount++;
    if (m_groups.back()->childCount % 2 == 0) {
      m_groups.back()->longKey = false;
    }
  }

  m_hasAnchor = false;
  m_hasAlias = false;
  m_hasTag = false;
  m_hasNonContent = false;
}

EmitterNodeType::value EmitterState::NextGroupType(
    GroupType::value type) const {
  if (type == GroupType::Seq) {
    if (GetFlowType(type) == Block)
      return EmitterNodeType::BlockSeq;
    return EmitterNodeType::FlowSeq;
  }

  if (GetFlowType(type) == Block)
    return EmitterNodeType::BlockMap;
  return EmitterNodeType::FlowMap;

  // can't happen
  assert(false);
  return EmitterNodeType::NoType;
}

void EmitterState::StartedDoc() {
  m_hasAnchor = false;
  m_hasTag = false;
  m_hasNonContent = false;
}

void EmitterState::EndedDoc() {
  m_hasAnchor = false;
  m_hasTag = false;
  m_hasNonContent = false;
}

void EmitterState::StartedScalar() {
  StartedNode();
  ClearModifiedSettings();
}

void EmitterState::StartedGroup(GroupType::value type) {
  StartedNode();

  const std::size_t lastGroupIndent =
      (m_groups.empty() ? 0 : m_groups.back()->indent);
  m_curIndent += lastGroupIndent;

  // TODO: Create move constructors for settings types to simplify transfer
  std::unique_ptr<Group> pGroup(new Group(type));

  // transfer settings (which last until this group is done)
  //
  // NB: if pGroup->modifiedSettings == m_modifiedSettings,
  // m_modifiedSettings is not changed!
  pGroup->modifiedSettings = std::move(m_modifiedSettings);

  // set up group
  if (GetFlowType(type) == Block) {
    pGroup->flowType = FlowType::Block;
  } else {
    pGroup->flowType = FlowType::Flow;
  }
  pGroup->indent = GetIndent();

  m_groups.push_back(std::move(pGroup));
}

void EmitterState::EndedGroup(GroupType::value type) {
  if (m_groups.empty()) {
    if (type == GroupType::Seq) {
      return SetError(ErrorMsg::UNEXPECTED_END_SEQ);
    }
    return SetError(ErrorMsg::UNEXPECTED_END_MAP);
  }

  if (m_hasTag) {
    SetError(ErrorMsg::INVALID_TAG);
  }
  if (m_hasAnchor) {
    SetError(ErrorMsg::INVALID_ANCHOR);
  }

  // get rid of the current group
  {
    std::unique_ptr<Group> pFinishedGroup = std::move(m_groups.back());
    m_groups.pop_back();
    if (pFinishedGroup->type != type) {
      return SetError(ErrorMsg::UNMATCHED_GROUP_TAG);
    }
  }

  // reset old settings
  std::size_t lastIndent = (m_groups.empty() ? 0 : m_groups.back()->indent);
  assert(m_curIndent >= lastIndent);
  m_curIndent -= lastIndent;

  // some global settings that we changed may have been overridden
  // by a local setting we just popped, so we need to restore them
  m_globalModifiedSettings.restore();

  ClearModifiedSettings();
  m_hasAnchor = false;
  m_hasTag = false;
  m_hasNonContent = false;
}

EmitterNodeType::value EmitterState::CurGroupNodeType() const {
  if (m_groups.empty()) {
    return EmitterNodeType::NoType;
  }

  return m_groups.back()->NodeType();
}

GroupType::value EmitterState::CurGroupType() const {
  return m_groups.empty() ? GroupType::NoType : m_groups.back()->type;
}

FlowType::value EmitterState::CurGroupFlowType() const {
  return m_groups.empty() ? FlowType::NoType : m_groups.back()->flowType;
}

std::size_t EmitterState::CurGroupIndent() const {
  return m_groups.empty() ? 0 : m_groups.back()->indent;
}

std::size_t EmitterState::CurGroupChildCount() const {
  return m_groups.empty() ? m_docCount : m_groups.back()->childCount;
}

bool EmitterState::CurGroupLongKey() const {
  return m_groups.empty() ? false : m_groups.back()->longKey;
}

std::size_t EmitterState::LastIndent() const {
  if (m_groups.size() <= 1) {
    return 0;
  }

  return m_curIndent - m_groups[m_groups.size() - 2]->indent;
}

void EmitterState::ClearModifiedSettings() { m_modifiedSettings.clear(); }

void EmitterState::RestoreGlobalModifiedSettings() {
  m_globalModifiedSettings.restore();
}

bool EmitterState::SetOutputCharset(EMITTER_MANIP value,
                                    FmtScope::value scope) {
  switch (value) {
    case EmitNonAscii:
    case EscapeNonAscii:
    case EscapeAsJson:
      _Set(m_charset, value, scope);
      return true;
    default:
      return false;
  }
}

bool EmitterState::SetStringFormat(EMITTER_MANIP value, FmtScope::value scope) {
  switch (value) {
    case Auto:
    case SingleQuoted:
    case DoubleQuoted:
    case Literal:
      _Set(m_strFmt, value, scope);
      return true;
    default:
      return false;
  }
}

bool EmitterState::SetBoolFormat(EMITTER_MANIP value, FmtScope::value scope) {
  switch (value) {
    case OnOffBool:
    case TrueFalseBool:
    case YesNoBool:
      _Set(m_boolFmt, value, scope);
      return true;
    default:
      return false;
  }
}

bool EmitterState::SetBoolLengthFormat(EMITTER_MANIP value,
                                       FmtScope::value scope) {
  switch (value) {
    case LongBool:
    case ShortBool:
      _Set(m_boolLengthFmt, value, scope);
      return true;
    default:
      return false;
  }
}

bool EmitterState::SetBoolCaseFormat(EMITTER_MANIP value,
                                     FmtScope::value scope) {
  switch (value) {
    case UpperCase:
    case LowerCase:
    case CamelCase:
      _Set(m_boolCaseFmt, value, scope);
      return true;
    default:
      return false;
  }
}

bool EmitterState::SetNullFormat(EMITTER_MANIP value, FmtScope::value scope) {
  switch (value) {
    case LowerNull:
    case UpperNull:
    case CamelNull:
    case TildeNull:
      _Set(m_nullFmt, value, scope);
      return true;
    default:
      return false;
  }
}

bool EmitterState::SetIntFormat(EMITTER_MANIP value, FmtScope::value scope) {
  switch (value) {
    case Dec:
    case Hex:
    case Oct:
      _Set(m_intFmt, value, scope);
      return true;
    default:
      return false;
  }
}

bool EmitterState::SetIndent(std::size_t value, FmtScope::value scope) {
  if (value <= 1)
    return false;

  _Set(m_indent, value, scope);
  return true;
}

bool EmitterState::SetPreCommentIndent(std::size_t value,
                                       FmtScope::value scope) {
  if (value == 0)
    return false;

  _Set(m_preCommentIndent, value, scope);
  return true;
}

bool EmitterState::SetPostCommentIndent(std::size_t value,
                                        FmtScope::value scope) {
  if (value == 0)
    return false;

  _Set(m_postCommentIndent, value, scope);
  return true;
}

bool EmitterState::SetFlowType(GroupType::value groupType, EMITTER_MANIP value,
                               FmtScope::value scope) {
  switch (value) {
    case Block:
    case Flow:
      _Set(groupType == GroupType::Seq ? m_seqFmt : m_mapFmt, value, scope);
      return true;
    default:
      return false;
  }
}

EMITTER_MANIP EmitterState::GetFlowType(GroupType::value groupType) const {
  // force flow style if we're currently in a flow
  if (CurGroupFlowType() == FlowType::Flow)
    return Flow;

  // otherwise, go with what's asked of us
  return (groupType == GroupType::Seq ? m_seqFmt.get() : m_mapFmt.get());
}

bool EmitterState::SetMapKeyFormat(EMITTER_MANIP value, FmtScope::value scope) {
  switch (value) {
    case Auto:
    case LongKey:
      _Set(m_mapKeyFmt, value, scope);
      return true;
    default:
      return false;
  }
}

bool EmitterState::SetFloatPrecision(std::size_t value, FmtScope::value scope) {
  if (value > std::numeric_limits<float>::max_digits10)
    return false;
  _Set(m_floatPrecision, value, scope);
  return true;
}

bool EmitterState::SetDoublePrecision(std::size_t value,
                                      FmtScope::value scope) {
  if (value > std::numeric_limits<double>::max_digits10)
    return false;
  _Set(m_doublePrecision, value, scope);
  return true;
}
}  // namespace YAML
// ====== END yaml-cpp/src/emitterstate.cpp ======


// ====== BEGIN yaml-cpp/src/emitterutils.cpp ======
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <sstream>

// Expanding include: emitterutils.h
// Expanding include: exp.h

// ====== BEGIN yaml-cpp/src/exp.h ======
#ifndef EXP_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EXP_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <ios>
#include <string>

// Expanding include: regex_yaml.h

// ====== BEGIN yaml-cpp/src/regex_yaml.h ======
#ifndef REGEX_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define REGEX_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>
#include <vector>

// Expanding include: yaml-cpp/dll.h

namespace YAML {
class Stream;

enum REGEX_OP {
  REGEX_EMPTY,
  REGEX_MATCH,
  REGEX_RANGE,
  REGEX_OR,
  REGEX_AND,
  REGEX_NOT,
  REGEX_SEQ
};

// simplified regular expressions
// . Only straightforward matches (no repeated characters)
// . Only matches from start of string
class YAML_CPP_API RegEx {
 public:
  RegEx();
  explicit RegEx(char ch);
  RegEx(char a, char z);
  RegEx(const std::string& str, REGEX_OP op = REGEX_SEQ);
  ~RegEx() = default;

  friend YAML_CPP_API RegEx operator!(const RegEx& ex);
  friend YAML_CPP_API RegEx operator|(const RegEx& ex1, const RegEx& ex2);
  friend YAML_CPP_API RegEx operator&(const RegEx& ex1, const RegEx& ex2);
  friend YAML_CPP_API RegEx operator+(const RegEx& ex1, const RegEx& ex2);

  bool Matches(char ch) const;
  bool Matches(const std::string& str) const;
  bool Matches(const Stream& in) const;
  template <typename Source>
  bool Matches(const Source& source) const;

  int Match(const std::string& str) const;
  int Match(const Stream& in) const;
  template <typename Source>
  int Match(const Source& source) const;

 private:
  explicit RegEx(REGEX_OP op);

  template <typename Source>
  bool IsValidSource(const Source& source) const;
  template <typename Source>
  int MatchUnchecked(const Source& source) const;

  template <typename Source>
  int MatchOpEmpty(const Source& source) const;
  template <typename Source>
  int MatchOpMatch(const Source& source) const;
  template <typename Source>
  int MatchOpRange(const Source& source) const;
  template <typename Source>
  int MatchOpOr(const Source& source) const;
  template <typename Source>
  int MatchOpAnd(const Source& source) const;
  template <typename Source>
  int MatchOpNot(const Source& source) const;
  template <typename Source>
  int MatchOpSeq(const Source& source) const;

 private:
  REGEX_OP m_op;
  char m_a{};
  char m_z{};
  std::vector<RegEx> m_params;
};
}  // namespace YAML

// Expanding include: regeximpl.h

// ====== BEGIN yaml-cpp/src/regeximpl.h ======
#ifndef REGEXIMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define REGEXIMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: stream.h

// ====== BEGIN yaml-cpp/src/stream.h ======
#ifndef STREAM_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define STREAM_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/mark.h
#include <cstddef>
#include <deque>
#include <ios>
#include <istream>
#include <set>
#include <string>

namespace YAML {

class StreamCharSource;

class Stream {
 public:
  friend class StreamCharSource;

  Stream(std::istream& input);
  Stream(const Stream&) = delete;
  Stream(Stream&&) = delete;
  Stream& operator=(const Stream&) = delete;
  Stream& operator=(Stream&&) = delete;
  ~Stream();

  operator bool() const;
  bool operator!() const { return !static_cast<bool>(*this); }

  char peek() const;
  char get();
  std::string get(int n);
  void eat(int n = 1);

  static char eof() { return 0x04; }

  const Mark mark() const { return m_mark; }
  int pos() const { return m_mark.pos; }
  int line() const { return m_mark.line; }
  int column() const { return m_mark.column; }
  void ResetColumn() { m_mark.column = 0; }

 private:
  enum CharacterSet { utf8, utf16le, utf16be, utf32le, utf32be };

  std::istream& m_input;
  Mark m_mark;

  CharacterSet m_charSet;
  char m_lineEndingSymbol{}; // 0 means it is not determined yet, must be '\n' or '\r'
  mutable std::deque<char> m_readahead;
  unsigned char* const m_pPrefetched;
  mutable size_t m_nPrefetchedAvailable;
  mutable size_t m_nPrefetchedUsed;

  void AdvanceCurrent();
  char CharAt(size_t i) const;
  bool ReadAheadTo(size_t i) const;
  bool _ReadAheadTo(size_t i) const;
  void StreamInUtf8() const;
  void StreamInUtf16() const;
  void StreamInUtf32() const;
  unsigned char GetNextByte() const;
};

// CharAt
// . Unchecked access
inline char Stream::CharAt(size_t i) const { return m_readahead[i]; }

inline bool Stream::ReadAheadTo(size_t i) const {
  if (m_readahead.size() > i)
    return true;
  return _ReadAheadTo(i);
}
}  // namespace YAML

#endif  // STREAM_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/stream.h ======

// Expanding include: streamcharsource.h

// ====== BEGIN yaml-cpp/src/streamcharsource.h ======
#ifndef STREAMCHARSOURCE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define STREAMCHARSOURCE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/noexcept.h
// Expanding include: stream.h
#include <cstddef>

namespace YAML {

class StreamCharSource {
 public:
  StreamCharSource(const Stream& stream) : m_offset(0), m_stream(stream) {}
  StreamCharSource(const StreamCharSource& source) = default;
  StreamCharSource(StreamCharSource&&) YAML_CPP_NOEXCEPT = default;
  StreamCharSource& operator=(const StreamCharSource&) = delete;
  StreamCharSource& operator=(StreamCharSource&&) = delete;
  ~StreamCharSource() = default;

  operator bool() const;
  char operator[](std::size_t i) const { return m_stream.CharAt(m_offset + i); }
  bool operator!() const { return !static_cast<bool>(*this); }

  const StreamCharSource operator+(int i) const;

 private:
  std::size_t m_offset;
  const Stream& m_stream;
};

inline StreamCharSource::operator bool() const {
  return m_stream.ReadAheadTo(m_offset);
}

inline const StreamCharSource StreamCharSource::operator+(int i) const {
  StreamCharSource source(*this);
  if (static_cast<int>(source.m_offset) + i >= 0)
    source.m_offset += static_cast<std::size_t>(i);
  else
    source.m_offset = 0;
  return source;
}
}  // namespace YAML

#endif  // STREAMCHARSOURCE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/streamcharsource.h ======

// Expanding include: stringsource.h

// ====== BEGIN yaml-cpp/src/stringsource.h ======
#ifndef STRINGSOURCE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define STRINGSOURCE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <cstddef>

namespace YAML {
class StringCharSource {
 public:
  StringCharSource(const char* str, std::size_t size)
      : m_str(str), m_size(size), m_offset(0) {}

  operator bool() const { return m_offset < m_size; }
  char operator[](std::size_t i) const { return m_str[m_offset + i]; }
  bool operator!() const { return !static_cast<bool>(*this); }

  const StringCharSource operator+(int i) const {
    StringCharSource source(*this);
    if (static_cast<int>(source.m_offset) + i >= 0)
      source.m_offset += i;
    else
      source.m_offset = 0;
    return source;
  }

  StringCharSource& operator++() {
    ++m_offset;
    return *this;
  }

  StringCharSource& operator+=(std::size_t offset) {
    m_offset += offset;
    return *this;
  }

 private:
  const char* m_str;
  std::size_t m_size;
  std::size_t m_offset;
};
}

#endif  // STRINGSOURCE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/stringsource.h ======


namespace YAML {
// query matches
inline bool RegEx::Matches(char ch) const {
  std::string str;
  str += ch;
  return Matches(str);
}

inline bool RegEx::Matches(const std::string& str) const {
  return Match(str) >= 0;
}

inline bool RegEx::Matches(const Stream& in) const { return Match(in) >= 0; }

template <typename Source>
inline bool RegEx::Matches(const Source& source) const {
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201103L) || __cplusplus >= 201103L)
  static_assert(!std::is_same<Source, const char*>::value,
#endif
    "Must use StringCharSource instead of plain C-string");
  return Match(source) >= 0;
}

// Match
// . Matches the given string against this regular expression.
// . Returns the number of characters matched.
// . Returns -1 if no characters were matched (the reason for
//   not returning zero is that we may have an empty regex
//   which is ALWAYS successful at matching zero characters).
// . REMEMBER that we only match from the start of the buffer!
inline int RegEx::Match(const std::string& str) const {
  StringCharSource source(str.c_str(), str.size());
  return Match(source);
}

inline int RegEx::Match(const Stream& in) const {
  StreamCharSource source(in);
  return Match(source);
}

template <typename Source>
inline bool RegEx::IsValidSource(const Source& source) const {
  return source;
}

template <>
inline bool RegEx::IsValidSource<StringCharSource>(
    const StringCharSource& source) const {
  switch (m_op) {
    case REGEX_MATCH:
    case REGEX_RANGE:
      return source;
    default:
      return true;
  }
}

template <typename Source>
inline int RegEx::Match(const Source& source) const {
  return IsValidSource(source) ? MatchUnchecked(source) : -1;
}

template <typename Source>
inline int RegEx::MatchUnchecked(const Source& source) const {
  switch (m_op) {
    case REGEX_EMPTY:
      return MatchOpEmpty(source);
    case REGEX_MATCH:
      return MatchOpMatch(source);
    case REGEX_RANGE:
      return MatchOpRange(source);
    case REGEX_OR:
      return MatchOpOr(source);
    case REGEX_AND:
      return MatchOpAnd(source);
    case REGEX_NOT:
      return MatchOpNot(source);
    case REGEX_SEQ:
      return MatchOpSeq(source);
  }

  return -1;
}

//////////////////////////////////////////////////////////////////////////////
// Operators
// Note: the convention MatchOp*<Source> is that we can assume
// IsSourceValid(source).
//       So we do all our checks *before* we call these functions

// EmptyOperator
template <typename Source>
inline int RegEx::MatchOpEmpty(const Source& source) const {
  return source[0] == Stream::eof() ? 0 : -1;
}

template <>
inline int RegEx::MatchOpEmpty<StringCharSource>(
    const StringCharSource& source) const {
  return !source ? 0 : -1;  // the empty regex only is successful on the empty
                            // string
}

// MatchOperator
template <typename Source>
inline int RegEx::MatchOpMatch(const Source& source) const {
  if (source[0] != m_a)
    return -1;
  return 1;
}

// RangeOperator
template <typename Source>
inline int RegEx::MatchOpRange(const Source& source) const {
  if (m_a > source[0] || m_z < source[0])
    return -1;
  return 1;
}

// OrOperator
template <typename Source>
inline int RegEx::MatchOpOr(const Source& source) const {
  for (const RegEx& param : m_params) {
    int n = param.MatchUnchecked(source);
    if (n >= 0)
      return n;
  }
  return -1;
}

// AndOperator
// Note: 'AND' is a little funny, since we may be required to match things
//       of different lengths. If we find a match, we return the length of
//       the FIRST entry on the list.
template <typename Source>
inline int RegEx::MatchOpAnd(const Source& source) const {
  int first = -1;
  for (std::size_t i = 0; i < m_params.size(); i++) {
    int n = m_params[i].MatchUnchecked(source);
    if (n == -1)
      return -1;
    if (i == 0)
      first = n;
  }
  return first;
}

// NotOperator
template <typename Source>
inline int RegEx::MatchOpNot(const Source& source) const {
  if (m_params.empty())
    return -1;
  if (m_params[0].MatchUnchecked(source) >= 0)
    return -1;
  return 1;
}

// SeqOperator
template <typename Source>
inline int RegEx::MatchOpSeq(const Source& source) const {
  int offset = 0;
  for (const RegEx& param : m_params) {
    int n = param.Match(source + offset);  // note Match, not
                                           // MatchUnchecked because we
                                           // need to check validity after
                                           // the offset
    if (n == -1)
      return -1;
    offset += n;
  }

  return offset;
}
}  // namespace YAML

#endif  // REGEXIMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/regeximpl.h ======


#endif  // REGEX_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/regex_yaml.h ======

// Expanding include: stream.h

namespace YAML {
////////////////////////////////////////////////////////////////////////////////
// Here we store a bunch of expressions for matching different parts of the
// file.

namespace Exp {
// misc
inline const RegEx& Empty() {
  static const RegEx e;
  return e;
}
inline const RegEx& Space() {
  static const RegEx e = RegEx(' ');
  return e;
}
inline const RegEx& Tab() {
  static const RegEx e = RegEx('\t');
  return e;
}
inline const RegEx& Blank() {
  static const RegEx e = Space() | Tab();
  return e;
}
inline const RegEx& Break() {
  static const RegEx e = RegEx('\n') | RegEx("\r\n") | RegEx('\r');
  return e;
}
inline const RegEx& BlankOrBreak() {
  static const RegEx e = Blank() | Break();
  return e;
}
inline const RegEx& Digit() {
  static const RegEx e = RegEx('0', '9');
  return e;
}
inline const RegEx& Alpha() {
  static const RegEx e = RegEx('a', 'z') | RegEx('A', 'Z');
  return e;
}
inline const RegEx& AlphaNumeric() {
  static const RegEx e = Alpha() | Digit();
  return e;
}
inline const RegEx& Word() {
  static const RegEx e = AlphaNumeric() | RegEx('-');
  return e;
}
inline const RegEx& Hex() {
  static const RegEx e = Digit() | RegEx('A', 'F') | RegEx('a', 'f');
  return e;
}
// Valid Unicode code points that are not part of c-printable (YAML 1.2, sec.
// 5.1)
inline const RegEx& NotPrintable() {
  static const RegEx e =
      RegEx(0) |
      RegEx("\x01\x02\x03\x04\x05\x06\x07\x08\x0B\x0C\x7F", REGEX_OR) |
      RegEx(0x0E, 0x1F) |
      (RegEx('\xC2') + (RegEx('\x80', '\x84') | RegEx('\x86', '\x9F')));
  return e;
}
inline const RegEx& Utf8_ByteOrderMark() {
  static const RegEx e = RegEx("\xEF\xBB\xBF");
  return e;
}

// actual tags

inline const RegEx& DocStart() {
  static const RegEx e = RegEx("---") + (BlankOrBreak() | RegEx());
  return e;
}
inline const RegEx& DocEnd() {
  static const RegEx e = RegEx("...") + (BlankOrBreak() | RegEx());
  return e;
}
inline const RegEx& DocIndicator() {
  static const RegEx e = DocStart() | DocEnd();
  return e;
}
inline const RegEx& BlockEntry() {
  static const RegEx e = RegEx('-') + (BlankOrBreak() | RegEx());
  return e;
}
inline const RegEx& Key() {
  static const RegEx e = RegEx('?') + BlankOrBreak();
  return e;
}
inline const RegEx& KeyInFlow() {
  static const RegEx e = RegEx('?') + BlankOrBreak();
  return e;
}
inline const RegEx& Value() {
  static const RegEx e = RegEx(':') + (BlankOrBreak() | RegEx());
  return e;
}
inline const RegEx& ValueInFlow() {
  static const RegEx e = RegEx(':') + (BlankOrBreak() | RegEx(",]}", REGEX_OR));
  return e;
}
inline const RegEx& ValueInJSONFlow() {
  static const RegEx e = RegEx(':');
  return e;
}
inline const RegEx& Ampersand() {
  static const RegEx e = RegEx('&');
  return e;
}
inline const RegEx Comment() {
  static const RegEx e = RegEx('#');
  return e;
}
inline const RegEx& Anchor() {
  static const RegEx e = !(RegEx("[]{},", REGEX_OR) | BlankOrBreak());
  return e;
}
inline const RegEx& AnchorEnd() {
  static const RegEx e = RegEx("?:,]}%@`", REGEX_OR) | BlankOrBreak();
  return e;
}
inline const RegEx& URI() {
  static const RegEx e = Word() | RegEx("#;/?:@&=+$,_.!~*'()[]", REGEX_OR) |
                         (RegEx('%') + Hex() + Hex());
  return e;
}
inline const RegEx& Tag() {
  static const RegEx e = Word() | RegEx("#;/?:@&=+$_.~*'()", REGEX_OR) |
                         (RegEx('%') + Hex() + Hex());
  return e;
}

// Plain scalar rules:
// . Cannot start with a blank.
// . Can never start with any of , [ ] { } # & * ! | > \' \" % @ `
// . In the block context - ? : must be not be followed with a space.
// . In the flow context ? is illegal and : and - must not be followed with a
// space.
inline const RegEx& PlainScalar() {
  static const RegEx e =
      !(BlankOrBreak() | RegEx(",[]{}#&*!|>\'\"%@`", REGEX_OR) |
        (RegEx("-?:", REGEX_OR) + (BlankOrBreak() | RegEx())));
  return e;
}
inline const RegEx& PlainScalarInFlow() {
  static const RegEx e =
      !(BlankOrBreak() | RegEx("?,[]{}#&*!|>\'\"%@`", REGEX_OR) |
        (RegEx("-:", REGEX_OR) + (Blank() | RegEx())));
  return e;
}
inline const RegEx& EndScalar() {
  static const RegEx e = RegEx(':') + (BlankOrBreak() | RegEx());
  return e;
}
inline const RegEx& EndScalarInFlow() {
  static const RegEx e =
      (RegEx(':') + (BlankOrBreak() | RegEx() | RegEx(",]}", REGEX_OR))) |
      RegEx(",?[]{}", REGEX_OR);
  return e;
}

inline const RegEx& ScanScalarEndInFlow() {
  static const RegEx e = (EndScalarInFlow() | (BlankOrBreak() + Comment()));
  return e;
}

inline const RegEx& ScanScalarEnd() {
  static const RegEx e = EndScalar() | (BlankOrBreak() + Comment());
  return e;
}
inline const RegEx& EscSingleQuote() {
  static const RegEx e = RegEx("\'\'");
  return e;
}
inline const RegEx& EscBreak() {
  static const RegEx e = RegEx('\\') + Break();
  return e;
}

inline const RegEx& ChompIndicator() {
  static const RegEx e = RegEx("+-", REGEX_OR);
  return e;
}
inline const RegEx& Chomp() {
  static const RegEx e = (ChompIndicator() + Digit()) |
                         (Digit() + ChompIndicator()) | ChompIndicator() |
                         Digit();
  return e;
}

// and some functions
std::string Escape(Stream& in);
}  // namespace Exp

namespace Keys {
const char Directive = '%';
const char FlowSeqStart = '[';
const char FlowSeqEnd = ']';
const char FlowMapStart = '{';
const char FlowMapEnd = '}';
const char FlowEntry = ',';
const char Alias = '*';
const char Anchor = '&';
const char Tag = '!';
const char LiteralScalar = '|';
const char FoldedScalar = '>';
const char VerbatimTagStart = '<';
const char VerbatimTagEnd = '>';
}  // namespace Keys
}  // namespace YAML

#endif  // EXP_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/exp.h ======

// Expanding include: indentation.h
// Expanding include: regex_yaml.h
// Expanding include: regeximpl.h
// Expanding include: stringsource.h
// Expanding include: yaml-cpp/binary.h
// Expanding include: yaml-cpp/null.h
// Expanding include: yaml-cpp/ostream_wrapper.h

namespace YAML {
namespace Utils {
namespace {
enum { REPLACEMENT_CHARACTER = 0xFFFD };

bool IsAnchorChar(int ch) {  // test for ns-anchor-char
  switch (ch) {
    case ',':
    case '[':
    case ']':
    case '{':
    case '}':  // c-flow-indicator
    case ' ':
    case '\t':    // s-white
    case 0xFEFF:  // c-byte-order-mark
    case 0xA:
    case 0xD:  // b-char
      return false;
    case 0x85:
      return true;
  }

  if (ch < 0x20) {
    return false;
  }

  if (ch < 0x7E) {
    return true;
  }

  if (ch < 0xA0) {
    return false;
  }
  if (ch >= 0xD800 && ch <= 0xDFFF) {
    return false;
  }
  if ((ch & 0xFFFE) == 0xFFFE) {
    return false;
  }
  if ((ch >= 0xFDD0) && (ch <= 0xFDEF)) {
    return false;
  }
  if (ch > 0x10FFFF) {
    return false;
  }

  return true;
}

int Utf8BytesIndicated(char ch) {
  int byteVal = static_cast<unsigned char>(ch);
  switch (byteVal >> 4) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return 1;
    case 12:
    case 13:
      return 2;
    case 14:
      return 3;
    case 15:
      return 4;
    default:
      return -1;
  }
}

bool IsTrailingByte(char ch) { return (ch & 0xC0) == 0x80; }

bool GetNextCodePointAndAdvance(int& codePoint,
                                const char*& first,
                                const char* last) {
  if (first == last)
    return false;

  int nBytes = Utf8BytesIndicated(*first);
  if (nBytes < 1) {
    // Bad lead byte
    ++first;
    codePoint = REPLACEMENT_CHARACTER;
    return true;
  }

  if (nBytes == 1) {
    codePoint = *first++;
    return true;
  }

  // Gather bits from trailing bytes
  codePoint = static_cast<unsigned char>(*first) & ~(0xFF << (7 - nBytes));
  ++first;
  --nBytes;
  for (; nBytes > 0; ++first, --nBytes) {
    if ((first == last) || !IsTrailingByte(*first)) {
      codePoint = REPLACEMENT_CHARACTER;
      break;
    }
    codePoint <<= 6;
    codePoint |= *first & 0x3F;
  }

  // Check for illegal code points
  if (codePoint > 0x10FFFF)
    codePoint = REPLACEMENT_CHARACTER;
  else if (codePoint >= 0xD800 && codePoint <= 0xDFFF)
    codePoint = REPLACEMENT_CHARACTER;
  else if ((codePoint & 0xFFFE) == 0xFFFE)
    codePoint = REPLACEMENT_CHARACTER;
  else if (codePoint >= 0xFDD0 && codePoint <= 0xFDEF)
    codePoint = REPLACEMENT_CHARACTER;
  return true;
}

void WriteCodePoint(ostream_wrapper& out, int codePoint) {
  if (codePoint < 0 || codePoint > 0x10FFFF) {
    codePoint = REPLACEMENT_CHARACTER;
  }
  if (codePoint <= 0x7F) {
    out << static_cast<char>(codePoint);
  } else if (codePoint <= 0x7FF) {
    out << static_cast<char>(0xC0 | (codePoint >> 6))
        << static_cast<char>(0x80 | (codePoint & 0x3F));
  } else if (codePoint <= 0xFFFF) {
    out << static_cast<char>(0xE0 | (codePoint >> 12))
        << static_cast<char>(0x80 | ((codePoint >> 6) & 0x3F))
        << static_cast<char>(0x80 | (codePoint & 0x3F));
  } else {
    out << static_cast<char>(0xF0 | (codePoint >> 18))
        << static_cast<char>(0x80 | ((codePoint >> 12) & 0x3F))
        << static_cast<char>(0x80 | ((codePoint >> 6) & 0x3F))
        << static_cast<char>(0x80 | (codePoint & 0x3F));
  }
}

bool IsValidPlainScalar(const char* str, std::size_t size, FlowType::value flowType,
                        bool allowOnlyAscii) {
  // check against null
  if (IsNullString(str, size)) {
    return false;
  }

  // check the start
  const RegEx& start = (flowType == FlowType::Flow ? Exp::PlainScalarInFlow()
                                                   : Exp::PlainScalar());
  if (!start.Matches(StringCharSource(str, size))) {
    return false;
  }

  // and check the end for plain whitespace (which can't be faithfully kept in a
  // plain scalar)
  if (size != 0 && str[size - 1] == ' ') {
    return false;
  }

  // then check until something is disallowed
  static const RegEx disallowed_flow =
      Exp::EndScalarInFlow() | (Exp::BlankOrBreak() + Exp::Comment()) |
      Exp::NotPrintable() | Exp::Utf8_ByteOrderMark() | Exp::Break() |
      Exp::Tab() | Exp::Ampersand();
  static const RegEx disallowed_block =
      Exp::EndScalar() | (Exp::BlankOrBreak() + Exp::Comment()) |
      Exp::NotPrintable() | Exp::Utf8_ByteOrderMark() | Exp::Break() |
      Exp::Tab() | Exp::Ampersand();
  const RegEx& disallowed =
      flowType == FlowType::Flow ? disallowed_flow : disallowed_block;

  StringCharSource buffer(str, size);
  while (buffer) {
    if (disallowed.Matches(buffer)) {
      return false;
    }
    if (allowOnlyAscii && (0x80 <= static_cast<unsigned char>(buffer[0]))) {
      return false;
    }
    ++buffer;
  }

  return true;
}

bool IsValidSingleQuotedScalar(const char* str, std::size_t size, bool escapeNonAscii) {
  // TODO: check for non-printable characters?
  return std::none_of(str, str + size, [=](char ch) {
    return (escapeNonAscii && (0x80 <= static_cast<unsigned char>(ch))) ||
           (ch == '\n');
  });
}

bool IsValidLiteralScalar(const char* str, std::size_t size, FlowType::value flowType,
                          bool escapeNonAscii) {
  if (flowType == FlowType::Flow) {
    return false;
  }

  // TODO: check for non-printable characters?
  return std::none_of(str, str + size, [=](char ch) {
    return (escapeNonAscii && (0x80 <= static_cast<unsigned char>(ch)));
  });
}

std::pair<uint16_t, uint16_t> EncodeUTF16SurrogatePair(int codePoint) {
  const uint32_t leadOffset = 0xD800 - (0x10000 >> 10);

  return {
    leadOffset | (codePoint >> 10),
    0xDC00 | (codePoint & 0x3FF),
  };
}

void WriteDoubleQuoteEscapeSequence(ostream_wrapper& out, int codePoint, StringEscaping::value stringEscapingStyle) {
  static const char hexDigits[] = "0123456789abcdef";

  out << "\\";
  int digits = 8;
  if (codePoint < 0xFF && stringEscapingStyle != StringEscaping::JSON) {
    out << "x";
    digits = 2;
  } else if (codePoint < 0xFFFF) {
    out << "u";
    digits = 4;
  } else if (stringEscapingStyle != StringEscaping::JSON) {
    out << "U";
    digits = 8;
  } else {
    auto surrogatePair = EncodeUTF16SurrogatePair(codePoint);
    WriteDoubleQuoteEscapeSequence(out, surrogatePair.first, stringEscapingStyle);
    WriteDoubleQuoteEscapeSequence(out, surrogatePair.second, stringEscapingStyle);
    return;
  }

  // Write digits into the escape sequence
  for (; digits > 0; --digits)
    out << hexDigits[(codePoint >> (4 * (digits - 1))) & 0xF];
}

bool WriteAliasName(ostream_wrapper& out, const char* str, std::size_t size) {
  int codePoint;
  for (const char* i = str;
       GetNextCodePointAndAdvance(codePoint, i, str + size);) {
    if (!IsAnchorChar(codePoint)) {
      return false;
    }

    WriteCodePoint(out, codePoint);
  }
  return true;
}
}  // namespace

StringFormat::value ComputeStringFormat(const char* str, std::size_t size,
                                        EMITTER_MANIP strFormat,
                                        FlowType::value flowType,
                                        bool escapeNonAscii) {
  switch (strFormat) {
    case Auto:
      if (IsValidPlainScalar(str, size, flowType, escapeNonAscii)) {
        return StringFormat::Plain;
      }
      return StringFormat::DoubleQuoted;
    case SingleQuoted:
      if (IsValidSingleQuotedScalar(str, size, escapeNonAscii)) {
        return StringFormat::SingleQuoted;
      }
      return StringFormat::DoubleQuoted;
    case DoubleQuoted:
      return StringFormat::DoubleQuoted;
    case Literal:
      if (IsValidLiteralScalar(str, size, flowType, escapeNonAscii)) {
        return StringFormat::Literal;
      }
      return StringFormat::DoubleQuoted;
    default:
      break;
  }

  return StringFormat::DoubleQuoted;
}

bool WriteSingleQuotedString(ostream_wrapper& out, const char* str, std::size_t size) {
  out << "'";
  int codePoint;
  for (const char* i = str;
       GetNextCodePointAndAdvance(codePoint, i, str + size);) {
    if (codePoint == '\n') {
      return false;  // We can't handle a new line and the attendant indentation
                     // yet
    }

    if (codePoint == '\'') {
      out << "''";
    } else {
      WriteCodePoint(out, codePoint);
    }
  }
  out << "'";
  return true;
}

bool WriteDoubleQuotedString(ostream_wrapper& out, const char* str, std::size_t size,
                             StringEscaping::value stringEscaping) {
  out << "\"";
  int codePoint;
  for (const char* i = str;
       GetNextCodePointAndAdvance(codePoint, i, str + size);) {
    switch (codePoint) {
      case '\"':
        out << "\\\"";
        break;
      case '\\':
        out << "\\\\";
        break;
      case '\n':
        out << "\\n";
        break;
      case '\t':
        out << "\\t";
        break;
      case '\r':
        out << "\\r";
        break;
      case '\b':
        out << "\\b";
        break;
      case '\f':
        out << "\\f";
        break;
      default:
        if (codePoint < 0x20 ||
            (codePoint >= 0x80 &&
             codePoint <= 0xA0)) {  // Control characters and non-breaking space
          WriteDoubleQuoteEscapeSequence(out, codePoint, stringEscaping);
        } else if (codePoint == 0xFEFF) {  // Byte order marks (ZWNS) should be
                                           // escaped (YAML 1.2, sec. 5.2)
          WriteDoubleQuoteEscapeSequence(out, codePoint, stringEscaping);
        } else if (stringEscaping == StringEscaping::NonAscii && codePoint > 0x7E) {
          WriteDoubleQuoteEscapeSequence(out, codePoint, stringEscaping);
        } else {
          WriteCodePoint(out, codePoint);
        }
    }
  }
  out << "\"";
  return true;
}

bool WriteLiteralString(ostream_wrapper& out, const char* str, std::size_t size,
                        std::size_t indent) {
  out << "|\n";
  int codePoint;
  for (const char* i = str;
       GetNextCodePointAndAdvance(codePoint, i, str + size);) {
    if (codePoint == '\n') {
      out << "\n";
    } else {
      out<< IndentTo(indent);
      WriteCodePoint(out, codePoint);
    }
  }
  return true;
}

bool WriteChar(ostream_wrapper& out, char ch, StringEscaping::value stringEscapingStyle) {
  if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
    out << ch;
  } else if (ch == '\"') {
    out << R"("\"")";
  } else if (ch == '\t') {
    out << R"("\t")";
  } else if (ch == '\n') {
    out << R"("\n")";
  } else if (ch == '\b') {
    out << R"("\b")";
  } else if (ch == '\r') {
    out << R"("\r")";
  } else if (ch == '\f') {
    out << R"("\f")";
  } else if (ch == '\\') {
    out << R"("\\")";
  } else if (0x20 <= ch && ch <= 0x7e) {
    out << "\"" << ch << "\"";
  } else {
    out << "\"";
    WriteDoubleQuoteEscapeSequence(out, ch, stringEscapingStyle);
    out << "\"";
  }
  return true;
}

bool WriteComment(ostream_wrapper& out, const char* str, std::size_t size,
                  std::size_t postCommentIndent) {
  const std::size_t curIndent = out.col();
  out << "#" << Indentation(postCommentIndent);
  out.set_comment();
  int codePoint;
  for (const char* i = str;
       GetNextCodePointAndAdvance(codePoint, i, str + size);) {
    if (codePoint == '\n') {
      out << "\n"
          << IndentTo(curIndent) << "#" << Indentation(postCommentIndent);
      out.set_comment();
    } else {
      WriteCodePoint(out, codePoint);
    }
  }
  return true;
}

bool WriteAlias(ostream_wrapper& out, const char* str, std::size_t size) {
  out << "*";
  return WriteAliasName(out, str, size);
}

bool WriteAnchor(ostream_wrapper& out, const char* str, std::size_t size) {
  out << "&";
  return WriteAliasName(out, str, size);
}

bool WriteTag(ostream_wrapper& out, const std::string& str, bool verbatim) {
  out << (verbatim ? "!<" : "!");
  StringCharSource buffer(str.c_str(), str.size());
  const RegEx& reValid = verbatim ? Exp::URI() : Exp::Tag();
  while (buffer) {
    int n = reValid.Match(buffer);
    if (n <= 0) {
      return false;
    }

    while (--n >= 0) {
      out << buffer[0];
      ++buffer;
    }
  }
  if (verbatim) {
    out << ">";
  }
  return true;
}

bool WriteTagWithPrefix(ostream_wrapper& out, const std::string& prefix,
                        const std::string& tag) {
  out << "!";
  StringCharSource prefixBuffer(prefix.c_str(), prefix.size());
  while (prefixBuffer) {
    int n = Exp::URI().Match(prefixBuffer);
    if (n <= 0) {
      return false;
    }

    while (--n >= 0) {
      out << prefixBuffer[0];
      ++prefixBuffer;
    }
  }

  out << "!";
  StringCharSource tagBuffer(tag.c_str(), tag.size());
  while (tagBuffer) {
    int n = Exp::Tag().Match(tagBuffer);
    if (n <= 0) {
      return false;
    }

    while (--n >= 0) {
      out << tagBuffer[0];
      ++tagBuffer;
    }
  }
  return true;
}

bool WriteBinary(ostream_wrapper& out, const Binary& binary) {
  std::string encoded = EncodeBase64(binary.data(), binary.size());
  WriteDoubleQuotedString(out, encoded.data(), encoded.size(),
                          StringEscaping::None);
  return true;
}
}  // namespace Utils
}  // namespace YAML
// ====== END yaml-cpp/src/emitterutils.cpp ======


// ====== BEGIN yaml-cpp/src/exceptions.cpp ======
// Expanding include: yaml-cpp/exceptions.h
// Expanding include: yaml-cpp/noexcept.h

namespace YAML {

// These destructors are defined out-of-line so the vtable is only emitted once.
Exception::~Exception() YAML_CPP_NOEXCEPT = default;
ParserException::~ParserException() YAML_CPP_NOEXCEPT = default;
RepresentationException::~RepresentationException() YAML_CPP_NOEXCEPT = default;
InvalidScalar::~InvalidScalar() YAML_CPP_NOEXCEPT = default;
KeyNotFound::~KeyNotFound() YAML_CPP_NOEXCEPT = default;
InvalidNode::~InvalidNode() YAML_CPP_NOEXCEPT = default;
BadConversion::~BadConversion() YAML_CPP_NOEXCEPT = default;
BadDereference::~BadDereference() YAML_CPP_NOEXCEPT = default;
BadSubscript::~BadSubscript() YAML_CPP_NOEXCEPT = default;
BadPushback::~BadPushback() YAML_CPP_NOEXCEPT = default;
BadInsert::~BadInsert() YAML_CPP_NOEXCEPT = default;
EmitterException::~EmitterException() YAML_CPP_NOEXCEPT = default;
BadFile::~BadFile() YAML_CPP_NOEXCEPT = default;
}  // namespace YAML
// ====== END yaml-cpp/src/exceptions.cpp ======


// ====== BEGIN yaml-cpp/src/exp.cpp ======
#include <sstream>

// Expanding include: exp.h
// Expanding include: stream.h
// Expanding include: yaml-cpp/exceptions.h

namespace YAML {
struct Mark;
}  // namespace YAML

namespace YAML {
namespace Exp {
unsigned ParseHex(const std::string& str, const Mark& mark) {
  unsigned value = 0;
  for (char ch : str) {
    int digit = 0;
    if ('a' <= ch && ch <= 'f')
      digit = ch - 'a' + 10;
    else if ('A' <= ch && ch <= 'F')
      digit = ch - 'A' + 10;
    else if ('0' <= ch && ch <= '9')
      digit = ch - '0';
    else
      throw ParserException(mark, ErrorMsg::INVALID_HEX);

    value = (value << 4) + digit;
  }

  return value;
}

std::string Str(unsigned ch) { return std::string(1, static_cast<char>(ch)); }

// Escape
// . Translates the next 'codeLength' characters into a hex number and returns
// the result.
// . Throws if it's not actually hex.
std::string Escape(Stream& in, int codeLength) {
  // grab string
  std::string str;
  for (int i = 0; i < codeLength; i++)
    str += in.get();

  // get the value
  unsigned value = ParseHex(str, in.mark());

  // legal unicode?
  if ((value >= 0xD800 && value <= 0xDFFF) || value > 0x10FFFF) {
    std::stringstream msg;
    msg << ErrorMsg::INVALID_UNICODE << value;
    throw ParserException(in.mark(), msg.str());
  }

  // now break it up into chars
  if (value <= 0x7F)
    return Str(value);

  if (value <= 0x7FF)
    return Str(0xC0 + (value >> 6)) + Str(0x80 + (value & 0x3F));

  if (value <= 0xFFFF)
    return Str(0xE0 + (value >> 12)) + Str(0x80 + ((value >> 6) & 0x3F)) +
           Str(0x80 + (value & 0x3F));

  return Str(0xF0 + (value >> 18)) + Str(0x80 + ((value >> 12) & 0x3F)) +
         Str(0x80 + ((value >> 6) & 0x3F)) + Str(0x80 + (value & 0x3F));
}

// Escape
// . Escapes the sequence starting 'in' (it must begin with a '\' or single
// quote)
//   and returns the result.
// . Throws if it's an unknown escape character.
std::string Escape(Stream& in) {
  // eat slash
  char escape = in.get();

  // switch on escape character
  char ch = in.get();

  // first do single quote, since it's easier
  if (escape == '\'' && ch == '\'')
    return "\'";

  // now do the slash (we're not gonna check if it's a slash - you better pass
  // one!)
  switch (ch) {
    case '0':
      return std::string(1, '\x00');
    case 'a':
      return "\x07";
    case 'b':
      return "\x08";
    case 't':
    case '\t':
      return "\x09";
    case 'n':
      return "\x0A";
    case 'v':
      return "\x0B";
    case 'f':
      return "\x0C";
    case 'r':
      return "\x0D";
    case 'e':
      return "\x1B";
    case ' ':
      return R"( )";
    case '\"':
      return "\"";
    case '\'':
      return "\'";
    case '\\':
      return "\\";
    case '/':
      return "/";
    case 'N':
      return "\x85";
    case '_':
      return "\xA0";
    case 'L':
      return "\xE2\x80\xA8";  // LS (#x2028)
    case 'P':
      return "\xE2\x80\xA9";  // PS (#x2029)
    case 'x':
      return Escape(in, 2);
    case 'u':
      return Escape(in, 4);
    case 'U':
      return Escape(in, 8);
  }

  std::stringstream msg;
  throw ParserException(in.mark(), std::string(ErrorMsg::INVALID_ESCAPE) + ch);
}
}  // namespace Exp
}  // namespace YAML
// ====== END yaml-cpp/src/exp.cpp ======


// ====== BEGIN yaml-cpp/src/fptostring.cpp ======
// Expanding include: yaml-cpp/fptostring.h
// Expanding include: contrib/dragonbox.h

// ====== BEGIN yaml-cpp/src/contrib/dragonbox.h ======
// SPDX-FileCopyrightText: 2020-2024 Junekey Jeon
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-License-Identifier: BSL-1.0
// SPDX-License-Identifier: MIT

// This file is an adjusted copy of https://github.com/jk-jeon/dragonbox
// Junekey Jeon agreed to license this file under MIT license explicitly for
// usage in yaml-cpp.
//
// Changes to the original dragonbox library:
// - Added additional license information and information at top
// - Wrapped the 'jkj' namespace in an additional 'YAML' namespace

#ifndef JKJ_HEADER_DRAGONBOX
#define JKJ_HEADER_DRAGONBOX

// Attribute for storing static data into a dedicated place, e.g. flash memory. Every ODR-used
// static data declaration will be decorated with this macro. The users may define this macro,
// before including the library headers, into whatever they want.
#ifndef JKJ_STATIC_DATA_SECTION
    #define JKJ_STATIC_DATA_SECTION
#else
    #define JKJ_STATIC_DATA_SECTION_DEFINED 1
#endif

// To use the library with toolchains without standard C++ headers, the users may define this macro
// into their custom namespace which contains the defintions of all the standard C++ library
// features used in this header. (The list can be found below.)
#ifndef JKJ_STD_REPLACEMENT_NAMESPACE
    #define JKJ_STD_REPLACEMENT_NAMESPACE std
    #include <cassert>
    #include <cstdint>
    #include <cstring>
    #include <limits>
    #include <type_traits>

    #ifdef __has_include
        #if __has_include(<version>)
            #include <version>
        #endif
    #endif
#else
    #define JKJ_STD_REPLACEMENT_NAMESPACE_DEFINED 1
#endif

////////////////////////////////////////////////////////////////////////////////////////
// Language feature detections.
////////////////////////////////////////////////////////////////////////////////////////

// C++14 constexpr
#if defined(__cpp_constexpr) && __cpp_constexpr >= 201304L
    #define JKJ_HAS_CONSTEXPR14 1
#elif __cplusplus >= 201402L
    #define JKJ_HAS_CONSTEXPR14 1
#elif defined(_MSC_VER) && _MSC_VER >= 1910 && _MSVC_LANG >= 201402L
    #define JKJ_HAS_CONSTEXPR14 1
#else
    #define JKJ_HAS_CONSTEXPR14 0
#endif

#if JKJ_HAS_CONSTEXPR14
    #define JKJ_CONSTEXPR14 constexpr
#else
    #define JKJ_CONSTEXPR14
#endif

// C++17 constexpr lambdas
#if defined(__cpp_constexpr) && __cpp_constexpr >= 201603L
    #define JKJ_HAS_CONSTEXPR17 1
#elif __cplusplus >= 201703L
    #define JKJ_HAS_CONSTEXPR17 1
#elif defined(_MSC_VER) && _MSC_VER >= 1911 && _MSVC_LANG >= 201703L
    #define JKJ_HAS_CONSTEXPR17 1
#else
    #define JKJ_HAS_CONSTEXPR17 0
#endif

// C++17 inline variables
#if defined(__cpp_inline_variables) && __cpp_inline_variables >= 201606L
    #define JKJ_HAS_INLINE_VARIABLE 1
#elif __cplusplus >= 201703L
    #define JKJ_HAS_INLINE_VARIABLE 1
#elif defined(_MSC_VER) && _MSC_VER >= 1912 && _MSVC_LANG >= 201703L
    #define JKJ_HAS_INLINE_VARIABLE 1
#else
    #define JKJ_HAS_INLINE_VARIABLE 0
#endif

#if JKJ_HAS_INLINE_VARIABLE
    #define JKJ_INLINE_VARIABLE inline constexpr
#else
    #define JKJ_INLINE_VARIABLE static constexpr
#endif

// C++17 if constexpr
#if defined(__cpp_if_constexpr) && __cpp_if_constexpr >= 201606L
    #define JKJ_HAS_IF_CONSTEXPR 1
#elif __cplusplus >= 201703L
    #define JKJ_HAS_IF_CONSTEXPR 1
#elif defined(_MSC_VER) && _MSC_VER >= 1911 && _MSVC_LANG >= 201703L
    #define JKJ_HAS_IF_CONSTEXPR 1
#else
    #define JKJ_HAS_IF_CONSTEXPR 0
#endif

#if JKJ_HAS_IF_CONSTEXPR
    #define JKJ_IF_CONSTEXPR if constexpr
#else
    #define JKJ_IF_CONSTEXPR if
#endif

// C++20 std::bit_cast
#if JKJ_STD_REPLACEMENT_NAMESPACE_DEFINED
    #if JKJ_STD_REPLACEMENT_HAS_BIT_CAST
        #define JKJ_HAS_BIT_CAST 1
    #else
        #define JKJ_HAS_BIT_CAST 0
    #endif
#elif defined(__cpp_lib_bit_cast) && __cpp_lib_bit_cast >= 201806L
    #include <bit>
    #define JKJ_HAS_BIT_CAST 1
#else
    #define JKJ_HAS_BIT_CAST 0
#endif

// C++23 if consteval or C++20 std::is_constant_evaluated
#if defined(__cpp_if_consteval) && __cpp_is_consteval >= 202106L
    #define JKJ_IF_CONSTEVAL if consteval
    #define JKJ_IF_NOT_CONSTEVAL if !consteval
    #define JKJ_CAN_BRANCH_ON_CONSTEVAL 1
    #define JKJ_USE_IS_CONSTANT_EVALUATED 0
#elif JKJ_STD_REPLACEMENT_NAMESPACE_DEFINED
    #if JKJ_STD_REPLACEMENT_HAS_IS_CONSTANT_EVALUATED
        #define JKJ_IF_CONSTEVAL if (stdr::is_constant_evaluated())
        #define JKJ_IF_NOT_CONSTEVAL if (!stdr::is_constant_evaluated())
        #define JKJ_CAN_BRANCH_ON_CONSTEVAL 1
        #define JKJ_USE_IS_CONSTANT_EVALUATED 1
    #elif JKJ_HAS_IF_CONSTEXPR
        #define JKJ_IF_CONSTEVAL if constexpr (false)
        #define JKJ_IF_NOT_CONSTEVAL if constexpr (true)
        #define JKJ_CAN_BRANCH_ON_CONSTEVAL 0
        #define JKJ_USE_IS_CONSTANT_EVALUATED 0
    #else
        #define JKJ_IF_CONSTEVAL if (false)
        #define JKJ_IF_NOT_CONSTEVAL if (true)
        #define JKJ_CAN_BRANCH_ON_CONSTEVAL 0
        #define JKJ_USE_IS_CONSTANT_EVALUATED 0
    #endif
#else
    #if defined(__cpp_lib_is_constant_evaluated) && __cpp_lib_is_constant_evaluated >= 201811L
        #define JKJ_IF_CONSTEVAL if (stdr::is_constant_evaluated())
        #define JKJ_IF_NOT_CONSTEVAL if (!stdr::is_constant_evaluated())
        #define JKJ_CAN_BRANCH_ON_CONSTEVAL 1
        #define JKJ_USE_IS_CONSTANT_EVALUATED 1
    #elif JKJ_HAS_IF_CONSTEXPR
        #define JKJ_IF_CONSTEVAL if constexpr (false)
        #define JKJ_IF_NOT_CONSTEVAL if constexpr (true)
        #define JKJ_CAN_BRANCH_ON_CONSTEVAL 0
        #define JKJ_USE_IS_CONSTANT_EVALUATED 0
    #else
        #define JKJ_IF_CONSTEVAL if (false)
        #define JKJ_IF_NOT_CONSTEVAL if (true)
        #define JKJ_CAN_BRANCH_ON_CONSTEVAL 0
        #define JKJ_USE_IS_CONSTANT_EVALUATED 0
    #endif
#endif

#if JKJ_CAN_BRANCH_ON_CONSTEVAL && JKJ_HAS_BIT_CAST
    #define JKJ_CONSTEXPR20 constexpr
#else
    #define JKJ_CONSTEXPR20
#endif

// Suppress additional buffer overrun check.
// I have no idea why MSVC thinks some functions here are vulnerable to the buffer overrun
// attacks. No, they aren't.
#if defined(__GNUC__) || defined(__clang__)
    #define JKJ_SAFEBUFFERS
    #define JKJ_FORCEINLINE inline __attribute__((always_inline))
#elif defined(_MSC_VER)
    #define JKJ_SAFEBUFFERS __declspec(safebuffers)
    #define JKJ_FORCEINLINE __forceinline
#else
    #define JKJ_SAFEBUFFERS
    #define JKJ_FORCEINLINE inline
#endif

#if defined(__has_builtin)
    #define JKJ_HAS_BUILTIN(x) __has_builtin(x)
#else
    #define JKJ_HAS_BUILTIN(x) false
#endif

#if defined(_MSC_VER)
    #include <intrin.h>
#elif defined(__INTEL_COMPILER)
    #include <immintrin.h>
#endif

namespace YAML {
namespace jkj {
    namespace dragonbox {
        ////////////////////////////////////////////////////////////////////////////////////////
        // The Compatibility layer for toolchains without standard C++ headers.
        ////////////////////////////////////////////////////////////////////////////////////////
        namespace detail {
            namespace stdr {
                // <bit>
#if JKJ_HAS_BIT_CAST
                using JKJ_STD_REPLACEMENT_NAMESPACE::bit_cast;
#endif

                // <cassert>
                // We need assert() macro, but it is not namespaced anyway, so nothing to do here.

                // <cstdint>
                using JKJ_STD_REPLACEMENT_NAMESPACE::int_least8_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::int_least16_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::int_least32_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::int_fast8_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::int_fast16_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::int_fast32_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::uint_least8_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::uint_least16_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::uint_least32_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::uint_least64_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::uint_fast8_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::uint_fast16_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::uint_fast32_t;
                // We need INT32_C, UINT32_C and UINT64_C macros too, but again there is nothing to do
                // here.

                // <cstring>
                using JKJ_STD_REPLACEMENT_NAMESPACE::size_t;
                using JKJ_STD_REPLACEMENT_NAMESPACE::memcpy;

                // <limits>
                template <class T>
                using numeric_limits = JKJ_STD_REPLACEMENT_NAMESPACE::numeric_limits<T>;

                // <type_traits>
                template <bool cond, class T = void>
                using enable_if = JKJ_STD_REPLACEMENT_NAMESPACE::enable_if<cond, T>;
                template <class T>
                using add_rvalue_reference = JKJ_STD_REPLACEMENT_NAMESPACE::add_rvalue_reference<T>;
                template <bool cond, class T_true, class T_false>
                using conditional = JKJ_STD_REPLACEMENT_NAMESPACE::conditional<cond, T_true, T_false>;
#if JKJ_USE_IS_CONSTANT_EVALUATED
                using JKJ_STD_REPLACEMENT_NAMESPACE::is_constant_evaluated;
#endif
                template <class T1, class T2>
                using is_same = JKJ_STD_REPLACEMENT_NAMESPACE::is_same<T1, T2>;
#if !JKJ_HAS_BIT_CAST
                template <class T>
                using is_trivially_copyable = JKJ_STD_REPLACEMENT_NAMESPACE::is_trivially_copyable<T>;
#endif
                template <class T>
                using is_integral = JKJ_STD_REPLACEMENT_NAMESPACE::is_integral<T>;
                template <class T>
                using is_signed = JKJ_STD_REPLACEMENT_NAMESPACE::is_signed<T>;
                template <class T>
                using is_unsigned = JKJ_STD_REPLACEMENT_NAMESPACE::is_unsigned<T>;
            }
        }


        ////////////////////////////////////////////////////////////////////////////////////////
        // Some general utilities for C++11-compatibility.
        ////////////////////////////////////////////////////////////////////////////////////////
        namespace detail {
#if !JKJ_HAS_CONSTEXPR17
            template <stdr::size_t... indices>
            struct index_sequence {};

            template <stdr::size_t current, stdr::size_t total, class Dummy, stdr::size_t... indices>
            struct make_index_sequence_impl {
                using type = typename make_index_sequence_impl<current + 1, total, Dummy, indices...,
                                                               current>::type;
            };

            template <stdr::size_t total, class Dummy, stdr::size_t... indices>
            struct make_index_sequence_impl<total, total, Dummy, indices...> {
                using type = index_sequence<indices...>;
            };

            template <stdr::size_t N>
            using make_index_sequence = typename make_index_sequence_impl<0, N, void>::type;
#endif

            // Available since C++11, but including <utility> just for this is an overkill.
            template <class T>
            typename stdr::add_rvalue_reference<T>::type declval() noexcept;

            // Similarly, including <array> is an overkill.
            template <class T, stdr::size_t N>
            struct array {
                T data_[N];
                constexpr T operator[](stdr::size_t idx) const noexcept { return data_[idx]; }
                JKJ_CONSTEXPR14 T& operator[](stdr::size_t idx) noexcept { return data_[idx]; }
            };
        }


        ////////////////////////////////////////////////////////////////////////////////////////
        // Some basic features for encoding/decoding IEEE-754 formats.
        ////////////////////////////////////////////////////////////////////////////////////////
        namespace detail {
            template <class T>
            struct physical_bits {
                static constexpr stdr::size_t value =
                    sizeof(T) * stdr::numeric_limits<unsigned char>::digits;
            };
            template <class T>
            struct value_bits {
                static constexpr stdr::size_t value = stdr::numeric_limits<
                    typename stdr::enable_if<stdr::is_integral<T>::value, T>::type>::digits;
            };

            template <typename To, typename From>
            JKJ_CONSTEXPR20 To bit_cast(const From& from) {
#if JKJ_HAS_BIT_CAST
                return stdr::bit_cast<To>(from);
#else
                static_assert(sizeof(From) == sizeof(To), "");
                static_assert(stdr::is_trivially_copyable<To>::value, "");
                static_assert(stdr::is_trivially_copyable<From>::value, "");
                To to;
                stdr::memcpy(&to, &from, sizeof(To));
                return to;
#endif
            }
        }

        // These classes expose encoding specs of IEEE-754-like floating-point formats.
        // Currently available formats are IEEE-754 binary32 & IEEE-754 binary64.

        struct ieee754_binary32 {
            static constexpr int total_bits = 32;
            static constexpr int significand_bits = 23;
            static constexpr int exponent_bits = 8;
            static constexpr int min_exponent = -126;
            static constexpr int max_exponent = 127;
            static constexpr int exponent_bias = -127;
            static constexpr int decimal_significand_digits = 9;
            static constexpr int decimal_exponent_digits = 2;
        };
        struct ieee754_binary64 {
            static constexpr int total_bits = 64;
            static constexpr int significand_bits = 52;
            static constexpr int exponent_bits = 11;
            static constexpr int min_exponent = -1022;
            static constexpr int max_exponent = 1023;
            static constexpr int exponent_bias = -1023;
            static constexpr int decimal_significand_digits = 17;
            static constexpr int decimal_exponent_digits = 3;
        };

        // A floating-point format traits class defines ways to interpret a bit pattern of given size as
        // an encoding of floating-point number. This is an implementation of such a traits class,
        // supporting ways to interpret IEEE-754 binary floating-point numbers.
        template <class Format, class CarrierUInt, class ExponentInt = int>
        struct ieee754_binary_traits {
            // CarrierUInt needs to have enough size to hold the entire contents of floating-point
            // numbers. The actual bits are assumed to be aligned to the LSB, and every other bits are
            // assumed to be zeroed.
            static_assert(detail::value_bits<CarrierUInt>::value >= Format::total_bits,
                          "jkj::dragonbox: insufficient number of bits");
            static_assert(detail::stdr::is_unsigned<CarrierUInt>::value, "");

            // ExponentUInt needs to be large enough to hold (unsigned) exponent bits as well as the
            // (signed) actual exponent.
            // TODO: static overflow guard against intermediate computations.
            static_assert(detail::value_bits<ExponentInt>::value >= Format::exponent_bits + 1,
                          "jkj::dragonbox: insufficient number of bits");
            static_assert(detail::stdr::is_signed<ExponentInt>::value, "");

            using format = Format;
            using carrier_uint = CarrierUInt;
            static constexpr int carrier_bits = int(detail::value_bits<carrier_uint>::value);
            using exponent_int = ExponentInt;

            // Extract exponent bits from a bit pattern.
            // The result must be aligned to the LSB so that there is no additional zero paddings
            // on the right. This function does not do bias adjustment.
            static constexpr exponent_int extract_exponent_bits(carrier_uint u) noexcept {
                return exponent_int((u >> format::significand_bits) &
                                    ((exponent_int(1) << format::exponent_bits) - 1));
            }

            // Extract significand bits from a bit pattern.
            // The result must be aligned to the LSB so that there is no additional zero paddings
            // on the right. The result does not contain the implicit bit.
            static constexpr carrier_uint extract_significand_bits(carrier_uint u) noexcept {
                return carrier_uint(u & ((carrier_uint(1) << format::significand_bits) - 1u));
            }

            // Remove the exponent bits and extract significand bits together with the sign bit.
            static constexpr carrier_uint remove_exponent_bits(carrier_uint u) noexcept {
                return carrier_uint(u & ~(((carrier_uint(1) << format::exponent_bits) - 1u)
                                          << format::significand_bits));
            }

            // Shift the obtained signed significand bits to the left by 1 to remove the sign bit.
            static constexpr carrier_uint remove_sign_bit_and_shift(carrier_uint u) noexcept {
                return carrier_uint((carrier_uint(u) << 1) &
                                    ((((carrier_uint(1) << (Format::total_bits - 1)) - 1u) << 1) | 1u));
            }

            // Obtain the actual value of the binary exponent from the extracted exponent bits.
            static constexpr exponent_int binary_exponent(exponent_int exponent_bits) noexcept {
                return exponent_int(exponent_bits == 0 ? format::min_exponent
                                                       : exponent_bits + format::exponent_bias);
            }

            // Obtain the actual value of the binary significand from the extracted significand bits
            // and exponent bits.
            static constexpr carrier_uint binary_significand(carrier_uint significand_bits,
                                                             exponent_int exponent_bits) noexcept {
                return carrier_uint(
                    exponent_bits == 0
                        ? significand_bits
                        : (significand_bits | (carrier_uint(1) << format::significand_bits)));
            }

            /* Various boolean observer functions */

            static constexpr bool is_nonzero(carrier_uint u) noexcept {
                return (u & ((carrier_uint(1) << (format::significand_bits + format::exponent_bits)) -
                             1u)) != 0;
            }
            static constexpr bool is_positive(carrier_uint u) noexcept {
                return u < (carrier_uint(1) << (format::significand_bits + format::exponent_bits));
            }
            static constexpr bool is_negative(carrier_uint u) noexcept { return !is_positive(u); }
            static constexpr bool is_finite(exponent_int exponent_bits) noexcept {
                return exponent_bits != ((exponent_int(1) << format::exponent_bits) - 1);
            }
            static constexpr bool has_all_zero_significand_bits(carrier_uint u) noexcept {
                return ((u << 1) &
                        ((((carrier_uint(1) << (Format::total_bits - 1)) - 1u) << 1) | 1u)) == 0;
            }
            static constexpr bool has_even_significand_bits(carrier_uint u) noexcept {
                return u % 2 == 0;
            }
        };

        // Convert between bit patterns stored in carrier_uint and instances of an actual
        // floating-point type. Depending on format and carrier_uint, this operation might not
        // be possible for some specific bit patterns. However, the contract is that u always
        // denotes a valid bit pattern, so the functions here are assumed to be noexcept.
        // Users might specialize this class to change the behavior for certain types.
        // The default provided by the library is to treat the given floating-point type Float as either
        // IEEE-754 binary32 or IEEE-754 binary64, depending on the bitwise size of Float.
        template <class Float>
        struct default_float_bit_carrier_conversion_traits {
            // Guards against types that have different internal representations than IEEE-754
            // binary32/64. I don't know if there is a truly reliable way of detecting IEEE-754 binary
            // formats. I just did my best here. Note that in some cases
            // numeric_limits<Float>::is_iec559 may report false even if the internal representation is
            // IEEE-754 compatible. In such a case, the user can specialize this traits template and
            // remove this static sanity check in order to make Dragonbox work for Float.
            static_assert(detail::stdr::numeric_limits<Float>::is_iec559 &&
                              detail::stdr::numeric_limits<Float>::radix == 2 &&
                              (detail::physical_bits<Float>::value == 32 ||
                               detail::physical_bits<Float>::value == 64),
                          "jkj::dragonbox: Float may not be of IEEE-754 binary32/binary64");

            // Specifies the unsigned integer type to hold bitwise value of Float.
            using carrier_uint =
                typename detail::stdr::conditional<detail::physical_bits<Float>::value == 32,
                                                   detail::stdr::uint_least32_t,
                                                   detail::stdr::uint_least64_t>::type;

            // Specifies the floating-point format.
            using format = typename detail::stdr::conditional<detail::physical_bits<Float>::value == 32,
                                                              ieee754_binary32, ieee754_binary64>::type;

            // Converts the floating-point type into the bit-carrier unsigned integer type.
            static JKJ_CONSTEXPR20 carrier_uint float_to_carrier(Float x) noexcept {
                return detail::bit_cast<carrier_uint>(x);
            }

            // Converts the bit-carrier unsigned integer type into the floating-point type.
            static JKJ_CONSTEXPR20 Float carrier_to_float(carrier_uint x) noexcept {
                return detail::bit_cast<Float>(x);
            }
        };

        // Convenient wrappers for floating-point traits classes.
        // In order to reduce the argument passing overhead, these classes should be as simple as
        // possible (e.g., no inheritance, no private non-static data member, etc.; this is an
        // unfortunate fact about common ABI convention).

        template <class FormatTraits>
        struct signed_significand_bits {
            using format_traits = FormatTraits;
            using carrier_uint = typename format_traits::carrier_uint;

            carrier_uint u;

            signed_significand_bits() = default;
            constexpr explicit signed_significand_bits(carrier_uint bit_pattern) noexcept
                : u{bit_pattern} {}

            // Shift the obtained signed significand bits to the left by 1 to remove the sign bit.
            constexpr carrier_uint remove_sign_bit_and_shift() const noexcept {
                return format_traits::remove_sign_bit_and_shift(u);
            }

            constexpr bool is_positive() const noexcept { return format_traits::is_positive(u); }
            constexpr bool is_negative() const noexcept { return format_traits::is_negative(u); }
            constexpr bool has_all_zero_significand_bits() const noexcept {
                return format_traits::has_all_zero_significand_bits(u);
            }
            constexpr bool has_even_significand_bits() const noexcept {
                return format_traits::has_even_significand_bits(u);
            }
        };

        template <class FormatTraits>
        struct float_bits {
            using format_traits = FormatTraits;
            using carrier_uint = typename format_traits::carrier_uint;
            using exponent_int = typename format_traits::exponent_int;

            carrier_uint u;

            float_bits() = default;
            constexpr explicit float_bits(carrier_uint bit_pattern) noexcept : u{bit_pattern} {}

            // Extract exponent bits from a bit pattern.
            // The result must be aligned to the LSB so that there is no additional zero paddings
            // on the right. This function does not do bias adjustment.
            constexpr exponent_int extract_exponent_bits() const noexcept {
                return format_traits::extract_exponent_bits(u);
            }

            // Extract significand bits from a bit pattern.
            // The result must be aligned to the LSB so that there is no additional zero paddings
            // on the right. The result does not contain the implicit bit.
            constexpr carrier_uint extract_significand_bits() const noexcept {
                return format_traits::extract_significand_bits(u);
            }

            // Remove the exponent bits and extract significand bits together with the sign bit.
            constexpr signed_significand_bits<format_traits> remove_exponent_bits() const noexcept {
                return signed_significand_bits<format_traits>(format_traits::remove_exponent_bits(u));
            }

            // Obtain the actual value of the binary exponent from the extracted exponent bits.
            static constexpr exponent_int binary_exponent(exponent_int exponent_bits) noexcept {
                return format_traits::binary_exponent(exponent_bits);
            }
            constexpr exponent_int binary_exponent() const noexcept {
                return binary_exponent(extract_exponent_bits());
            }

            // Obtain the actual value of the binary exponent from the extracted significand bits
            // and exponent bits.
            static constexpr carrier_uint binary_significand(carrier_uint significand_bits,
                                                             exponent_int exponent_bits) noexcept {
                return format_traits::binary_significand(significand_bits, exponent_bits);
            }
            constexpr carrier_uint binary_significand() const noexcept {
                return binary_significand(extract_significand_bits(), extract_exponent_bits());
            }

            constexpr bool is_nonzero() const noexcept { return format_traits::is_nonzero(u); }
            constexpr bool is_positive() const noexcept { return format_traits::is_positive(u); }
            constexpr bool is_negative() const noexcept { return format_traits::is_negative(u); }
            constexpr bool is_finite(exponent_int exponent_bits) const noexcept {
                return format_traits::is_finite(exponent_bits);
            }
            constexpr bool is_finite() const noexcept {
                return format_traits::is_finite(extract_exponent_bits());
            }
            constexpr bool has_even_significand_bits() const noexcept {
                return format_traits::has_even_significand_bits(u);
            }
        };

        template <class Float,
                  class ConversionTraits = default_float_bit_carrier_conversion_traits<Float>,
                  class FormatTraits = ieee754_binary_traits<typename ConversionTraits::format,
                                                             typename ConversionTraits::carrier_uint>>
        JKJ_CONSTEXPR20 float_bits<FormatTraits> make_float_bits(Float x) noexcept {
            return float_bits<FormatTraits>(ConversionTraits::float_to_carrier(x));
        }

        namespace detail {
            ////////////////////////////////////////////////////////////////////////////////////////
            // Bit operation intrinsics.
            ////////////////////////////////////////////////////////////////////////////////////////

            namespace bits {
                // Most compilers should be able to optimize this into the ROR instruction.
                // n is assumed to be at most of bit_width bits.
                template <stdr::size_t bit_width, class UInt>
                JKJ_CONSTEXPR14 UInt rotr(UInt n, unsigned int r) noexcept {
                    static_assert(bit_width > 0, "jkj::dragonbox: rotation bit-width must be positive");
                    static_assert(bit_width <= value_bits<UInt>::value,
                                  "jkj::dragonbox: rotation bit-width is too large");
                    r &= (bit_width - 1);
                    return (n >> r) | (n << ((bit_width - r) & (bit_width - 1)));
                }
            }

            ////////////////////////////////////////////////////////////////////////////////////////
            // Utilities for wide unsigned integer arithmetic.
            ////////////////////////////////////////////////////////////////////////////////////////

            namespace wuint {
                // Compilers might support built-in 128-bit integer types. However, it seems that
                // emulating them with a pair of 64-bit integers actually produces a better code,
                // so we avoid using those built-ins. That said, they are still useful for
                // implementing 64-bit x 64-bit -> 128-bit multiplication.

                // clang-format off
#if defined(__SIZEOF_INT128__)
		// To silence "error: ISO C++ does not support '__int128' for 'type name'
		// [-Wpedantic]"
#if defined(__GNUC__)
			__extension__
#endif
			using builtin_uint128_t = unsigned __int128;
#endif
                // clang-format on

                struct uint128 {
                    uint128() = default;

                    stdr::uint_least64_t high_;
                    stdr::uint_least64_t low_;

                    constexpr uint128(stdr::uint_least64_t high, stdr::uint_least64_t low) noexcept
                        : high_{high}, low_{low} {}

                    constexpr stdr::uint_least64_t high() const noexcept { return high_; }
                    constexpr stdr::uint_least64_t low() const noexcept { return low_; }

                    JKJ_CONSTEXPR20 uint128& operator+=(stdr::uint_least64_t n) & noexcept {
                        auto const generic_impl = [&] {
                            auto const sum = (low_ + n) & UINT64_C(0xffffffffffffffff);
                            high_ += (sum < low_ ? 1 : 0);
                            low_ = sum;
                        };
                        // To suppress warning.
                        static_cast<void>(generic_impl);

                        JKJ_IF_CONSTEXPR(value_bits<stdr::uint_least64_t>::value > 64) {
                            generic_impl();
                            return *this;
                        }

                        JKJ_IF_CONSTEVAL {
                            generic_impl();
                            return *this;
                        }

                        // See https://github.com/fmtlib/fmt/pull/2985.
#if JKJ_HAS_BUILTIN(__builtin_addcll) && !defined(__ibmxl__)
                        JKJ_IF_CONSTEXPR(
                            stdr::is_same<stdr::uint_least64_t, unsigned long long>::value) {
                            unsigned long long carry{};
                            low_ = stdr::uint_least64_t(__builtin_addcll(low_, n, 0, &carry));
                            high_ = stdr::uint_least64_t(__builtin_addcll(high_, 0, carry, &carry));
                            return *this;
                        }
#endif
#if JKJ_HAS_BUILTIN(__builtin_addcl) && !defined(__ibmxl__)
                        JKJ_IF_CONSTEXPR(stdr::is_same<stdr::uint_least64_t, unsigned long>::value) {
                            unsigned long carry{};
                            low_ = stdr::uint_least64_t(
                                __builtin_addcl(static_cast<unsigned long>(low_),
                                                static_cast<unsigned long>(n), 0, &carry));
                            high_ = stdr::uint_least64_t(
                                __builtin_addcl(static_cast<unsigned long>(high_), 0, carry, &carry));
                            return *this;
                        }
#endif
#if JKJ_HAS_BUILTIN(__builtin_addc) && !defined(__ibmxl__)
                        JKJ_IF_CONSTEXPR(stdr::is_same<stdr::uint_least64_t, unsigned int>::value) {
                            unsigned int carry{};
                            low_ = stdr::uint_least64_t(__builtin_addc(static_cast<unsigned int>(low_),
                                                                       static_cast<unsigned int>(n), 0,
                                                                       &carry));
                            high_ = stdr::uint_least64_t(
                                __builtin_addc(static_cast<unsigned int>(high_), 0, carry, &carry));
                            return *this;
                        }
#endif

#if JKJ_HAS_BUILTIN(__builtin_ia32_addcarry_u64)
                        // __builtin_ia32_addcarry_u64 is not documented, but it seems it takes unsigned
                        // long long arguments.
                        unsigned long long result{};
                        auto const carry = __builtin_ia32_addcarry_u64(0, low_, n, &result);
                        low_ = stdr::uint_least64_t(result);
                        __builtin_ia32_addcarry_u64(carry, high_, 0, &result);
                        high_ = stdr::uint_least64_t(result);
#elif defined(_MSC_VER) && defined(_M_X64)
                        // On MSVC, uint_least64_t and __int64 must be unsigned long long; see
                        // https://learn.microsoft.com/en-us/cpp/c-runtime-library/standard-types
                        // and https://learn.microsoft.com/en-us/cpp/cpp/int8-int16-int32-int64.
                        static_assert(stdr::is_same<unsigned long long, stdr::uint_least64_t>::value,
                                      "");
                        auto const carry = _addcarry_u64(0, low_, n, &low_);
                        _addcarry_u64(carry, high_, 0, &high_);
#elif defined(__INTEL_COMPILER) && (defined(_M_X64) || defined(__x86_64))
                        // Cannot find any documentation on how things are defined, but hopefully this
                        // is always true...
                        static_assert(stdr::is_same<unsigned __int64, stdr::uint_least64_t>::value, "");
                        auto const carry = _addcarry_u64(0, low_, n, &low_);
                        _addcarry_u64(carry, high_, 0, &high_);
#else
                        generic_impl();
#endif
                        return *this;
                    }
                };

                inline JKJ_CONSTEXPR20 stdr::uint_least64_t umul64(stdr::uint_least32_t x,
                                                                   stdr::uint_least32_t y) noexcept {
#if defined(_MSC_VER) && defined(_M_IX86)
                    JKJ_IF_NOT_CONSTEVAL { return __emulu(x, y); }
#endif
                    return x * stdr::uint_least64_t(y);
                }

                // Get 128-bit result of multiplication of two 64-bit unsigned integers.
                JKJ_SAFEBUFFERS inline JKJ_CONSTEXPR20 uint128
                umul128(stdr::uint_least64_t x, stdr::uint_least64_t y) noexcept {
                    auto const generic_impl = [=]() -> uint128 {
                        auto const a = stdr::uint_least32_t(x >> 32);
                        auto const b = stdr::uint_least32_t(x);
                        auto const c = stdr::uint_least32_t(y >> 32);
                        auto const d = stdr::uint_least32_t(y);

                        auto const ac = umul64(a, c);
                        auto const bc = umul64(b, c);
                        auto const ad = umul64(a, d);
                        auto const bd = umul64(b, d);

                        auto const intermediate =
                            (bd >> 32) + stdr::uint_least32_t(ad) + stdr::uint_least32_t(bc);

                        return {ac + (intermediate >> 32) + (ad >> 32) + (bc >> 32),
                                (intermediate << 32) + stdr::uint_least32_t(bd)};
                    };
                    // To silence warning.
                    static_cast<void>(generic_impl);

#if defined(__SIZEOF_INT128__)
                    auto const result = builtin_uint128_t(x) * builtin_uint128_t(y);
                    return {stdr::uint_least64_t(result >> 64), stdr::uint_least64_t(result)};
#elif defined(_MSC_VER) && defined(_M_X64)
                    JKJ_IF_CONSTEVAL {
                        // This redundant variable is to workaround MSVC's codegen bug caused by the
                        // interaction of NRVO and intrinsics.
                        auto const result = generic_impl();
                        return result;
                    }
                    uint128 result;
    #if defined(__AVX2__)
                    result.low_ = _mulx_u64(x, y, &result.high_);
    #else
                    result.low_ = _umul128(x, y, &result.high_);
    #endif
                    return result;
#else
                    return generic_impl();
#endif
                }

                // Get high half of the 128-bit result of multiplication of two 64-bit unsigned
                // integers.
                JKJ_SAFEBUFFERS inline JKJ_CONSTEXPR20 stdr::uint_least64_t
                umul128_upper64(stdr::uint_least64_t x, stdr::uint_least64_t y) noexcept {
                    auto const generic_impl = [=]() -> stdr::uint_least64_t {
                        auto const a = stdr::uint_least32_t(x >> 32);
                        auto const b = stdr::uint_least32_t(x);
                        auto const c = stdr::uint_least32_t(y >> 32);
                        auto const d = stdr::uint_least32_t(y);

                        auto const ac = umul64(a, c);
                        auto const bc = umul64(b, c);
                        auto const ad = umul64(a, d);
                        auto const bd = umul64(b, d);

                        auto const intermediate =
                            (bd >> 32) + stdr::uint_least32_t(ad) + stdr::uint_least32_t(bc);

                        return ac + (intermediate >> 32) + (ad >> 32) + (bc >> 32);
                    };
                    // To silence warning.
                    static_cast<void>(generic_impl);

#if defined(__SIZEOF_INT128__)
                    auto const result = builtin_uint128_t(x) * builtin_uint128_t(y);
                    return stdr::uint_least64_t(result >> 64);
#elif defined(_MSC_VER) && defined(_M_X64)
                    JKJ_IF_CONSTEVAL {
                        // This redundant variable is to workaround MSVC's codegen bug caused by the
                        // interaction of NRVO and intrinsics.
                        auto const result = generic_impl();
                        return result;
                    }
                    stdr::uint_least64_t result;
    #if defined(__AVX2__)
                    _mulx_u64(x, y, &result);
    #else
                    result = __umulh(x, y);
    #endif
                    return result;
#else
                    return generic_impl();
#endif
                }

                // Get upper 128-bits of multiplication of a 64-bit unsigned integer and a 128-bit
                // unsigned integer.
                JKJ_SAFEBUFFERS inline JKJ_CONSTEXPR20 uint128 umul192_upper128(stdr::uint_least64_t x,
                                                                                uint128 y) noexcept {
                    auto r = umul128(x, y.high());
                    r += umul128_upper64(x, y.low());
                    return r;
                }

                // Get upper 64-bits of multiplication of a 32-bit unsigned integer and a 64-bit
                // unsigned integer.
                inline JKJ_CONSTEXPR20 stdr::uint_least64_t
                umul96_upper64(stdr::uint_least32_t x, stdr::uint_least64_t y) noexcept {
#if defined(__SIZEOF_INT128__) || (defined(_MSC_VER) && defined(_M_X64))
                    return umul128_upper64(stdr::uint_least64_t(x) << 32, y);
#else
                    auto const yh = stdr::uint_least32_t(y >> 32);
                    auto const yl = stdr::uint_least32_t(y);

                    auto const xyh = umul64(x, yh);
                    auto const xyl = umul64(x, yl);

                    return xyh + (xyl >> 32);
#endif
                }

                // Get lower 128-bits of multiplication of a 64-bit unsigned integer and a 128-bit
                // unsigned integer.
                JKJ_SAFEBUFFERS inline JKJ_CONSTEXPR20 uint128 umul192_lower128(stdr::uint_least64_t x,
                                                                                uint128 y) noexcept {
                    auto const high = x * y.high();
                    auto const high_low = umul128(x, y.low());
                    return {(high + high_low.high()) & UINT64_C(0xffffffffffffffff), high_low.low()};
                }

                // Get lower 64-bits of multiplication of a 32-bit unsigned integer and a 64-bit
                // unsigned integer.
                constexpr stdr::uint_least64_t umul96_lower64(stdr::uint_least32_t x,
                                                              stdr::uint_least64_t y) noexcept {
                    return (x * y) & UINT64_C(0xffffffffffffffff);
                }
            }

            ////////////////////////////////////////////////////////////////////////////////////////
            // Some simple utilities for constexpr computation.
            ////////////////////////////////////////////////////////////////////////////////////////

            template <int k, class Int>
            constexpr Int compute_power(Int a) noexcept {
                static_assert(k >= 0, "");
#if JKJ_HAS_CONSTEXPR14
                Int p = 1;
                for (int i = 0; i < k; ++i) {
                    p *= a;
                }
                return p;
#else
                return k == 0       ? 1
                       : k % 2 == 0 ? compute_power<k / 2, Int>(a * a)
                                    : a * compute_power<k / 2, Int>(a * a);
#endif
            }

            template <int a, class UInt>
            constexpr int count_factors(UInt n) noexcept {
                static_assert(a > 1, "");
#if JKJ_HAS_CONSTEXPR14
                int c = 0;
                while (n % a == 0) {
                    n /= a;
                    ++c;
                }
                return c;
#else
                return n % a == 0 ? count_factors<a, UInt>(n / a) + 1 : 0;
#endif
            }

            ////////////////////////////////////////////////////////////////////////////////////////
            // Utilities for fast/constexpr log computation.
            ////////////////////////////////////////////////////////////////////////////////////////

            namespace log {
                static_assert((stdr::int_fast32_t(-1) >> 1) == stdr::int_fast32_t(-1) &&
                                  (stdr::int_fast16_t(-1) >> 1) == stdr::int_fast16_t(-1),
                              "jkj::dragonbox: right-shift for signed integers must be arithmetic");

                // For constexpr computation.
                // Returns -1 when n = 0.
                template <class UInt>
                constexpr int floor_log2(UInt n) noexcept {
#if JKJ_HAS_CONSTEXPR14
                    int count = -1;
                    while (n != 0) {
                        ++count;
                        n >>= 1;
                    }
                    return count;
#else
                    return n == 0 ? -1 : floor_log2<UInt>(n / 2) + 1;
#endif
                }

                template <template <stdr::size_t> class Info, stdr::int_least32_t min_exponent,
                          stdr::int_least32_t max_exponent, stdr::size_t current_tier,
                          stdr::int_least32_t supported_min_exponent = Info<current_tier>::min_exponent,
                          stdr::int_least32_t supported_max_exponent = Info<current_tier>::max_exponent>
                constexpr bool is_in_range(int) noexcept {
                    return min_exponent >= supported_min_exponent &&
                           max_exponent <= supported_max_exponent;
                }
                template <template <stdr::size_t> class Info, stdr::int_least32_t min_exponent,
                          stdr::int_least32_t max_exponent, stdr::size_t current_tier>
                constexpr bool is_in_range(...) noexcept {
                    // Supposed to be always false, but formally dependent on the template parameters.
                    static_assert(min_exponent > max_exponent,
                                  "jkj::dragonbox: exponent range is too wide");
                    return false;
                }

                template <template <stdr::size_t> class Info, stdr::int_least32_t min_exponent,
                          stdr::int_least32_t max_exponent, stdr::size_t current_tier = 0,
                          bool = is_in_range<Info, min_exponent, max_exponent, current_tier>(0)>
                struct compute_impl;

                template <template <stdr::size_t> class Info, stdr::int_least32_t min_exponent,
                          stdr::int_least32_t max_exponent, stdr::size_t current_tier>
                struct compute_impl<Info, min_exponent, max_exponent, current_tier, true> {
                    using info = Info<current_tier>;
                    using default_return_type = typename info::default_return_type;
                    template <class ReturnType, class Int>
                    static constexpr ReturnType compute(Int e) noexcept {
#if JKJ_HAS_CONSTEXPR14
                        assert(min_exponent <= e && e <= max_exponent);
#endif
                        // The sign is irrelevant for the mathematical validity of the formula, but
                        // assuming positivity makes the overflow analysis simpler.
                        static_assert(info::multiply >= 0 && info::subtract >= 0, "");
                        return static_cast<ReturnType>((e * info::multiply - info::subtract) >>
                                                       info::shift);
                    }
                };

                template <template <stdr::size_t> class Info, stdr::int_least32_t min_exponent,
                          stdr::int_least32_t max_exponent, stdr::size_t current_tier>
                struct compute_impl<Info, min_exponent, max_exponent, current_tier, false> {
                    using next_tier = compute_impl<Info, min_exponent, max_exponent, current_tier + 1>;
                    using default_return_type = typename next_tier::default_return_type;
                    template <class ReturnType, class Int>
                    static constexpr ReturnType compute(Int e) noexcept {
                        return next_tier::template compute<ReturnType>(e);
                    }
                };

                template <stdr::size_t tier>
                struct floor_log10_pow2_info;
                template <>
                struct floor_log10_pow2_info<0> {
                    using default_return_type = stdr::int_fast8_t;
                    static constexpr stdr::int_fast16_t multiply = 77;
                    static constexpr stdr::int_fast16_t subtract = 0;
                    static constexpr stdr::size_t shift = 8;
                    static constexpr stdr::int_least32_t min_exponent = -102;
                    static constexpr stdr::int_least32_t max_exponent = 102;
                };
                template <>
                struct floor_log10_pow2_info<1> {
                    using default_return_type = stdr::int_fast8_t;
                    // 24-bits are enough in fact.
                    static constexpr stdr::int_fast32_t multiply = 1233;
                    static constexpr stdr::int_fast32_t subtract = 0;
                    static constexpr stdr::size_t shift = 12;
                    // Formula itself holds on [-680,680]; [-425,425] is to ensure that the output is
                    // within [-127,127].
                    static constexpr stdr::int_least32_t min_exponent = -425;
                    static constexpr stdr::int_least32_t max_exponent = 425;
                };
                template <>
                struct floor_log10_pow2_info<2> {
                    using default_return_type = stdr::int_fast16_t;
                    static constexpr stdr::int_fast32_t multiply = INT32_C(315653);
                    static constexpr stdr::int_fast32_t subtract = 0;
                    static constexpr stdr::size_t shift = 20;
                    static constexpr stdr::int_least32_t min_exponent = -2620;
                    static constexpr stdr::int_least32_t max_exponent = 2620;
                };
                template <stdr::int_least32_t min_exponent = -2620,
                          stdr::int_least32_t max_exponent = 2620,
                          class ReturnType = typename compute_impl<floor_log10_pow2_info, min_exponent,
                                                                   max_exponent>::default_return_type,
                          class Int>
                constexpr ReturnType floor_log10_pow2(Int e) noexcept {
                    return compute_impl<floor_log10_pow2_info, min_exponent,
                                        max_exponent>::template compute<ReturnType>(e);
                }

                template <stdr::size_t tier>
                struct floor_log2_pow10_info;
                template <>
                struct floor_log2_pow10_info<0> {
                    using default_return_type = stdr::int_fast8_t;
                    static constexpr stdr::int_fast16_t multiply = 53;
                    static constexpr stdr::int_fast16_t subtract = 0;
                    static constexpr stdr::size_t shift = 4;
                    static constexpr stdr::int_least32_t min_exponent = -15;
                    static constexpr stdr::int_least32_t max_exponent = 18;
                };
                template <>
                struct floor_log2_pow10_info<1> {
                    using default_return_type = stdr::int_fast16_t;
                    // 24-bits are enough in fact.
                    static constexpr stdr::int_fast32_t multiply = 1701;
                    static constexpr stdr::int_fast32_t subtract = 0;
                    static constexpr stdr::size_t shift = 9;
                    static constexpr stdr::int_least32_t min_exponent = -58;
                    static constexpr stdr::int_least32_t max_exponent = 58;
                };
                template <>
                struct floor_log2_pow10_info<2> {
                    using default_return_type = stdr::int_fast16_t;
                    static constexpr stdr::int_fast32_t multiply = INT32_C(1741647);
                    static constexpr stdr::int_fast32_t subtract = 0;
                    static constexpr stdr::size_t shift = 19;
                    // Formula itself holds on [-4003,4003]; [-1233,1233] is to ensure no overflow.
                    static constexpr stdr::int_least32_t min_exponent = -1233;
                    static constexpr stdr::int_least32_t max_exponent = 1233;
                };
                template <stdr::int_least32_t min_exponent = -1233,
                          stdr::int_least32_t max_exponent = 1233,
                          class ReturnType = typename compute_impl<floor_log2_pow10_info, min_exponent,
                                                                   max_exponent>::default_return_type,
                          class Int>
                constexpr ReturnType floor_log2_pow10(Int e) noexcept {
                    return compute_impl<floor_log2_pow10_info, min_exponent,
                                        max_exponent>::template compute<ReturnType>(e);
                }

                template <stdr::size_t tier>
                struct floor_log10_pow2_minus_log10_4_over_3_info;
                template <>
                struct floor_log10_pow2_minus_log10_4_over_3_info<0> {
                    using default_return_type = stdr::int_fast8_t;
                    static constexpr stdr::int_fast16_t multiply = 77;
                    static constexpr stdr::int_fast16_t subtract = 31;
                    static constexpr stdr::size_t shift = 8;
                    static constexpr stdr::int_least32_t min_exponent = -75;
                    static constexpr stdr::int_least32_t max_exponent = 129;
                };
                template <>
                struct floor_log10_pow2_minus_log10_4_over_3_info<1> {
                    using default_return_type = stdr::int_fast8_t;
                    // 24-bits are enough in fact.
                    static constexpr stdr::int_fast32_t multiply = 19728;
                    static constexpr stdr::int_fast32_t subtract = 8241;
                    static constexpr stdr::size_t shift = 16;
                    // Formula itself holds on [-849,315]; [-424,315] is to ensure that the output is
                    // within [-127,127].
                    static constexpr stdr::int_least32_t min_exponent = -424;
                    static constexpr stdr::int_least32_t max_exponent = 315;
                };
                template <>
                struct floor_log10_pow2_minus_log10_4_over_3_info<2> {
                    using default_return_type = stdr::int_fast16_t;
                    static constexpr stdr::int_fast32_t multiply = INT32_C(631305);
                    static constexpr stdr::int_fast32_t subtract = INT32_C(261663);
                    static constexpr stdr::size_t shift = 21;
                    static constexpr stdr::int_least32_t min_exponent = -2985;
                    static constexpr stdr::int_least32_t max_exponent = 2936;
                };
                template <stdr::int_least32_t min_exponent = -2985,
                          stdr::int_least32_t max_exponent = 2936,
                          class ReturnType =
                              typename compute_impl<floor_log10_pow2_minus_log10_4_over_3_info,
                                                    min_exponent, max_exponent>::default_return_type,
                          class Int>
                constexpr ReturnType floor_log10_pow2_minus_log10_4_over_3(Int e) noexcept {
                    return compute_impl<floor_log10_pow2_minus_log10_4_over_3_info, min_exponent,
                                        max_exponent>::template compute<ReturnType>(e);
                }

                template <stdr::size_t tier>
                struct floor_log5_pow2_info;
                template <>
                struct floor_log5_pow2_info<0> {
                    using default_return_type = stdr::int_fast32_t;
                    static constexpr stdr::int_fast32_t multiply = INT32_C(225799);
                    static constexpr stdr::int_fast32_t subtract = 0;
                    static constexpr stdr::size_t shift = 19;
                    static constexpr stdr::int_least32_t min_exponent = -1831;
                    static constexpr stdr::int_least32_t max_exponent = 1831;
                };
                template <stdr::int_least32_t min_exponent = -1831,
                          stdr::int_least32_t max_exponent = 1831,
                          class ReturnType = typename compute_impl<floor_log5_pow2_info, min_exponent,
                                                                   max_exponent>::default_return_type,
                          class Int>
                constexpr ReturnType floor_log5_pow2(Int e) noexcept {
                    return compute_impl<floor_log5_pow2_info, min_exponent,
                                        max_exponent>::template compute<ReturnType>(e);
                }

                template <stdr::size_t tier>
                struct floor_log5_pow2_minus_log5_3_info;
                template <>
                struct floor_log5_pow2_minus_log5_3_info<0> {
                    using default_return_type = stdr::int_fast32_t;
                    static constexpr stdr::int_fast32_t multiply = INT32_C(451597);
                    static constexpr stdr::int_fast32_t subtract = INT32_C(715764);
                    static constexpr stdr::size_t shift = 20;
                    static constexpr stdr::int_least32_t min_exponent = -3543;
                    static constexpr stdr::int_least32_t max_exponent = 2427;
                };
                template <stdr::int_least32_t min_exponent = -3543,
                          stdr::int_least32_t max_exponent = 2427,
                          class ReturnType =
                              typename compute_impl<floor_log5_pow2_minus_log5_3_info, min_exponent,
                                                    max_exponent>::default_return_type,
                          class Int>
                constexpr ReturnType floor_log5_pow2_minus_log5_3(Int e) noexcept {
                    return compute_impl<floor_log5_pow2_minus_log5_3_info, min_exponent,
                                        max_exponent>::template compute<ReturnType>(e);
                }
            }

            ////////////////////////////////////////////////////////////////////////////////////////
            // Utilities for fast divisibility tests.
            ////////////////////////////////////////////////////////////////////////////////////////

            namespace div {
                // Replace n by floor(n / 10^N).
                // Returns true if and only if n is divisible by 10^N.
                // Precondition: n <= 10^(N+1)
                // !!It takes an in-out parameter!!
                template <int N, class UInt>
                struct divide_by_pow10_info;

                template <class UInt>
                struct divide_by_pow10_info<1, UInt> {
                    static constexpr stdr::uint_fast32_t magic_number = 6554;
                    static constexpr int shift_amount = 16;
                };

                template <>
                struct divide_by_pow10_info<1, stdr::uint_least8_t> {
                    static constexpr stdr::uint_fast16_t magic_number = 103;
                    static constexpr int shift_amount = 10;
                };

                template <>
                struct divide_by_pow10_info<1, stdr::uint_least16_t> {
                    static constexpr stdr::uint_fast16_t magic_number = 103;
                    static constexpr int shift_amount = 10;
                };

                template <class UInt>
                struct divide_by_pow10_info<2, UInt> {
                    static constexpr stdr::uint_fast32_t magic_number = 656;
                    static constexpr int shift_amount = 16;
                };

                template <>
                struct divide_by_pow10_info<2, stdr::uint_least16_t> {
                    static constexpr stdr::uint_fast32_t magic_number = 41;
                    static constexpr int shift_amount = 12;
                };

                template <int N, class UInt>
                JKJ_CONSTEXPR14 bool check_divisibility_and_divide_by_pow10(UInt& n) noexcept {
                    // Make sure the computation for max_n does not overflow.
                    static_assert(N + 1 <= log::floor_log10_pow2(int(value_bits<UInt>::value)), "");
                    assert(n <= compute_power<N + 1>(UInt(10)));

                    using info = divide_by_pow10_info<N, UInt>;
                    using intermediate_type = decltype(info::magic_number);
                    auto const prod = intermediate_type(n * info::magic_number);

                    constexpr auto mask =
                        intermediate_type((intermediate_type(1) << info::shift_amount) - 1);
                    bool const result = ((prod & mask) < info::magic_number);

                    n = UInt(prod >> info::shift_amount);
                    return result;
                }

                // Compute floor(n / 10^N) for small n and N.
                // Precondition: n <= 10^(N+1)
                template <int N, class UInt>
                JKJ_CONSTEXPR14 UInt small_division_by_pow10(UInt n) noexcept {
                    // Make sure the computation for max_n does not overflow.
                    static_assert(N + 1 <= log::floor_log10_pow2(int(value_bits<UInt>::value)), "");
                    assert(n <= compute_power<N + 1>(UInt(10)));

                    return UInt((n * divide_by_pow10_info<N, UInt>::magic_number) >>
                                divide_by_pow10_info<N, UInt>::shift_amount);
                }

                // Compute floor(n / 10^N) for small N.
                // Precondition: n <= n_max
                template <int N, class UInt, UInt n_max>
                JKJ_CONSTEXPR20 UInt divide_by_pow10(UInt n) noexcept {
                    static_assert(N >= 0, "");

                    // Specialize for 32-bit division by 10.
                    // Without the bound on n_max (which compilers these days never leverage), the
                    // minimum needed amount of shift is larger than 32. Hence, this may generate better
                    // code for 32-bit or smaller architectures. Even for 64-bit architectures, it seems
                    // compilers tend to generate mov + mul instead of a single imul for an unknown
                    // reason if we just write n / 10.
                    JKJ_IF_CONSTEXPR(stdr::is_same<UInt, stdr::uint_least32_t>::value && N == 1 &&
                                     n_max <= UINT32_C(1073741828)) {
                        return UInt(wuint::umul64(n, UINT32_C(429496730)) >> 32);
                    }
                    // Specialize for 64-bit division by 10.
                    // Without the bound on n_max (which compilers these days never leverage), the
                    // minimum needed amount of shift is larger than 64.
                    else JKJ_IF_CONSTEXPR(stdr::is_same<UInt, stdr::uint_least64_t>::value && N == 1 &&
                                          n_max <= UINT64_C(4611686018427387908)) {
                        return UInt(wuint::umul128_upper64(n, UINT64_C(1844674407370955162)));
                    }
                    // Specialize for 32-bit division by 100.
                    // It seems compilers tend to generate mov + mul instead of a single imul for an
                    // unknown reason if we just write n / 100.
                    else JKJ_IF_CONSTEXPR(stdr::is_same<UInt, stdr::uint_least32_t>::value && N == 2) {
                        return UInt(wuint::umul64(n, UINT32_C(1374389535)) >> 37);
                    }
                    // Specialize for 64-bit division by 1000.
                    // Without the bound on n_max (which compilers these days never leverage), the
                    // smallest magic number for this computation does not fit into 64-bits.
                    else JKJ_IF_CONSTEXPR(stdr::is_same<UInt, stdr::uint_least64_t>::value && N == 3 &&
                                          n_max <= UINT64_C(15534100272597517998)) {
                        return UInt(wuint::umul128_upper64(n, UINT64_C(4722366482869645214)) >> 8);
                    }
                    else {
                        constexpr auto divisor = compute_power<N>(UInt(10));
                        return n / divisor;
                    }
                }
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        // Return types for the main interface function.
        ////////////////////////////////////////////////////////////////////////////////////////

        template <class SignificandType, class ExponentType, bool is_signed, bool trailing_zero_flag>
        struct decimal_fp;

        template <class SignificandType, class ExponentType>
        struct decimal_fp<SignificandType, ExponentType, false, false> {
            SignificandType significand;
            ExponentType exponent;
        };

        template <class SignificandType, class ExponentType>
        struct decimal_fp<SignificandType, ExponentType, true, false> {
            SignificandType significand;
            ExponentType exponent;
            bool is_negative;
        };

        template <class SignificandType, class ExponentType>
        struct decimal_fp<SignificandType, ExponentType, false, true> {
            SignificandType significand;
            ExponentType exponent;
            bool may_have_trailing_zeros;
        };

        template <class SignificandType, class ExponentType>
        struct decimal_fp<SignificandType, ExponentType, true, true> {
            SignificandType significand;
            ExponentType exponent;
            bool may_have_trailing_zeros;
            bool is_negative;
        };

        template <class SignificandType, class ExponentType, bool trailing_zero_flag = false>
        using unsigned_decimal_fp =
            decimal_fp<SignificandType, ExponentType, false, trailing_zero_flag>;

        template <class SignificandType, class ExponentType, bool trailing_zero_flag = false>
        using signed_decimal_fp = decimal_fp<SignificandType, ExponentType, true, trailing_zero_flag>;

        template <class SignificandType, class ExponentType>
        constexpr signed_decimal_fp<SignificandType, ExponentType, false>
        add_sign_to_unsigned_decimal_fp(
            bool is_negative, unsigned_decimal_fp<SignificandType, ExponentType, false> r) noexcept {
            return {r.significand, r.exponent, is_negative};
        }

        template <class SignificandType, class ExponentType>
        constexpr signed_decimal_fp<SignificandType, ExponentType, true>
        add_sign_to_unsigned_decimal_fp(
            bool is_negative, unsigned_decimal_fp<SignificandType, ExponentType, true> r) noexcept {
            return {r.significand, r.exponent, r.may_have_trailing_zeros, is_negative};
        }

        namespace detail {
            template <class UnsignedDecimalFp>
            struct unsigned_decimal_fp_to_signed;

            template <class SignificandType, class ExponentType, bool trailing_zero_flag>
            struct unsigned_decimal_fp_to_signed<
                unsigned_decimal_fp<SignificandType, ExponentType, trailing_zero_flag>> {
                using type = signed_decimal_fp<SignificandType, ExponentType, trailing_zero_flag>;
            };

            template <class UnsignedDecimalFp>
            using unsigned_decimal_fp_to_signed_t =
                typename unsigned_decimal_fp_to_signed<UnsignedDecimalFp>::type;
        }


        ////////////////////////////////////////////////////////////////////////////////////////
        // Computed cache entries.
        ////////////////////////////////////////////////////////////////////////////////////////

        template <class FloatFormat, class Dummy = void>
        struct cache_holder;

        template <class Dummy>
        struct cache_holder<ieee754_binary32, Dummy> {
            using cache_entry_type = detail::stdr::uint_least64_t;
            static constexpr int cache_bits = 64;
            static constexpr int min_k = -31;
            static constexpr int max_k = 46;
            static constexpr detail::array<cache_entry_type, detail::stdr::size_t(max_k - min_k + 1)>
                cache JKJ_STATIC_DATA_SECTION = {
                    {UINT64_C(0x81ceb32c4b43fcf5), UINT64_C(0xa2425ff75e14fc32),
                     UINT64_C(0xcad2f7f5359a3b3f), UINT64_C(0xfd87b5f28300ca0e),
                     UINT64_C(0x9e74d1b791e07e49), UINT64_C(0xc612062576589ddb),
                     UINT64_C(0xf79687aed3eec552), UINT64_C(0x9abe14cd44753b53),
                     UINT64_C(0xc16d9a0095928a28), UINT64_C(0xf1c90080baf72cb2),
                     UINT64_C(0x971da05074da7bef), UINT64_C(0xbce5086492111aeb),
                     UINT64_C(0xec1e4a7db69561a6), UINT64_C(0x9392ee8e921d5d08),
                     UINT64_C(0xb877aa3236a4b44a), UINT64_C(0xe69594bec44de15c),
                     UINT64_C(0x901d7cf73ab0acda), UINT64_C(0xb424dc35095cd810),
                     UINT64_C(0xe12e13424bb40e14), UINT64_C(0x8cbccc096f5088cc),
                     UINT64_C(0xafebff0bcb24aaff), UINT64_C(0xdbe6fecebdedd5bf),
                     UINT64_C(0x89705f4136b4a598), UINT64_C(0xabcc77118461cefd),
                     UINT64_C(0xd6bf94d5e57a42bd), UINT64_C(0x8637bd05af6c69b6),
                     UINT64_C(0xa7c5ac471b478424), UINT64_C(0xd1b71758e219652c),
                     UINT64_C(0x83126e978d4fdf3c), UINT64_C(0xa3d70a3d70a3d70b),
                     UINT64_C(0xcccccccccccccccd), UINT64_C(0x8000000000000000),
                     UINT64_C(0xa000000000000000), UINT64_C(0xc800000000000000),
                     UINT64_C(0xfa00000000000000), UINT64_C(0x9c40000000000000),
                     UINT64_C(0xc350000000000000), UINT64_C(0xf424000000000000),
                     UINT64_C(0x9896800000000000), UINT64_C(0xbebc200000000000),
                     UINT64_C(0xee6b280000000000), UINT64_C(0x9502f90000000000),
                     UINT64_C(0xba43b74000000000), UINT64_C(0xe8d4a51000000000),
                     UINT64_C(0x9184e72a00000000), UINT64_C(0xb5e620f480000000),
                     UINT64_C(0xe35fa931a0000000), UINT64_C(0x8e1bc9bf04000000),
                     UINT64_C(0xb1a2bc2ec5000000), UINT64_C(0xde0b6b3a76400000),
                     UINT64_C(0x8ac7230489e80000), UINT64_C(0xad78ebc5ac620000),
                     UINT64_C(0xd8d726b7177a8000), UINT64_C(0x878678326eac9000),
                     UINT64_C(0xa968163f0a57b400), UINT64_C(0xd3c21bcecceda100),
                     UINT64_C(0x84595161401484a0), UINT64_C(0xa56fa5b99019a5c8),
                     UINT64_C(0xcecb8f27f4200f3a), UINT64_C(0x813f3978f8940985),
                     UINT64_C(0xa18f07d736b90be6), UINT64_C(0xc9f2c9cd04674edf),
                     UINT64_C(0xfc6f7c4045812297), UINT64_C(0x9dc5ada82b70b59e),
                     UINT64_C(0xc5371912364ce306), UINT64_C(0xf684df56c3e01bc7),
                     UINT64_C(0x9a130b963a6c115d), UINT64_C(0xc097ce7bc90715b4),
                     UINT64_C(0xf0bdc21abb48db21), UINT64_C(0x96769950b50d88f5),
                     UINT64_C(0xbc143fa4e250eb32), UINT64_C(0xeb194f8e1ae525fe),
                     UINT64_C(0x92efd1b8d0cf37bf), UINT64_C(0xb7abc627050305ae),
                     UINT64_C(0xe596b7b0c643c71a), UINT64_C(0x8f7e32ce7bea5c70),
                     UINT64_C(0xb35dbf821ae4f38c), UINT64_C(0xe0352f62a19e306f)}};
        };
#if !JKJ_HAS_INLINE_VARIABLE
        // decltype(...) should not depend on Dummy; see
        // https://stackoverflow.com/questions/76438400/decltype-on-static-variable-in-template-class.
        template <class Dummy>
        constexpr decltype(cache_holder<ieee754_binary32>::cache)
            cache_holder<ieee754_binary32, Dummy>::cache;
#endif

        template <class Dummy>
        struct cache_holder<ieee754_binary64, Dummy> {
            using cache_entry_type = detail::wuint::uint128;
            static constexpr int cache_bits = 128;
            static constexpr int min_k = -292;
            static constexpr int max_k = 326;
            static constexpr detail::array<cache_entry_type, detail::stdr::size_t(max_k - min_k + 1)>
                cache JKJ_STATIC_DATA_SECTION = {
                    {{UINT64_C(0xff77b1fcbebcdc4f), UINT64_C(0x25e8e89c13bb0f7b)},
                     {UINT64_C(0x9faacf3df73609b1), UINT64_C(0x77b191618c54e9ad)},
                     {UINT64_C(0xc795830d75038c1d), UINT64_C(0xd59df5b9ef6a2418)},
                     {UINT64_C(0xf97ae3d0d2446f25), UINT64_C(0x4b0573286b44ad1e)},
                     {UINT64_C(0x9becce62836ac577), UINT64_C(0x4ee367f9430aec33)},
                     {UINT64_C(0xc2e801fb244576d5), UINT64_C(0x229c41f793cda740)},
                     {UINT64_C(0xf3a20279ed56d48a), UINT64_C(0x6b43527578c11110)},
                     {UINT64_C(0x9845418c345644d6), UINT64_C(0x830a13896b78aaaa)},
                     {UINT64_C(0xbe5691ef416bd60c), UINT64_C(0x23cc986bc656d554)},
                     {UINT64_C(0xedec366b11c6cb8f), UINT64_C(0x2cbfbe86b7ec8aa9)},
                     {UINT64_C(0x94b3a202eb1c3f39), UINT64_C(0x7bf7d71432f3d6aa)},
                     {UINT64_C(0xb9e08a83a5e34f07), UINT64_C(0xdaf5ccd93fb0cc54)},
                     {UINT64_C(0xe858ad248f5c22c9), UINT64_C(0xd1b3400f8f9cff69)},
                     {UINT64_C(0x91376c36d99995be), UINT64_C(0x23100809b9c21fa2)},
                     {UINT64_C(0xb58547448ffffb2d), UINT64_C(0xabd40a0c2832a78b)},
                     {UINT64_C(0xe2e69915b3fff9f9), UINT64_C(0x16c90c8f323f516d)},
                     {UINT64_C(0x8dd01fad907ffc3b), UINT64_C(0xae3da7d97f6792e4)},
                     {UINT64_C(0xb1442798f49ffb4a), UINT64_C(0x99cd11cfdf41779d)},
                     {UINT64_C(0xdd95317f31c7fa1d), UINT64_C(0x40405643d711d584)},
                     {UINT64_C(0x8a7d3eef7f1cfc52), UINT64_C(0x482835ea666b2573)},
                     {UINT64_C(0xad1c8eab5ee43b66), UINT64_C(0xda3243650005eed0)},
                     {UINT64_C(0xd863b256369d4a40), UINT64_C(0x90bed43e40076a83)},
                     {UINT64_C(0x873e4f75e2224e68), UINT64_C(0x5a7744a6e804a292)},
                     {UINT64_C(0xa90de3535aaae202), UINT64_C(0x711515d0a205cb37)},
                     {UINT64_C(0xd3515c2831559a83), UINT64_C(0x0d5a5b44ca873e04)},
                     {UINT64_C(0x8412d9991ed58091), UINT64_C(0xe858790afe9486c3)},
                     {UINT64_C(0xa5178fff668ae0b6), UINT64_C(0x626e974dbe39a873)},
                     {UINT64_C(0xce5d73ff402d98e3), UINT64_C(0xfb0a3d212dc81290)},
                     {UINT64_C(0x80fa687f881c7f8e), UINT64_C(0x7ce66634bc9d0b9a)},
                     {UINT64_C(0xa139029f6a239f72), UINT64_C(0x1c1fffc1ebc44e81)},
                     {UINT64_C(0xc987434744ac874e), UINT64_C(0xa327ffb266b56221)},
                     {UINT64_C(0xfbe9141915d7a922), UINT64_C(0x4bf1ff9f0062baa9)},
                     {UINT64_C(0x9d71ac8fada6c9b5), UINT64_C(0x6f773fc3603db4aa)},
                     {UINT64_C(0xc4ce17b399107c22), UINT64_C(0xcb550fb4384d21d4)},
                     {UINT64_C(0xf6019da07f549b2b), UINT64_C(0x7e2a53a146606a49)},
                     {UINT64_C(0x99c102844f94e0fb), UINT64_C(0x2eda7444cbfc426e)},
                     {UINT64_C(0xc0314325637a1939), UINT64_C(0xfa911155fefb5309)},
                     {UINT64_C(0xf03d93eebc589f88), UINT64_C(0x793555ab7eba27cb)},
                     {UINT64_C(0x96267c7535b763b5), UINT64_C(0x4bc1558b2f3458df)},
                     {UINT64_C(0xbbb01b9283253ca2), UINT64_C(0x9eb1aaedfb016f17)},
                     {UINT64_C(0xea9c227723ee8bcb), UINT64_C(0x465e15a979c1cadd)},
                     {UINT64_C(0x92a1958a7675175f), UINT64_C(0x0bfacd89ec191eca)},
                     {UINT64_C(0xb749faed14125d36), UINT64_C(0xcef980ec671f667c)},
                     {UINT64_C(0xe51c79a85916f484), UINT64_C(0x82b7e12780e7401b)},
                     {UINT64_C(0x8f31cc0937ae58d2), UINT64_C(0xd1b2ecb8b0908811)},
                     {UINT64_C(0xb2fe3f0b8599ef07), UINT64_C(0x861fa7e6dcb4aa16)},
                     {UINT64_C(0xdfbdcece67006ac9), UINT64_C(0x67a791e093e1d49b)},
                     {UINT64_C(0x8bd6a141006042bd), UINT64_C(0xe0c8bb2c5c6d24e1)},
                     {UINT64_C(0xaecc49914078536d), UINT64_C(0x58fae9f773886e19)},
                     {UINT64_C(0xda7f5bf590966848), UINT64_C(0xaf39a475506a899f)},
                     {UINT64_C(0x888f99797a5e012d), UINT64_C(0x6d8406c952429604)},
                     {UINT64_C(0xaab37fd7d8f58178), UINT64_C(0xc8e5087ba6d33b84)},
                     {UINT64_C(0xd5605fcdcf32e1d6), UINT64_C(0xfb1e4a9a90880a65)},
                     {UINT64_C(0x855c3be0a17fcd26), UINT64_C(0x5cf2eea09a550680)},
                     {UINT64_C(0xa6b34ad8c9dfc06f), UINT64_C(0xf42faa48c0ea481f)},
                     {UINT64_C(0xd0601d8efc57b08b), UINT64_C(0xf13b94daf124da27)},
                     {UINT64_C(0x823c12795db6ce57), UINT64_C(0x76c53d08d6b70859)},
                     {UINT64_C(0xa2cb1717b52481ed), UINT64_C(0x54768c4b0c64ca6f)},
                     {UINT64_C(0xcb7ddcdda26da268), UINT64_C(0xa9942f5dcf7dfd0a)},
                     {UINT64_C(0xfe5d54150b090b02), UINT64_C(0xd3f93b35435d7c4d)},
                     {UINT64_C(0x9efa548d26e5a6e1), UINT64_C(0xc47bc5014a1a6db0)},
                     {UINT64_C(0xc6b8e9b0709f109a), UINT64_C(0x359ab6419ca1091c)},
                     {UINT64_C(0xf867241c8cc6d4c0), UINT64_C(0xc30163d203c94b63)},
                     {UINT64_C(0x9b407691d7fc44f8), UINT64_C(0x79e0de63425dcf1e)},
                     {UINT64_C(0xc21094364dfb5636), UINT64_C(0x985915fc12f542e5)},
                     {UINT64_C(0xf294b943e17a2bc4), UINT64_C(0x3e6f5b7b17b2939e)},
                     {UINT64_C(0x979cf3ca6cec5b5a), UINT64_C(0xa705992ceecf9c43)},
                     {UINT64_C(0xbd8430bd08277231), UINT64_C(0x50c6ff782a838354)},
                     {UINT64_C(0xece53cec4a314ebd), UINT64_C(0xa4f8bf5635246429)},
                     {UINT64_C(0x940f4613ae5ed136), UINT64_C(0x871b7795e136be9a)},
                     {UINT64_C(0xb913179899f68584), UINT64_C(0x28e2557b59846e40)},
                     {UINT64_C(0xe757dd7ec07426e5), UINT64_C(0x331aeada2fe589d0)},
                     {UINT64_C(0x9096ea6f3848984f), UINT64_C(0x3ff0d2c85def7622)},
                     {UINT64_C(0xb4bca50b065abe63), UINT64_C(0x0fed077a756b53aa)},
                     {UINT64_C(0xe1ebce4dc7f16dfb), UINT64_C(0xd3e8495912c62895)},
                     {UINT64_C(0x8d3360f09cf6e4bd), UINT64_C(0x64712dd7abbbd95d)},
                     {UINT64_C(0xb080392cc4349dec), UINT64_C(0xbd8d794d96aacfb4)},
                     {UINT64_C(0xdca04777f541c567), UINT64_C(0xecf0d7a0fc5583a1)},
                     {UINT64_C(0x89e42caaf9491b60), UINT64_C(0xf41686c49db57245)},
                     {UINT64_C(0xac5d37d5b79b6239), UINT64_C(0x311c2875c522ced6)},
                     {UINT64_C(0xd77485cb25823ac7), UINT64_C(0x7d633293366b828c)},
                     {UINT64_C(0x86a8d39ef77164bc), UINT64_C(0xae5dff9c02033198)},
                     {UINT64_C(0xa8530886b54dbdeb), UINT64_C(0xd9f57f830283fdfd)},
                     {UINT64_C(0xd267caa862a12d66), UINT64_C(0xd072df63c324fd7c)},
                     {UINT64_C(0x8380dea93da4bc60), UINT64_C(0x4247cb9e59f71e6e)},
                     {UINT64_C(0xa46116538d0deb78), UINT64_C(0x52d9be85f074e609)},
                     {UINT64_C(0xcd795be870516656), UINT64_C(0x67902e276c921f8c)},
                     {UINT64_C(0x806bd9714632dff6), UINT64_C(0x00ba1cd8a3db53b7)},
                     {UINT64_C(0xa086cfcd97bf97f3), UINT64_C(0x80e8a40eccd228a5)},
                     {UINT64_C(0xc8a883c0fdaf7df0), UINT64_C(0x6122cd128006b2ce)},
                     {UINT64_C(0xfad2a4b13d1b5d6c), UINT64_C(0x796b805720085f82)},
                     {UINT64_C(0x9cc3a6eec6311a63), UINT64_C(0xcbe3303674053bb1)},
                     {UINT64_C(0xc3f490aa77bd60fc), UINT64_C(0xbedbfc4411068a9d)},
                     {UINT64_C(0xf4f1b4d515acb93b), UINT64_C(0xee92fb5515482d45)},
                     {UINT64_C(0x991711052d8bf3c5), UINT64_C(0x751bdd152d4d1c4b)},
                     {UINT64_C(0xbf5cd54678eef0b6), UINT64_C(0xd262d45a78a0635e)},
                     {UINT64_C(0xef340a98172aace4), UINT64_C(0x86fb897116c87c35)},
                     {UINT64_C(0x9580869f0e7aac0e), UINT64_C(0xd45d35e6ae3d4da1)},
                     {UINT64_C(0xbae0a846d2195712), UINT64_C(0x8974836059cca10a)},
                     {UINT64_C(0xe998d258869facd7), UINT64_C(0x2bd1a438703fc94c)},
                     {UINT64_C(0x91ff83775423cc06), UINT64_C(0x7b6306a34627ddd0)},
                     {UINT64_C(0xb67f6455292cbf08), UINT64_C(0x1a3bc84c17b1d543)},
                     {UINT64_C(0xe41f3d6a7377eeca), UINT64_C(0x20caba5f1d9e4a94)},
                     {UINT64_C(0x8e938662882af53e), UINT64_C(0x547eb47b7282ee9d)},
                     {UINT64_C(0xb23867fb2a35b28d), UINT64_C(0xe99e619a4f23aa44)},
                     {UINT64_C(0xdec681f9f4c31f31), UINT64_C(0x6405fa00e2ec94d5)},
                     {UINT64_C(0x8b3c113c38f9f37e), UINT64_C(0xde83bc408dd3dd05)},
                     {UINT64_C(0xae0b158b4738705e), UINT64_C(0x9624ab50b148d446)},
                     {UINT64_C(0xd98ddaee19068c76), UINT64_C(0x3badd624dd9b0958)},
                     {UINT64_C(0x87f8a8d4cfa417c9), UINT64_C(0xe54ca5d70a80e5d7)},
                     {UINT64_C(0xa9f6d30a038d1dbc), UINT64_C(0x5e9fcf4ccd211f4d)},
                     {UINT64_C(0xd47487cc8470652b), UINT64_C(0x7647c32000696720)},
                     {UINT64_C(0x84c8d4dfd2c63f3b), UINT64_C(0x29ecd9f40041e074)},
                     {UINT64_C(0xa5fb0a17c777cf09), UINT64_C(0xf468107100525891)},
                     {UINT64_C(0xcf79cc9db955c2cc), UINT64_C(0x7182148d4066eeb5)},
                     {UINT64_C(0x81ac1fe293d599bf), UINT64_C(0xc6f14cd848405531)},
                     {UINT64_C(0xa21727db38cb002f), UINT64_C(0xb8ada00e5a506a7d)},
                     {UINT64_C(0xca9cf1d206fdc03b), UINT64_C(0xa6d90811f0e4851d)},
                     {UINT64_C(0xfd442e4688bd304a), UINT64_C(0x908f4a166d1da664)},
                     {UINT64_C(0x9e4a9cec15763e2e), UINT64_C(0x9a598e4e043287ff)},
                     {UINT64_C(0xc5dd44271ad3cdba), UINT64_C(0x40eff1e1853f29fe)},
                     {UINT64_C(0xf7549530e188c128), UINT64_C(0xd12bee59e68ef47d)},
                     {UINT64_C(0x9a94dd3e8cf578b9), UINT64_C(0x82bb74f8301958cf)},
                     {UINT64_C(0xc13a148e3032d6e7), UINT64_C(0xe36a52363c1faf02)},
                     {UINT64_C(0xf18899b1bc3f8ca1), UINT64_C(0xdc44e6c3cb279ac2)},
                     {UINT64_C(0x96f5600f15a7b7e5), UINT64_C(0x29ab103a5ef8c0ba)},
                     {UINT64_C(0xbcb2b812db11a5de), UINT64_C(0x7415d448f6b6f0e8)},
                     {UINT64_C(0xebdf661791d60f56), UINT64_C(0x111b495b3464ad22)},
                     {UINT64_C(0x936b9fcebb25c995), UINT64_C(0xcab10dd900beec35)},
                     {UINT64_C(0xb84687c269ef3bfb), UINT64_C(0x3d5d514f40eea743)},
                     {UINT64_C(0xe65829b3046b0afa), UINT64_C(0x0cb4a5a3112a5113)},
                     {UINT64_C(0x8ff71a0fe2c2e6dc), UINT64_C(0x47f0e785eaba72ac)},
                     {UINT64_C(0xb3f4e093db73a093), UINT64_C(0x59ed216765690f57)},
                     {UINT64_C(0xe0f218b8d25088b8), UINT64_C(0x306869c13ec3532d)},
                     {UINT64_C(0x8c974f7383725573), UINT64_C(0x1e414218c73a13fc)},
                     {UINT64_C(0xafbd2350644eeacf), UINT64_C(0xe5d1929ef90898fb)},
                     {UINT64_C(0xdbac6c247d62a583), UINT64_C(0xdf45f746b74abf3a)},
                     {UINT64_C(0x894bc396ce5da772), UINT64_C(0x6b8bba8c328eb784)},
                     {UINT64_C(0xab9eb47c81f5114f), UINT64_C(0x066ea92f3f326565)},
                     {UINT64_C(0xd686619ba27255a2), UINT64_C(0xc80a537b0efefebe)},
                     {UINT64_C(0x8613fd0145877585), UINT64_C(0xbd06742ce95f5f37)},
                     {UINT64_C(0xa798fc4196e952e7), UINT64_C(0x2c48113823b73705)},
                     {UINT64_C(0xd17f3b51fca3a7a0), UINT64_C(0xf75a15862ca504c6)},
                     {UINT64_C(0x82ef85133de648c4), UINT64_C(0x9a984d73dbe722fc)},
                     {UINT64_C(0xa3ab66580d5fdaf5), UINT64_C(0xc13e60d0d2e0ebbb)},
                     {UINT64_C(0xcc963fee10b7d1b3), UINT64_C(0x318df905079926a9)},
                     {UINT64_C(0xffbbcfe994e5c61f), UINT64_C(0xfdf17746497f7053)},
                     {UINT64_C(0x9fd561f1fd0f9bd3), UINT64_C(0xfeb6ea8bedefa634)},
                     {UINT64_C(0xc7caba6e7c5382c8), UINT64_C(0xfe64a52ee96b8fc1)},
                     {UINT64_C(0xf9bd690a1b68637b), UINT64_C(0x3dfdce7aa3c673b1)},
                     {UINT64_C(0x9c1661a651213e2d), UINT64_C(0x06bea10ca65c084f)},
                     {UINT64_C(0xc31bfa0fe5698db8), UINT64_C(0x486e494fcff30a63)},
                     {UINT64_C(0xf3e2f893dec3f126), UINT64_C(0x5a89dba3c3efccfb)},
                     {UINT64_C(0x986ddb5c6b3a76b7), UINT64_C(0xf89629465a75e01d)},
                     {UINT64_C(0xbe89523386091465), UINT64_C(0xf6bbb397f1135824)},
                     {UINT64_C(0xee2ba6c0678b597f), UINT64_C(0x746aa07ded582e2d)},
                     {UINT64_C(0x94db483840b717ef), UINT64_C(0xa8c2a44eb4571cdd)},
                     {UINT64_C(0xba121a4650e4ddeb), UINT64_C(0x92f34d62616ce414)},
                     {UINT64_C(0xe896a0d7e51e1566), UINT64_C(0x77b020baf9c81d18)},
                     {UINT64_C(0x915e2486ef32cd60), UINT64_C(0x0ace1474dc1d122f)},
                     {UINT64_C(0xb5b5ada8aaff80b8), UINT64_C(0x0d819992132456bb)},
                     {UINT64_C(0xe3231912d5bf60e6), UINT64_C(0x10e1fff697ed6c6a)},
                     {UINT64_C(0x8df5efabc5979c8f), UINT64_C(0xca8d3ffa1ef463c2)},
                     {UINT64_C(0xb1736b96b6fd83b3), UINT64_C(0xbd308ff8a6b17cb3)},
                     {UINT64_C(0xddd0467c64bce4a0), UINT64_C(0xac7cb3f6d05ddbdf)},
                     {UINT64_C(0x8aa22c0dbef60ee4), UINT64_C(0x6bcdf07a423aa96c)},
                     {UINT64_C(0xad4ab7112eb3929d), UINT64_C(0x86c16c98d2c953c7)},
                     {UINT64_C(0xd89d64d57a607744), UINT64_C(0xe871c7bf077ba8b8)},
                     {UINT64_C(0x87625f056c7c4a8b), UINT64_C(0x11471cd764ad4973)},
                     {UINT64_C(0xa93af6c6c79b5d2d), UINT64_C(0xd598e40d3dd89bd0)},
                     {UINT64_C(0xd389b47879823479), UINT64_C(0x4aff1d108d4ec2c4)},
                     {UINT64_C(0x843610cb4bf160cb), UINT64_C(0xcedf722a585139bb)},
                     {UINT64_C(0xa54394fe1eedb8fe), UINT64_C(0xc2974eb4ee658829)},
                     {UINT64_C(0xce947a3da6a9273e), UINT64_C(0x733d226229feea33)},
                     {UINT64_C(0x811ccc668829b887), UINT64_C(0x0806357d5a3f5260)},
                     {UINT64_C(0xa163ff802a3426a8), UINT64_C(0xca07c2dcb0cf26f8)},
                     {UINT64_C(0xc9bcff6034c13052), UINT64_C(0xfc89b393dd02f0b6)},
                     {UINT64_C(0xfc2c3f3841f17c67), UINT64_C(0xbbac2078d443ace3)},
                     {UINT64_C(0x9d9ba7832936edc0), UINT64_C(0xd54b944b84aa4c0e)},
                     {UINT64_C(0xc5029163f384a931), UINT64_C(0x0a9e795e65d4df12)},
                     {UINT64_C(0xf64335bcf065d37d), UINT64_C(0x4d4617b5ff4a16d6)},
                     {UINT64_C(0x99ea0196163fa42e), UINT64_C(0x504bced1bf8e4e46)},
                     {UINT64_C(0xc06481fb9bcf8d39), UINT64_C(0xe45ec2862f71e1d7)},
                     {UINT64_C(0xf07da27a82c37088), UINT64_C(0x5d767327bb4e5a4d)},
                     {UINT64_C(0x964e858c91ba2655), UINT64_C(0x3a6a07f8d510f870)},
                     {UINT64_C(0xbbe226efb628afea), UINT64_C(0x890489f70a55368c)},
                     {UINT64_C(0xeadab0aba3b2dbe5), UINT64_C(0x2b45ac74ccea842f)},
                     {UINT64_C(0x92c8ae6b464fc96f), UINT64_C(0x3b0b8bc90012929e)},
                     {UINT64_C(0xb77ada0617e3bbcb), UINT64_C(0x09ce6ebb40173745)},
                     {UINT64_C(0xe55990879ddcaabd), UINT64_C(0xcc420a6a101d0516)},
                     {UINT64_C(0x8f57fa54c2a9eab6), UINT64_C(0x9fa946824a12232e)},
                     {UINT64_C(0xb32df8e9f3546564), UINT64_C(0x47939822dc96abfa)},
                     {UINT64_C(0xdff9772470297ebd), UINT64_C(0x59787e2b93bc56f8)},
                     {UINT64_C(0x8bfbea76c619ef36), UINT64_C(0x57eb4edb3c55b65b)},
                     {UINT64_C(0xaefae51477a06b03), UINT64_C(0xede622920b6b23f2)},
                     {UINT64_C(0xdab99e59958885c4), UINT64_C(0xe95fab368e45ecee)},
                     {UINT64_C(0x88b402f7fd75539b), UINT64_C(0x11dbcb0218ebb415)},
                     {UINT64_C(0xaae103b5fcd2a881), UINT64_C(0xd652bdc29f26a11a)},
                     {UINT64_C(0xd59944a37c0752a2), UINT64_C(0x4be76d3346f04960)},
                     {UINT64_C(0x857fcae62d8493a5), UINT64_C(0x6f70a4400c562ddc)},
                     {UINT64_C(0xa6dfbd9fb8e5b88e), UINT64_C(0xcb4ccd500f6bb953)},
                     {UINT64_C(0xd097ad07a71f26b2), UINT64_C(0x7e2000a41346a7a8)},
                     {UINT64_C(0x825ecc24c873782f), UINT64_C(0x8ed400668c0c28c9)},
                     {UINT64_C(0xa2f67f2dfa90563b), UINT64_C(0x728900802f0f32fb)},
                     {UINT64_C(0xcbb41ef979346bca), UINT64_C(0x4f2b40a03ad2ffba)},
                     {UINT64_C(0xfea126b7d78186bc), UINT64_C(0xe2f610c84987bfa9)},
                     {UINT64_C(0x9f24b832e6b0f436), UINT64_C(0x0dd9ca7d2df4d7ca)},
                     {UINT64_C(0xc6ede63fa05d3143), UINT64_C(0x91503d1c79720dbc)},
                     {UINT64_C(0xf8a95fcf88747d94), UINT64_C(0x75a44c6397ce912b)},
                     {UINT64_C(0x9b69dbe1b548ce7c), UINT64_C(0xc986afbe3ee11abb)},
                     {UINT64_C(0xc24452da229b021b), UINT64_C(0xfbe85badce996169)},
                     {UINT64_C(0xf2d56790ab41c2a2), UINT64_C(0xfae27299423fb9c4)},
                     {UINT64_C(0x97c560ba6b0919a5), UINT64_C(0xdccd879fc967d41b)},
                     {UINT64_C(0xbdb6b8e905cb600f), UINT64_C(0x5400e987bbc1c921)},
                     {UINT64_C(0xed246723473e3813), UINT64_C(0x290123e9aab23b69)},
                     {UINT64_C(0x9436c0760c86e30b), UINT64_C(0xf9a0b6720aaf6522)},
                     {UINT64_C(0xb94470938fa89bce), UINT64_C(0xf808e40e8d5b3e6a)},
                     {UINT64_C(0xe7958cb87392c2c2), UINT64_C(0xb60b1d1230b20e05)},
                     {UINT64_C(0x90bd77f3483bb9b9), UINT64_C(0xb1c6f22b5e6f48c3)},
                     {UINT64_C(0xb4ecd5f01a4aa828), UINT64_C(0x1e38aeb6360b1af4)},
                     {UINT64_C(0xe2280b6c20dd5232), UINT64_C(0x25c6da63c38de1b1)},
                     {UINT64_C(0x8d590723948a535f), UINT64_C(0x579c487e5a38ad0f)},
                     {UINT64_C(0xb0af48ec79ace837), UINT64_C(0x2d835a9df0c6d852)},
                     {UINT64_C(0xdcdb1b2798182244), UINT64_C(0xf8e431456cf88e66)},
                     {UINT64_C(0x8a08f0f8bf0f156b), UINT64_C(0x1b8e9ecb641b5900)},
                     {UINT64_C(0xac8b2d36eed2dac5), UINT64_C(0xe272467e3d222f40)},
                     {UINT64_C(0xd7adf884aa879177), UINT64_C(0x5b0ed81dcc6abb10)},
                     {UINT64_C(0x86ccbb52ea94baea), UINT64_C(0x98e947129fc2b4ea)},
                     {UINT64_C(0xa87fea27a539e9a5), UINT64_C(0x3f2398d747b36225)},
                     {UINT64_C(0xd29fe4b18e88640e), UINT64_C(0x8eec7f0d19a03aae)},
                     {UINT64_C(0x83a3eeeef9153e89), UINT64_C(0x1953cf68300424ad)},
                     {UINT64_C(0xa48ceaaab75a8e2b), UINT64_C(0x5fa8c3423c052dd8)},
                     {UINT64_C(0xcdb02555653131b6), UINT64_C(0x3792f412cb06794e)},
                     {UINT64_C(0x808e17555f3ebf11), UINT64_C(0xe2bbd88bbee40bd1)},
                     {UINT64_C(0xa0b19d2ab70e6ed6), UINT64_C(0x5b6aceaeae9d0ec5)},
                     {UINT64_C(0xc8de047564d20a8b), UINT64_C(0xf245825a5a445276)},
                     {UINT64_C(0xfb158592be068d2e), UINT64_C(0xeed6e2f0f0d56713)},
                     {UINT64_C(0x9ced737bb6c4183d), UINT64_C(0x55464dd69685606c)},
                     {UINT64_C(0xc428d05aa4751e4c), UINT64_C(0xaa97e14c3c26b887)},
                     {UINT64_C(0xf53304714d9265df), UINT64_C(0xd53dd99f4b3066a9)},
                     {UINT64_C(0x993fe2c6d07b7fab), UINT64_C(0xe546a8038efe402a)},
                     {UINT64_C(0xbf8fdb78849a5f96), UINT64_C(0xde98520472bdd034)},
                     {UINT64_C(0xef73d256a5c0f77c), UINT64_C(0x963e66858f6d4441)},
                     {UINT64_C(0x95a8637627989aad), UINT64_C(0xdde7001379a44aa9)},
                     {UINT64_C(0xbb127c53b17ec159), UINT64_C(0x5560c018580d5d53)},
                     {UINT64_C(0xe9d71b689dde71af), UINT64_C(0xaab8f01e6e10b4a7)},
                     {UINT64_C(0x9226712162ab070d), UINT64_C(0xcab3961304ca70e9)},
                     {UINT64_C(0xb6b00d69bb55c8d1), UINT64_C(0x3d607b97c5fd0d23)},
                     {UINT64_C(0xe45c10c42a2b3b05), UINT64_C(0x8cb89a7db77c506b)},
                     {UINT64_C(0x8eb98a7a9a5b04e3), UINT64_C(0x77f3608e92adb243)},
                     {UINT64_C(0xb267ed1940f1c61c), UINT64_C(0x55f038b237591ed4)},
                     {UINT64_C(0xdf01e85f912e37a3), UINT64_C(0x6b6c46dec52f6689)},
                     {UINT64_C(0x8b61313bbabce2c6), UINT64_C(0x2323ac4b3b3da016)},
                     {UINT64_C(0xae397d8aa96c1b77), UINT64_C(0xabec975e0a0d081b)},
                     {UINT64_C(0xd9c7dced53c72255), UINT64_C(0x96e7bd358c904a22)},
                     {UINT64_C(0x881cea14545c7575), UINT64_C(0x7e50d64177da2e55)},
                     {UINT64_C(0xaa242499697392d2), UINT64_C(0xdde50bd1d5d0b9ea)},
                     {UINT64_C(0xd4ad2dbfc3d07787), UINT64_C(0x955e4ec64b44e865)},
                     {UINT64_C(0x84ec3c97da624ab4), UINT64_C(0xbd5af13bef0b113f)},
                     {UINT64_C(0xa6274bbdd0fadd61), UINT64_C(0xecb1ad8aeacdd58f)},
                     {UINT64_C(0xcfb11ead453994ba), UINT64_C(0x67de18eda5814af3)},
                     {UINT64_C(0x81ceb32c4b43fcf4), UINT64_C(0x80eacf948770ced8)},
                     {UINT64_C(0xa2425ff75e14fc31), UINT64_C(0xa1258379a94d028e)},
                     {UINT64_C(0xcad2f7f5359a3b3e), UINT64_C(0x096ee45813a04331)},
                     {UINT64_C(0xfd87b5f28300ca0d), UINT64_C(0x8bca9d6e188853fd)},
                     {UINT64_C(0x9e74d1b791e07e48), UINT64_C(0x775ea264cf55347e)},
                     {UINT64_C(0xc612062576589dda), UINT64_C(0x95364afe032a819e)},
                     {UINT64_C(0xf79687aed3eec551), UINT64_C(0x3a83ddbd83f52205)},
                     {UINT64_C(0x9abe14cd44753b52), UINT64_C(0xc4926a9672793543)},
                     {UINT64_C(0xc16d9a0095928a27), UINT64_C(0x75b7053c0f178294)},
                     {UINT64_C(0xf1c90080baf72cb1), UINT64_C(0x5324c68b12dd6339)},
                     {UINT64_C(0x971da05074da7bee), UINT64_C(0xd3f6fc16ebca5e04)},
                     {UINT64_C(0xbce5086492111aea), UINT64_C(0x88f4bb1ca6bcf585)},
                     {UINT64_C(0xec1e4a7db69561a5), UINT64_C(0x2b31e9e3d06c32e6)},
                     {UINT64_C(0x9392ee8e921d5d07), UINT64_C(0x3aff322e62439fd0)},
                     {UINT64_C(0xb877aa3236a4b449), UINT64_C(0x09befeb9fad487c3)},
                     {UINT64_C(0xe69594bec44de15b), UINT64_C(0x4c2ebe687989a9b4)},
                     {UINT64_C(0x901d7cf73ab0acd9), UINT64_C(0x0f9d37014bf60a11)},
                     {UINT64_C(0xb424dc35095cd80f), UINT64_C(0x538484c19ef38c95)},
                     {UINT64_C(0xe12e13424bb40e13), UINT64_C(0x2865a5f206b06fba)},
                     {UINT64_C(0x8cbccc096f5088cb), UINT64_C(0xf93f87b7442e45d4)},
                     {UINT64_C(0xafebff0bcb24aafe), UINT64_C(0xf78f69a51539d749)},
                     {UINT64_C(0xdbe6fecebdedd5be), UINT64_C(0xb573440e5a884d1c)},
                     {UINT64_C(0x89705f4136b4a597), UINT64_C(0x31680a88f8953031)},
                     {UINT64_C(0xabcc77118461cefc), UINT64_C(0xfdc20d2b36ba7c3e)},
                     {UINT64_C(0xd6bf94d5e57a42bc), UINT64_C(0x3d32907604691b4d)},
                     {UINT64_C(0x8637bd05af6c69b5), UINT64_C(0xa63f9a49c2c1b110)},
                     {UINT64_C(0xa7c5ac471b478423), UINT64_C(0x0fcf80dc33721d54)},
                     {UINT64_C(0xd1b71758e219652b), UINT64_C(0xd3c36113404ea4a9)},
                     {UINT64_C(0x83126e978d4fdf3b), UINT64_C(0x645a1cac083126ea)},
                     {UINT64_C(0xa3d70a3d70a3d70a), UINT64_C(0x3d70a3d70a3d70a4)},
                     {UINT64_C(0xcccccccccccccccc), UINT64_C(0xcccccccccccccccd)},
                     {UINT64_C(0x8000000000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xa000000000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xc800000000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xfa00000000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x9c40000000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xc350000000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xf424000000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x9896800000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xbebc200000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xee6b280000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x9502f90000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xba43b74000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xe8d4a51000000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x9184e72a00000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xb5e620f480000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xe35fa931a0000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x8e1bc9bf04000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xb1a2bc2ec5000000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xde0b6b3a76400000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x8ac7230489e80000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xad78ebc5ac620000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xd8d726b7177a8000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x878678326eac9000), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xa968163f0a57b400), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xd3c21bcecceda100), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x84595161401484a0), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xa56fa5b99019a5c8), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0xcecb8f27f4200f3a), UINT64_C(0x0000000000000000)},
                     {UINT64_C(0x813f3978f8940984), UINT64_C(0x4000000000000000)},
                     {UINT64_C(0xa18f07d736b90be5), UINT64_C(0x5000000000000000)},
                     {UINT64_C(0xc9f2c9cd04674ede), UINT64_C(0xa400000000000000)},
                     {UINT64_C(0xfc6f7c4045812296), UINT64_C(0x4d00000000000000)},
                     {UINT64_C(0x9dc5ada82b70b59d), UINT64_C(0xf020000000000000)},
                     {UINT64_C(0xc5371912364ce305), UINT64_C(0x6c28000000000000)},
                     {UINT64_C(0xf684df56c3e01bc6), UINT64_C(0xc732000000000000)},
                     {UINT64_C(0x9a130b963a6c115c), UINT64_C(0x3c7f400000000000)},
                     {UINT64_C(0xc097ce7bc90715b3), UINT64_C(0x4b9f100000000000)},
                     {UINT64_C(0xf0bdc21abb48db20), UINT64_C(0x1e86d40000000000)},
                     {UINT64_C(0x96769950b50d88f4), UINT64_C(0x1314448000000000)},
                     {UINT64_C(0xbc143fa4e250eb31), UINT64_C(0x17d955a000000000)},
                     {UINT64_C(0xeb194f8e1ae525fd), UINT64_C(0x5dcfab0800000000)},
                     {UINT64_C(0x92efd1b8d0cf37be), UINT64_C(0x5aa1cae500000000)},
                     {UINT64_C(0xb7abc627050305ad), UINT64_C(0xf14a3d9e40000000)},
                     {UINT64_C(0xe596b7b0c643c719), UINT64_C(0x6d9ccd05d0000000)},
                     {UINT64_C(0x8f7e32ce7bea5c6f), UINT64_C(0xe4820023a2000000)},
                     {UINT64_C(0xb35dbf821ae4f38b), UINT64_C(0xdda2802c8a800000)},
                     {UINT64_C(0xe0352f62a19e306e), UINT64_C(0xd50b2037ad200000)},
                     {UINT64_C(0x8c213d9da502de45), UINT64_C(0x4526f422cc340000)},
                     {UINT64_C(0xaf298d050e4395d6), UINT64_C(0x9670b12b7f410000)},
                     {UINT64_C(0xdaf3f04651d47b4c), UINT64_C(0x3c0cdd765f114000)},
                     {UINT64_C(0x88d8762bf324cd0f), UINT64_C(0xa5880a69fb6ac800)},
                     {UINT64_C(0xab0e93b6efee0053), UINT64_C(0x8eea0d047a457a00)},
                     {UINT64_C(0xd5d238a4abe98068), UINT64_C(0x72a4904598d6d880)},
                     {UINT64_C(0x85a36366eb71f041), UINT64_C(0x47a6da2b7f864750)},
                     {UINT64_C(0xa70c3c40a64e6c51), UINT64_C(0x999090b65f67d924)},
                     {UINT64_C(0xd0cf4b50cfe20765), UINT64_C(0xfff4b4e3f741cf6d)},
                     {UINT64_C(0x82818f1281ed449f), UINT64_C(0xbff8f10e7a8921a5)},
                     {UINT64_C(0xa321f2d7226895c7), UINT64_C(0xaff72d52192b6a0e)},
                     {UINT64_C(0xcbea6f8ceb02bb39), UINT64_C(0x9bf4f8a69f764491)},
                     {UINT64_C(0xfee50b7025c36a08), UINT64_C(0x02f236d04753d5b5)},
                     {UINT64_C(0x9f4f2726179a2245), UINT64_C(0x01d762422c946591)},
                     {UINT64_C(0xc722f0ef9d80aad6), UINT64_C(0x424d3ad2b7b97ef6)},
                     {UINT64_C(0xf8ebad2b84e0d58b), UINT64_C(0xd2e0898765a7deb3)},
                     {UINT64_C(0x9b934c3b330c8577), UINT64_C(0x63cc55f49f88eb30)},
                     {UINT64_C(0xc2781f49ffcfa6d5), UINT64_C(0x3cbf6b71c76b25fc)},
                     {UINT64_C(0xf316271c7fc3908a), UINT64_C(0x8bef464e3945ef7b)},
                     {UINT64_C(0x97edd871cfda3a56), UINT64_C(0x97758bf0e3cbb5ad)},
                     {UINT64_C(0xbde94e8e43d0c8ec), UINT64_C(0x3d52eeed1cbea318)},
                     {UINT64_C(0xed63a231d4c4fb27), UINT64_C(0x4ca7aaa863ee4bde)},
                     {UINT64_C(0x945e455f24fb1cf8), UINT64_C(0x8fe8caa93e74ef6b)},
                     {UINT64_C(0xb975d6b6ee39e436), UINT64_C(0xb3e2fd538e122b45)},
                     {UINT64_C(0xe7d34c64a9c85d44), UINT64_C(0x60dbbca87196b617)},
                     {UINT64_C(0x90e40fbeea1d3a4a), UINT64_C(0xbc8955e946fe31ce)},
                     {UINT64_C(0xb51d13aea4a488dd), UINT64_C(0x6babab6398bdbe42)},
                     {UINT64_C(0xe264589a4dcdab14), UINT64_C(0xc696963c7eed2dd2)},
                     {UINT64_C(0x8d7eb76070a08aec), UINT64_C(0xfc1e1de5cf543ca3)},
                     {UINT64_C(0xb0de65388cc8ada8), UINT64_C(0x3b25a55f43294bcc)},
                     {UINT64_C(0xdd15fe86affad912), UINT64_C(0x49ef0eb713f39ebf)},
                     {UINT64_C(0x8a2dbf142dfcc7ab), UINT64_C(0x6e3569326c784338)},
                     {UINT64_C(0xacb92ed9397bf996), UINT64_C(0x49c2c37f07965405)},
                     {UINT64_C(0xd7e77a8f87daf7fb), UINT64_C(0xdc33745ec97be907)},
                     {UINT64_C(0x86f0ac99b4e8dafd), UINT64_C(0x69a028bb3ded71a4)},
                     {UINT64_C(0xa8acd7c0222311bc), UINT64_C(0xc40832ea0d68ce0d)},
                     {UINT64_C(0xd2d80db02aabd62b), UINT64_C(0xf50a3fa490c30191)},
                     {UINT64_C(0x83c7088e1aab65db), UINT64_C(0x792667c6da79e0fb)},
                     {UINT64_C(0xa4b8cab1a1563f52), UINT64_C(0x577001b891185939)},
                     {UINT64_C(0xcde6fd5e09abcf26), UINT64_C(0xed4c0226b55e6f87)},
                     {UINT64_C(0x80b05e5ac60b6178), UINT64_C(0x544f8158315b05b5)},
                     {UINT64_C(0xa0dc75f1778e39d6), UINT64_C(0x696361ae3db1c722)},
                     {UINT64_C(0xc913936dd571c84c), UINT64_C(0x03bc3a19cd1e38ea)},
                     {UINT64_C(0xfb5878494ace3a5f), UINT64_C(0x04ab48a04065c724)},
                     {UINT64_C(0x9d174b2dcec0e47b), UINT64_C(0x62eb0d64283f9c77)},
                     {UINT64_C(0xc45d1df942711d9a), UINT64_C(0x3ba5d0bd324f8395)},
                     {UINT64_C(0xf5746577930d6500), UINT64_C(0xca8f44ec7ee3647a)},
                     {UINT64_C(0x9968bf6abbe85f20), UINT64_C(0x7e998b13cf4e1ecc)},
                     {UINT64_C(0xbfc2ef456ae276e8), UINT64_C(0x9e3fedd8c321a67f)},
                     {UINT64_C(0xefb3ab16c59b14a2), UINT64_C(0xc5cfe94ef3ea101f)},
                     {UINT64_C(0x95d04aee3b80ece5), UINT64_C(0xbba1f1d158724a13)},
                     {UINT64_C(0xbb445da9ca61281f), UINT64_C(0x2a8a6e45ae8edc98)},
                     {UINT64_C(0xea1575143cf97226), UINT64_C(0xf52d09d71a3293be)},
                     {UINT64_C(0x924d692ca61be758), UINT64_C(0x593c2626705f9c57)},
                     {UINT64_C(0xb6e0c377cfa2e12e), UINT64_C(0x6f8b2fb00c77836d)},
                     {UINT64_C(0xe498f455c38b997a), UINT64_C(0x0b6dfb9c0f956448)},
                     {UINT64_C(0x8edf98b59a373fec), UINT64_C(0x4724bd4189bd5ead)},
                     {UINT64_C(0xb2977ee300c50fe7), UINT64_C(0x58edec91ec2cb658)},
                     {UINT64_C(0xdf3d5e9bc0f653e1), UINT64_C(0x2f2967b66737e3ee)},
                     {UINT64_C(0x8b865b215899f46c), UINT64_C(0xbd79e0d20082ee75)},
                     {UINT64_C(0xae67f1e9aec07187), UINT64_C(0xecd8590680a3aa12)},
                     {UINT64_C(0xda01ee641a708de9), UINT64_C(0xe80e6f4820cc9496)},
                     {UINT64_C(0x884134fe908658b2), UINT64_C(0x3109058d147fdcde)},
                     {UINT64_C(0xaa51823e34a7eede), UINT64_C(0xbd4b46f0599fd416)},
                     {UINT64_C(0xd4e5e2cdc1d1ea96), UINT64_C(0x6c9e18ac7007c91b)},
                     {UINT64_C(0x850fadc09923329e), UINT64_C(0x03e2cf6bc604ddb1)},
                     {UINT64_C(0xa6539930bf6bff45), UINT64_C(0x84db8346b786151d)},
                     {UINT64_C(0xcfe87f7cef46ff16), UINT64_C(0xe612641865679a64)},
                     {UINT64_C(0x81f14fae158c5f6e), UINT64_C(0x4fcb7e8f3f60c07f)},
                     {UINT64_C(0xa26da3999aef7749), UINT64_C(0xe3be5e330f38f09e)},
                     {UINT64_C(0xcb090c8001ab551c), UINT64_C(0x5cadf5bfd3072cc6)},
                     {UINT64_C(0xfdcb4fa002162a63), UINT64_C(0x73d9732fc7c8f7f7)},
                     {UINT64_C(0x9e9f11c4014dda7e), UINT64_C(0x2867e7fddcdd9afb)},
                     {UINT64_C(0xc646d63501a1511d), UINT64_C(0xb281e1fd541501b9)},
                     {UINT64_C(0xf7d88bc24209a565), UINT64_C(0x1f225a7ca91a4227)},
                     {UINT64_C(0x9ae757596946075f), UINT64_C(0x3375788de9b06959)},
                     {UINT64_C(0xc1a12d2fc3978937), UINT64_C(0x0052d6b1641c83af)},
                     {UINT64_C(0xf209787bb47d6b84), UINT64_C(0xc0678c5dbd23a49b)},
                     {UINT64_C(0x9745eb4d50ce6332), UINT64_C(0xf840b7ba963646e1)},
                     {UINT64_C(0xbd176620a501fbff), UINT64_C(0xb650e5a93bc3d899)},
                     {UINT64_C(0xec5d3fa8ce427aff), UINT64_C(0xa3e51f138ab4cebf)},
                     {UINT64_C(0x93ba47c980e98cdf), UINT64_C(0xc66f336c36b10138)},
                     {UINT64_C(0xb8a8d9bbe123f017), UINT64_C(0xb80b0047445d4185)},
                     {UINT64_C(0xe6d3102ad96cec1d), UINT64_C(0xa60dc059157491e6)},
                     {UINT64_C(0x9043ea1ac7e41392), UINT64_C(0x87c89837ad68db30)},
                     {UINT64_C(0xb454e4a179dd1877), UINT64_C(0x29babe4598c311fc)},
                     {UINT64_C(0xe16a1dc9d8545e94), UINT64_C(0xf4296dd6fef3d67b)},
                     {UINT64_C(0x8ce2529e2734bb1d), UINT64_C(0x1899e4a65f58660d)},
                     {UINT64_C(0xb01ae745b101e9e4), UINT64_C(0x5ec05dcff72e7f90)},
                     {UINT64_C(0xdc21a1171d42645d), UINT64_C(0x76707543f4fa1f74)},
                     {UINT64_C(0x899504ae72497eba), UINT64_C(0x6a06494a791c53a9)},
                     {UINT64_C(0xabfa45da0edbde69), UINT64_C(0x0487db9d17636893)},
                     {UINT64_C(0xd6f8d7509292d603), UINT64_C(0x45a9d2845d3c42b7)},
                     {UINT64_C(0x865b86925b9bc5c2), UINT64_C(0x0b8a2392ba45a9b3)},
                     {UINT64_C(0xa7f26836f282b732), UINT64_C(0x8e6cac7768d7141f)},
                     {UINT64_C(0xd1ef0244af2364ff), UINT64_C(0x3207d795430cd927)},
                     {UINT64_C(0x8335616aed761f1f), UINT64_C(0x7f44e6bd49e807b9)},
                     {UINT64_C(0xa402b9c5a8d3a6e7), UINT64_C(0x5f16206c9c6209a7)},
                     {UINT64_C(0xcd036837130890a1), UINT64_C(0x36dba887c37a8c10)},
                     {UINT64_C(0x802221226be55a64), UINT64_C(0xc2494954da2c978a)},
                     {UINT64_C(0xa02aa96b06deb0fd), UINT64_C(0xf2db9baa10b7bd6d)},
                     {UINT64_C(0xc83553c5c8965d3d), UINT64_C(0x6f92829494e5acc8)},
                     {UINT64_C(0xfa42a8b73abbf48c), UINT64_C(0xcb772339ba1f17fa)},
                     {UINT64_C(0x9c69a97284b578d7), UINT64_C(0xff2a760414536efc)},
                     {UINT64_C(0xc38413cf25e2d70d), UINT64_C(0xfef5138519684abb)},
                     {UINT64_C(0xf46518c2ef5b8cd1), UINT64_C(0x7eb258665fc25d6a)},
                     {UINT64_C(0x98bf2f79d5993802), UINT64_C(0xef2f773ffbd97a62)},
                     {UINT64_C(0xbeeefb584aff8603), UINT64_C(0xaafb550ffacfd8fb)},
                     {UINT64_C(0xeeaaba2e5dbf6784), UINT64_C(0x95ba2a53f983cf39)},
                     {UINT64_C(0x952ab45cfa97a0b2), UINT64_C(0xdd945a747bf26184)},
                     {UINT64_C(0xba756174393d88df), UINT64_C(0x94f971119aeef9e5)},
                     {UINT64_C(0xe912b9d1478ceb17), UINT64_C(0x7a37cd5601aab85e)},
                     {UINT64_C(0x91abb422ccb812ee), UINT64_C(0xac62e055c10ab33b)},
                     {UINT64_C(0xb616a12b7fe617aa), UINT64_C(0x577b986b314d600a)},
                     {UINT64_C(0xe39c49765fdf9d94), UINT64_C(0xed5a7e85fda0b80c)},
                     {UINT64_C(0x8e41ade9fbebc27d), UINT64_C(0x14588f13be847308)},
                     {UINT64_C(0xb1d219647ae6b31c), UINT64_C(0x596eb2d8ae258fc9)},
                     {UINT64_C(0xde469fbd99a05fe3), UINT64_C(0x6fca5f8ed9aef3bc)},
                     {UINT64_C(0x8aec23d680043bee), UINT64_C(0x25de7bb9480d5855)},
                     {UINT64_C(0xada72ccc20054ae9), UINT64_C(0xaf561aa79a10ae6b)},
                     {UINT64_C(0xd910f7ff28069da4), UINT64_C(0x1b2ba1518094da05)},
                     {UINT64_C(0x87aa9aff79042286), UINT64_C(0x90fb44d2f05d0843)},
                     {UINT64_C(0xa99541bf57452b28), UINT64_C(0x353a1607ac744a54)},
                     {UINT64_C(0xd3fa922f2d1675f2), UINT64_C(0x42889b8997915ce9)},
                     {UINT64_C(0x847c9b5d7c2e09b7), UINT64_C(0x69956135febada12)},
                     {UINT64_C(0xa59bc234db398c25), UINT64_C(0x43fab9837e699096)},
                     {UINT64_C(0xcf02b2c21207ef2e), UINT64_C(0x94f967e45e03f4bc)},
                     {UINT64_C(0x8161afb94b44f57d), UINT64_C(0x1d1be0eebac278f6)},
                     {UINT64_C(0xa1ba1ba79e1632dc), UINT64_C(0x6462d92a69731733)},
                     {UINT64_C(0xca28a291859bbf93), UINT64_C(0x7d7b8f7503cfdcff)},
                     {UINT64_C(0xfcb2cb35e702af78), UINT64_C(0x5cda735244c3d43f)},
                     {UINT64_C(0x9defbf01b061adab), UINT64_C(0x3a0888136afa64a8)},
                     {UINT64_C(0xc56baec21c7a1916), UINT64_C(0x088aaa1845b8fdd1)},
                     {UINT64_C(0xf6c69a72a3989f5b), UINT64_C(0x8aad549e57273d46)},
                     {UINT64_C(0x9a3c2087a63f6399), UINT64_C(0x36ac54e2f678864c)},
                     {UINT64_C(0xc0cb28a98fcf3c7f), UINT64_C(0x84576a1bb416a7de)},
                     {UINT64_C(0xf0fdf2d3f3c30b9f), UINT64_C(0x656d44a2a11c51d6)},
                     {UINT64_C(0x969eb7c47859e743), UINT64_C(0x9f644ae5a4b1b326)},
                     {UINT64_C(0xbc4665b596706114), UINT64_C(0x873d5d9f0dde1fef)},
                     {UINT64_C(0xeb57ff22fc0c7959), UINT64_C(0xa90cb506d155a7eb)},
                     {UINT64_C(0x9316ff75dd87cbd8), UINT64_C(0x09a7f12442d588f3)},
                     {UINT64_C(0xb7dcbf5354e9bece), UINT64_C(0x0c11ed6d538aeb30)},
                     {UINT64_C(0xe5d3ef282a242e81), UINT64_C(0x8f1668c8a86da5fb)},
                     {UINT64_C(0x8fa475791a569d10), UINT64_C(0xf96e017d694487bd)},
                     {UINT64_C(0xb38d92d760ec4455), UINT64_C(0x37c981dcc395a9ad)},
                     {UINT64_C(0xe070f78d3927556a), UINT64_C(0x85bbe253f47b1418)},
                     {UINT64_C(0x8c469ab843b89562), UINT64_C(0x93956d7478ccec8f)},
                     {UINT64_C(0xaf58416654a6babb), UINT64_C(0x387ac8d1970027b3)},
                     {UINT64_C(0xdb2e51bfe9d0696a), UINT64_C(0x06997b05fcc0319f)},
                     {UINT64_C(0x88fcf317f22241e2), UINT64_C(0x441fece3bdf81f04)},
                     {UINT64_C(0xab3c2fddeeaad25a), UINT64_C(0xd527e81cad7626c4)},
                     {UINT64_C(0xd60b3bd56a5586f1), UINT64_C(0x8a71e223d8d3b075)},
                     {UINT64_C(0x85c7056562757456), UINT64_C(0xf6872d5667844e4a)},
                     {UINT64_C(0xa738c6bebb12d16c), UINT64_C(0xb428f8ac016561dc)},
                     {UINT64_C(0xd106f86e69d785c7), UINT64_C(0xe13336d701beba53)},
                     {UINT64_C(0x82a45b450226b39c), UINT64_C(0xecc0024661173474)},
                     {UINT64_C(0xa34d721642b06084), UINT64_C(0x27f002d7f95d0191)},
                     {UINT64_C(0xcc20ce9bd35c78a5), UINT64_C(0x31ec038df7b441f5)},
                     {UINT64_C(0xff290242c83396ce), UINT64_C(0x7e67047175a15272)},
                     {UINT64_C(0x9f79a169bd203e41), UINT64_C(0x0f0062c6e984d387)},
                     {UINT64_C(0xc75809c42c684dd1), UINT64_C(0x52c07b78a3e60869)},
                     {UINT64_C(0xf92e0c3537826145), UINT64_C(0xa7709a56ccdf8a83)},
                     {UINT64_C(0x9bbcc7a142b17ccb), UINT64_C(0x88a66076400bb692)},
                     {UINT64_C(0xc2abf989935ddbfe), UINT64_C(0x6acff893d00ea436)},
                     {UINT64_C(0xf356f7ebf83552fe), UINT64_C(0x0583f6b8c4124d44)},
                     {UINT64_C(0x98165af37b2153de), UINT64_C(0xc3727a337a8b704b)},
                     {UINT64_C(0xbe1bf1b059e9a8d6), UINT64_C(0x744f18c0592e4c5d)},
                     {UINT64_C(0xeda2ee1c7064130c), UINT64_C(0x1162def06f79df74)},
                     {UINT64_C(0x9485d4d1c63e8be7), UINT64_C(0x8addcb5645ac2ba9)},
                     {UINT64_C(0xb9a74a0637ce2ee1), UINT64_C(0x6d953e2bd7173693)},
                     {UINT64_C(0xe8111c87c5c1ba99), UINT64_C(0xc8fa8db6ccdd0438)},
                     {UINT64_C(0x910ab1d4db9914a0), UINT64_C(0x1d9c9892400a22a3)},
                     {UINT64_C(0xb54d5e4a127f59c8), UINT64_C(0x2503beb6d00cab4c)},
                     {UINT64_C(0xe2a0b5dc971f303a), UINT64_C(0x2e44ae64840fd61e)},
                     {UINT64_C(0x8da471a9de737e24), UINT64_C(0x5ceaecfed289e5d3)},
                     {UINT64_C(0xb10d8e1456105dad), UINT64_C(0x7425a83e872c5f48)},
                     {UINT64_C(0xdd50f1996b947518), UINT64_C(0xd12f124e28f7771a)},
                     {UINT64_C(0x8a5296ffe33cc92f), UINT64_C(0x82bd6b70d99aaa70)},
                     {UINT64_C(0xace73cbfdc0bfb7b), UINT64_C(0x636cc64d1001550c)},
                     {UINT64_C(0xd8210befd30efa5a), UINT64_C(0x3c47f7e05401aa4f)},
                     {UINT64_C(0x8714a775e3e95c78), UINT64_C(0x65acfaec34810a72)},
                     {UINT64_C(0xa8d9d1535ce3b396), UINT64_C(0x7f1839a741a14d0e)},
                     {UINT64_C(0xd31045a8341ca07c), UINT64_C(0x1ede48111209a051)},
                     {UINT64_C(0x83ea2b892091e44d), UINT64_C(0x934aed0aab460433)},
                     {UINT64_C(0xa4e4b66b68b65d60), UINT64_C(0xf81da84d56178540)},
                     {UINT64_C(0xce1de40642e3f4b9), UINT64_C(0x36251260ab9d668f)},
                     {UINT64_C(0x80d2ae83e9ce78f3), UINT64_C(0xc1d72b7c6b42601a)},
                     {UINT64_C(0xa1075a24e4421730), UINT64_C(0xb24cf65b8612f820)},
                     {UINT64_C(0xc94930ae1d529cfc), UINT64_C(0xdee033f26797b628)},
                     {UINT64_C(0xfb9b7cd9a4a7443c), UINT64_C(0x169840ef017da3b2)},
                     {UINT64_C(0x9d412e0806e88aa5), UINT64_C(0x8e1f289560ee864f)},
                     {UINT64_C(0xc491798a08a2ad4e), UINT64_C(0xf1a6f2bab92a27e3)},
                     {UINT64_C(0xf5b5d7ec8acb58a2), UINT64_C(0xae10af696774b1dc)},
                     {UINT64_C(0x9991a6f3d6bf1765), UINT64_C(0xacca6da1e0a8ef2a)},
                     {UINT64_C(0xbff610b0cc6edd3f), UINT64_C(0x17fd090a58d32af4)},
                     {UINT64_C(0xeff394dcff8a948e), UINT64_C(0xddfc4b4cef07f5b1)},
                     {UINT64_C(0x95f83d0a1fb69cd9), UINT64_C(0x4abdaf101564f98f)},
                     {UINT64_C(0xbb764c4ca7a4440f), UINT64_C(0x9d6d1ad41abe37f2)},
                     {UINT64_C(0xea53df5fd18d5513), UINT64_C(0x84c86189216dc5ee)},
                     {UINT64_C(0x92746b9be2f8552c), UINT64_C(0x32fd3cf5b4e49bb5)},
                     {UINT64_C(0xb7118682dbb66a77), UINT64_C(0x3fbc8c33221dc2a2)},
                     {UINT64_C(0xe4d5e82392a40515), UINT64_C(0x0fabaf3feaa5334b)},
                     {UINT64_C(0x8f05b1163ba6832d), UINT64_C(0x29cb4d87f2a7400f)},
                     {UINT64_C(0xb2c71d5bca9023f8), UINT64_C(0x743e20e9ef511013)},
                     {UINT64_C(0xdf78e4b2bd342cf6), UINT64_C(0x914da9246b255417)},
                     {UINT64_C(0x8bab8eefb6409c1a), UINT64_C(0x1ad089b6c2f7548f)},
                     {UINT64_C(0xae9672aba3d0c320), UINT64_C(0xa184ac2473b529b2)},
                     {UINT64_C(0xda3c0f568cc4f3e8), UINT64_C(0xc9e5d72d90a2741f)},
                     {UINT64_C(0x8865899617fb1871), UINT64_C(0x7e2fa67c7a658893)},
                     {UINT64_C(0xaa7eebfb9df9de8d), UINT64_C(0xddbb901b98feeab8)},
                     {UINT64_C(0xd51ea6fa85785631), UINT64_C(0x552a74227f3ea566)},
                     {UINT64_C(0x8533285c936b35de), UINT64_C(0xd53a88958f872760)},
                     {UINT64_C(0xa67ff273b8460356), UINT64_C(0x8a892abaf368f138)},
                     {UINT64_C(0xd01fef10a657842c), UINT64_C(0x2d2b7569b0432d86)},
                     {UINT64_C(0x8213f56a67f6b29b), UINT64_C(0x9c3b29620e29fc74)},
                     {UINT64_C(0xa298f2c501f45f42), UINT64_C(0x8349f3ba91b47b90)},
                     {UINT64_C(0xcb3f2f7642717713), UINT64_C(0x241c70a936219a74)},
                     {UINT64_C(0xfe0efb53d30dd4d7), UINT64_C(0xed238cd383aa0111)},
                     {UINT64_C(0x9ec95d1463e8a506), UINT64_C(0xf4363804324a40ab)},
                     {UINT64_C(0xc67bb4597ce2ce48), UINT64_C(0xb143c6053edcd0d6)},
                     {UINT64_C(0xf81aa16fdc1b81da), UINT64_C(0xdd94b7868e94050b)},
                     {UINT64_C(0x9b10a4e5e9913128), UINT64_C(0xca7cf2b4191c8327)},
                     {UINT64_C(0xc1d4ce1f63f57d72), UINT64_C(0xfd1c2f611f63a3f1)},
                     {UINT64_C(0xf24a01a73cf2dccf), UINT64_C(0xbc633b39673c8ced)},
                     {UINT64_C(0x976e41088617ca01), UINT64_C(0xd5be0503e085d814)},
                     {UINT64_C(0xbd49d14aa79dbc82), UINT64_C(0x4b2d8644d8a74e19)},
                     {UINT64_C(0xec9c459d51852ba2), UINT64_C(0xddf8e7d60ed1219f)},
                     {UINT64_C(0x93e1ab8252f33b45), UINT64_C(0xcabb90e5c942b504)},
                     {UINT64_C(0xb8da1662e7b00a17), UINT64_C(0x3d6a751f3b936244)},
                     {UINT64_C(0xe7109bfba19c0c9d), UINT64_C(0x0cc512670a783ad5)},
                     {UINT64_C(0x906a617d450187e2), UINT64_C(0x27fb2b80668b24c6)},
                     {UINT64_C(0xb484f9dc9641e9da), UINT64_C(0xb1f9f660802dedf7)},
                     {UINT64_C(0xe1a63853bbd26451), UINT64_C(0x5e7873f8a0396974)},
                     {UINT64_C(0x8d07e33455637eb2), UINT64_C(0xdb0b487b6423e1e9)},
                     {UINT64_C(0xb049dc016abc5e5f), UINT64_C(0x91ce1a9a3d2cda63)},
                     {UINT64_C(0xdc5c5301c56b75f7), UINT64_C(0x7641a140cc7810fc)},
                     {UINT64_C(0x89b9b3e11b6329ba), UINT64_C(0xa9e904c87fcb0a9e)},
                     {UINT64_C(0xac2820d9623bf429), UINT64_C(0x546345fa9fbdcd45)},
                     {UINT64_C(0xd732290fbacaf133), UINT64_C(0xa97c177947ad4096)},
                     {UINT64_C(0x867f59a9d4bed6c0), UINT64_C(0x49ed8eabcccc485e)},
                     {UINT64_C(0xa81f301449ee8c70), UINT64_C(0x5c68f256bfff5a75)},
                     {UINT64_C(0xd226fc195c6a2f8c), UINT64_C(0x73832eec6fff3112)},
                     {UINT64_C(0x83585d8fd9c25db7), UINT64_C(0xc831fd53c5ff7eac)},
                     {UINT64_C(0xa42e74f3d032f525), UINT64_C(0xba3e7ca8b77f5e56)},
                     {UINT64_C(0xcd3a1230c43fb26f), UINT64_C(0x28ce1bd2e55f35ec)},
                     {UINT64_C(0x80444b5e7aa7cf85), UINT64_C(0x7980d163cf5b81b4)},
                     {UINT64_C(0xa0555e361951c366), UINT64_C(0xd7e105bcc3326220)},
                     {UINT64_C(0xc86ab5c39fa63440), UINT64_C(0x8dd9472bf3fefaa8)},
                     {UINT64_C(0xfa856334878fc150), UINT64_C(0xb14f98f6f0feb952)},
                     {UINT64_C(0x9c935e00d4b9d8d2), UINT64_C(0x6ed1bf9a569f33d4)},
                     {UINT64_C(0xc3b8358109e84f07), UINT64_C(0x0a862f80ec4700c9)},
                     {UINT64_C(0xf4a642e14c6262c8), UINT64_C(0xcd27bb612758c0fb)},
                     {UINT64_C(0x98e7e9cccfbd7dbd), UINT64_C(0x8038d51cb897789d)},
                     {UINT64_C(0xbf21e44003acdd2c), UINT64_C(0xe0470a63e6bd56c4)},
                     {UINT64_C(0xeeea5d5004981478), UINT64_C(0x1858ccfce06cac75)},
                     {UINT64_C(0x95527a5202df0ccb), UINT64_C(0x0f37801e0c43ebc9)},
                     {UINT64_C(0xbaa718e68396cffd), UINT64_C(0xd30560258f54e6bb)},
                     {UINT64_C(0xe950df20247c83fd), UINT64_C(0x47c6b82ef32a206a)},
                     {UINT64_C(0x91d28b7416cdd27e), UINT64_C(0x4cdc331d57fa5442)},
                     {UINT64_C(0xb6472e511c81471d), UINT64_C(0xe0133fe4adf8e953)},
                     {UINT64_C(0xe3d8f9e563a198e5), UINT64_C(0x58180fddd97723a7)},
                     {UINT64_C(0x8e679c2f5e44ff8f), UINT64_C(0x570f09eaa7ea7649)},
                     {UINT64_C(0xb201833b35d63f73), UINT64_C(0x2cd2cc6551e513db)},
                     {UINT64_C(0xde81e40a034bcf4f), UINT64_C(0xf8077f7ea65e58d2)},
                     {UINT64_C(0x8b112e86420f6191), UINT64_C(0xfb04afaf27faf783)},
                     {UINT64_C(0xadd57a27d29339f6), UINT64_C(0x79c5db9af1f9b564)},
                     {UINT64_C(0xd94ad8b1c7380874), UINT64_C(0x18375281ae7822bd)},
                     {UINT64_C(0x87cec76f1c830548), UINT64_C(0x8f2293910d0b15b6)},
                     {UINT64_C(0xa9c2794ae3a3c69a), UINT64_C(0xb2eb3875504ddb23)},
                     {UINT64_C(0xd433179d9c8cb841), UINT64_C(0x5fa60692a46151ec)},
                     {UINT64_C(0x849feec281d7f328), UINT64_C(0xdbc7c41ba6bcd334)},
                     {UINT64_C(0xa5c7ea73224deff3), UINT64_C(0x12b9b522906c0801)},
                     {UINT64_C(0xcf39e50feae16bef), UINT64_C(0xd768226b34870a01)},
                     {UINT64_C(0x81842f29f2cce375), UINT64_C(0xe6a1158300d46641)},
                     {UINT64_C(0xa1e53af46f801c53), UINT64_C(0x60495ae3c1097fd1)},
                     {UINT64_C(0xca5e89b18b602368), UINT64_C(0x385bb19cb14bdfc5)},
                     {UINT64_C(0xfcf62c1dee382c42), UINT64_C(0x46729e03dd9ed7b6)},
                     {UINT64_C(0x9e19db92b4e31ba9), UINT64_C(0x6c07a2c26a8346d2)},
                     {UINT64_C(0xc5a05277621be293), UINT64_C(0xc7098b7305241886)},
                     {UINT64_C(0xf70867153aa2db38), UINT64_C(0xb8cbee4fc66d1ea8)}}};
        };
#if !JKJ_HAS_INLINE_VARIABLE
        // decltype(...) should not depend on Dummy; see
        // https://stackoverflow.com/questions/76438400/decltype-on-static-variable-in-template-class.
        template <class Dummy>
        constexpr decltype(cache_holder<ieee754_binary64>::cache)
            cache_holder<ieee754_binary64, Dummy>::cache;
#endif

        // Compressed cache.
        template <class FloatFormat, class Dummy = void>
        struct compressed_cache_holder {
            using cache_entry_type = typename cache_holder<FloatFormat>::cache_entry_type;
            static constexpr int cache_bits = cache_holder<FloatFormat>::cache_bits;
            static constexpr int min_k = cache_holder<FloatFormat>::min_k;
            static constexpr int max_k = cache_holder<FloatFormat>::max_k;

            template <class ShiftAmountType, class DecimalExponentType>
            static constexpr cache_entry_type get_cache(DecimalExponentType k) noexcept {
                return cache_holder<FloatFormat>::cache[k - min_k];
            }
        };

        template <class Dummy>
        struct compressed_cache_holder<ieee754_binary32, Dummy> {
            using cache_entry_type = cache_holder<ieee754_binary32>::cache_entry_type;
            static constexpr int cache_bits = cache_holder<ieee754_binary32>::cache_bits;
            static constexpr int min_k = cache_holder<ieee754_binary32>::min_k;
            static constexpr int max_k = cache_holder<ieee754_binary32>::max_k;
            static constexpr int compression_ratio = 13;
            static constexpr detail::stdr::size_t compressed_table_size =
                detail::stdr::size_t((max_k - min_k + compression_ratio) / compression_ratio);
            static constexpr detail::stdr::size_t pow5_table_size =
                detail::stdr::size_t((compression_ratio + 1) / 2);

            using cache_holder_t = detail::array<cache_entry_type, compressed_table_size>;
            using pow5_holder_t = detail::array<detail::stdr::uint_least16_t, pow5_table_size>;

#if JKJ_HAS_CONSTEXPR17
            static constexpr cache_holder_t cache JKJ_STATIC_DATA_SECTION = [] {
                cache_holder_t res{};
                for (detail::stdr::size_t i = 0; i < compressed_table_size; ++i) {
                    res[i] = cache_holder<ieee754_binary32>::cache[i * compression_ratio];
                }
                return res;
            }();
            static constexpr pow5_holder_t pow5_table JKJ_STATIC_DATA_SECTION = [] {
                pow5_holder_t res{};
                detail::stdr::uint_least16_t p = 1;
                for (detail::stdr::size_t i = 0; i < pow5_table_size; ++i) {
                    res[i] = p;
                    p *= 5;
                }
                return res;
            }();
#else
            template <detail::stdr::size_t... indices>
            static constexpr cache_holder_t make_cache(detail::index_sequence<indices...>) {
                return {cache_holder<ieee754_binary32>::cache[indices * compression_ratio]...};
            }
            static constexpr cache_holder_t cache JKJ_STATIC_DATA_SECTION =
                make_cache(detail::make_index_sequence<compressed_table_size>{});

            template <detail::stdr::size_t... indices>
            static constexpr pow5_holder_t make_pow5_table(detail::index_sequence<indices...>) {
                return {detail::compute_power<indices>(detail::stdr::uint_least16_t(5))...};
            }
            static constexpr pow5_holder_t pow5_table JKJ_STATIC_DATA_SECTION =
                make_pow5_table(detail::make_index_sequence<pow5_table_size>{});
#endif

            template <class ShiftAmountType, class DecimalExponentType>
            static JKJ_CONSTEXPR20 cache_entry_type get_cache(DecimalExponentType k) noexcept {
                // Compute the base index.
                // Supposed to compute (k - min_k) / compression_ratio.
                static_assert(max_k - min_k <= 89 && compression_ratio == 13, "");
                static_assert(max_k - min_k <= detail::stdr::numeric_limits<DecimalExponentType>::max(),
                              "");
                auto const cache_index =
                    DecimalExponentType(detail::stdr::uint_fast16_t(DecimalExponentType(k - min_k) *
                                                                    detail::stdr::int_fast16_t(79)) >>
                                        10);
                auto const kb = DecimalExponentType(cache_index * compression_ratio + min_k);
                auto const offset = DecimalExponentType(k - kb);

                // Get the base cache.
                auto const base_cache = cache[cache_index];

                if (offset == 0) {
                    return base_cache;
                }
                else {
                    // Compute the required amount of bit-shift.
                    auto const alpha =
                        ShiftAmountType(detail::log::floor_log2_pow10<min_k, max_k>(k) -
                                        detail::log::floor_log2_pow10<min_k, max_k>(kb) - offset);
                    assert(alpha > 0 && alpha < 64);

                    // Try to recover the real cache.
                    auto const pow5 =
                        offset >= 7
                            ? detail::stdr::uint_fast32_t(detail::stdr::uint_fast32_t(pow5_table[6]) *
                                                          pow5_table[offset - 6])
                            : detail::stdr::uint_fast32_t(pow5_table[offset]);
                    auto mul_result = detail::wuint::umul128(base_cache, pow5);
                    auto const recovered_cache =
                        cache_entry_type((((mul_result.high() << ShiftAmountType(64 - alpha)) |
                                           (mul_result.low() >> alpha)) +
                                          1) &
                                         UINT64_C(0xffffffffffffffff));
                    assert(recovered_cache != 0);

                    return recovered_cache;
                }
            }
        };
#if !JKJ_HAS_INLINE_VARIABLE
        template <class Dummy>
        constexpr typename compressed_cache_holder<ieee754_binary32, Dummy>::cache_holder_t
            compressed_cache_holder<ieee754_binary32, Dummy>::cache;
        template <class Dummy>
        constexpr typename compressed_cache_holder<ieee754_binary32, Dummy>::pow5_holder_t
            compressed_cache_holder<ieee754_binary32, Dummy>::pow5_table;
#endif

        template <class Dummy>
        struct compressed_cache_holder<ieee754_binary64, Dummy> {
            using cache_entry_type = cache_holder<ieee754_binary64>::cache_entry_type;
            static constexpr int cache_bits = cache_holder<ieee754_binary64>::cache_bits;
            static constexpr int min_k = cache_holder<ieee754_binary64>::min_k;
            static constexpr int max_k = cache_holder<ieee754_binary64>::max_k;
            static constexpr int compression_ratio = 27;
            static constexpr detail::stdr::size_t compressed_table_size =
                detail::stdr::size_t((max_k - min_k + compression_ratio) / compression_ratio);
            static constexpr detail::stdr::size_t pow5_table_size =
                detail::stdr::size_t(compression_ratio);

            using cache_holder_t = detail::array<cache_entry_type, compressed_table_size>;
            using pow5_holder_t = detail::array<detail::stdr::uint_least64_t, pow5_table_size>;

#if JKJ_HAS_CONSTEXPR17
            static constexpr cache_holder_t cache JKJ_STATIC_DATA_SECTION = [] {
                cache_holder_t res{};
                for (detail::stdr::size_t i = 0; i < compressed_table_size; ++i) {
                    res[i] = cache_holder<ieee754_binary64>::cache[i * compression_ratio];
                }
                return res;
            }();
            static constexpr pow5_holder_t pow5_table JKJ_STATIC_DATA_SECTION = [] {
                pow5_holder_t res{};
                detail::stdr::uint_least64_t p = 1;
                for (detail::stdr::size_t i = 0; i < pow5_table_size; ++i) {
                    res[i] = p;
                    p *= 5;
                }
                return res;
            }();
#else
            template <detail::stdr::size_t... indices>
            static constexpr cache_holder_t make_cache(detail::index_sequence<indices...>) {
                return {cache_holder<ieee754_binary64>::cache[indices * compression_ratio]...};
            }
            static constexpr cache_holder_t cache JKJ_STATIC_DATA_SECTION =
                make_cache(detail::make_index_sequence<compressed_table_size>{});

            template <detail::stdr::size_t... indices>
            static constexpr pow5_holder_t make_pow5_table(detail::index_sequence<indices...>) {
                return {detail::compute_power<indices>(detail::stdr::uint_least64_t(5))...};
            }
            static constexpr pow5_holder_t pow5_table JKJ_STATIC_DATA_SECTION =
                make_pow5_table(detail::make_index_sequence<pow5_table_size>{});
#endif

            template <class ShiftAmountType, class DecimalExponentType>
            static JKJ_CONSTEXPR20 cache_entry_type get_cache(DecimalExponentType k) noexcept {
                // Compute the base index.
                // Supposed to compute (k - min_k) / compression_ratio.
                static_assert(max_k - min_k <= 619 && compression_ratio == 27, "");
                static_assert(max_k - min_k <= detail::stdr::numeric_limits<DecimalExponentType>::max(),
                              "");
                auto const cache_index =
                    DecimalExponentType(detail::stdr::uint_fast32_t(DecimalExponentType(k - min_k) *
                                                                    detail::stdr::int_fast32_t(607)) >>
                                        14);
                auto const kb = DecimalExponentType(cache_index * compression_ratio + min_k);
                auto const offset = DecimalExponentType(k - kb);

                // Get the base cache.
                auto const base_cache = cache[cache_index];

                if (offset == 0) {
                    return base_cache;
                }
                else {
                    // Compute the required amount of bit-shift.
                    auto const alpha =
                        ShiftAmountType(detail::log::floor_log2_pow10<min_k, max_k>(k) -
                                        detail::log::floor_log2_pow10<min_k, max_k>(kb) - offset);
                    assert(alpha > 0 && alpha < 64);

                    // Try to recover the real cache.
                    auto const pow5 = pow5_table[offset];
                    auto recovered_cache = detail::wuint::umul128(base_cache.high(), pow5);
                    auto const middle_low = detail::wuint::umul128(base_cache.low(), pow5);

                    recovered_cache += middle_low.high();

                    auto const high_to_middle = detail::stdr::uint_least64_t(
                        (recovered_cache.high() << ShiftAmountType(64 - alpha)) &
                        UINT64_C(0xffffffffffffffff));
                    auto const middle_to_low = detail::stdr::uint_least64_t(
                        (recovered_cache.low() << ShiftAmountType(64 - alpha)) &
                        UINT64_C(0xffffffffffffffff));

                    recovered_cache = {(recovered_cache.low() >> alpha) | high_to_middle,
                                       ((middle_low.low() >> alpha) | middle_to_low)};

                    assert(recovered_cache.low() != UINT64_C(0xffffffffffffffff));
                    recovered_cache = {recovered_cache.high(),
                                       detail::stdr::uint_least64_t(recovered_cache.low() + 1)};

                    return recovered_cache;
                }
            }
        };
#if !JKJ_HAS_INLINE_VARIABLE
        template <class Dummy>
        constexpr typename compressed_cache_holder<ieee754_binary64, Dummy>::cache_holder_t
            compressed_cache_holder<ieee754_binary64, Dummy>::cache;
        template <class Dummy>
        constexpr typename compressed_cache_holder<ieee754_binary64, Dummy>::pow5_holder_t
            compressed_cache_holder<ieee754_binary64, Dummy>::pow5_table;
#endif

        ////////////////////////////////////////////////////////////////////////////////////////
        // Forward declarations of user-specializable templates used in the main algorithm.
        ////////////////////////////////////////////////////////////////////////////////////////

        // Remove trailing zeros from significand and add the number of removed zeros into
        // exponent.
        template <class TrailingZeroPolicy, class Format, class DecimalSignificand,
                  class DecimalExponentType>
        struct remove_trailing_zeros_traits;

        // Users can specialize this traits class to make Dragonbox work with their own formats.
        // However, this requires detailed knowledge on how the algorithm works, so it is recommended to
        // read through the paper.
        template <class FormatTraits, class CacheEntryType, detail::stdr::size_t cache_bits_>
        struct multiplication_traits;

        // A collection of some common definitions to reduce boilerplate.
        template <class FormatTraits, class CacheEntryType, detail::stdr::size_t cache_bits_>
        struct multiplication_traits_base {
            using format = typename FormatTraits::format;
            static constexpr int significand_bits = format::significand_bits;
            static constexpr int total_bits = format::total_bits;
            using carrier_uint = typename FormatTraits::carrier_uint;
            using cache_entry_type = CacheEntryType;
            static constexpr int cache_bits = int(cache_bits_);

            struct compute_mul_result {
                carrier_uint integer_part;
                bool is_integer;
            };
            struct compute_mul_parity_result {
                bool parity;
                bool is_integer;
            };
        };


        ////////////////////////////////////////////////////////////////////////////////////////
        // Policies.
        ////////////////////////////////////////////////////////////////////////////////////////

        namespace detail {
            template <class T>
            struct dummy {};
        }

        namespace policy {
            namespace sign {
                JKJ_INLINE_VARIABLE struct ignore_t {
                    using sign_policy = ignore_t;
                    static constexpr bool return_has_sign = false;

#if defined(_MSC_VER) && !defined(__clang__)
                    // See
                    // https://developercommunity.visualstudio.com/t/Failure-to-optimize-intrinsics/10628226
                    template <class SignedSignificandBits, class DecimalSignificand,
                              class DecimalExponentType>
                    static constexpr decimal_fp<DecimalSignificand, DecimalExponentType, false, false>
                    handle_sign(
                        SignedSignificandBits,
                        decimal_fp<DecimalSignificand, DecimalExponentType, false, false> r) noexcept {
                        return {r.significand, r.exponent};
                    }
                    template <class SignedSignificandBits, class DecimalSignificand,
                              class DecimalExponentType>
                    static constexpr decimal_fp<DecimalSignificand, DecimalExponentType, false, true>
                    handle_sign(
                        SignedSignificandBits,
                        decimal_fp<DecimalSignificand, DecimalExponentType, false, true> r) noexcept {
                        return {r.significand, r.exponent, r.may_have_trailing_zeros};
                    }
#else
                    template <class SignedSignificandBits, class UnsignedDecimalFp>
                    static constexpr UnsignedDecimalFp handle_sign(SignedSignificandBits,
                                                                   UnsignedDecimalFp r) noexcept {
                        return r;
                    }
#endif
                } ignore = {};

                JKJ_INLINE_VARIABLE struct return_sign_t {
                    using sign_policy = return_sign_t;
                    static constexpr bool return_has_sign = true;

                    template <class SignedSignificandBits, class UnsignedDecimalFp>
                    static constexpr detail::unsigned_decimal_fp_to_signed_t<UnsignedDecimalFp>
                    handle_sign(SignedSignificandBits s, UnsignedDecimalFp r) noexcept {
                        return add_sign_to_unsigned_decimal_fp(s.is_negative(), r);
                    }
                } return_sign = {};
            }

            namespace trailing_zero {
                JKJ_INLINE_VARIABLE struct ignore_t {
                    using trailing_zero_policy = ignore_t;
                    static constexpr bool report_trailing_zeros = false;

                    template <class Format, class DecimalSignificand, class DecimalExponentType>
                    static constexpr unsigned_decimal_fp<DecimalSignificand, DecimalExponentType, false>
                    on_trailing_zeros(DecimalSignificand significand,
                                      DecimalExponentType exponent) noexcept {
                        return {significand, exponent};
                    }

                    template <class Format, class DecimalSignificand, class DecimalExponentType>
                    static constexpr unsigned_decimal_fp<DecimalSignificand, DecimalExponentType, false>
                    no_trailing_zeros(DecimalSignificand significand,
                                      DecimalExponentType exponent) noexcept {
                        return {significand, exponent};
                    }
                } ignore = {};

                JKJ_INLINE_VARIABLE struct remove_t {
                    using trailing_zero_policy = remove_t;
                    static constexpr bool report_trailing_zeros = false;

                    template <class Format, class DecimalSignificand, class DecimalExponentType>
                    JKJ_FORCEINLINE static JKJ_CONSTEXPR14
                        unsigned_decimal_fp<DecimalSignificand, DecimalExponentType, false>
                        on_trailing_zeros(DecimalSignificand significand,
                                          DecimalExponentType exponent) noexcept {
                        remove_trailing_zeros_traits<
                            remove_t, Format, DecimalSignificand,
                            DecimalExponentType>::remove_trailing_zeros(significand, exponent);
                        return {significand, exponent};
                    }

                    template <class Format, class DecimalSignificand, class DecimalExponentType>
                    static constexpr unsigned_decimal_fp<DecimalSignificand, DecimalExponentType, false>
                    no_trailing_zeros(DecimalSignificand significand,
                                      DecimalExponentType exponent) noexcept {
                        return {significand, exponent};
                    }
                } remove = {};

                JKJ_INLINE_VARIABLE struct remove_compact_t {
                    using trailing_zero_policy = remove_compact_t;
                    static constexpr bool report_trailing_zeros = false;

                    template <class Format, class DecimalSignificand, class DecimalExponentType>
                    JKJ_FORCEINLINE static JKJ_CONSTEXPR14
                        unsigned_decimal_fp<DecimalSignificand, DecimalExponentType, false>
                        on_trailing_zeros(DecimalSignificand significand,
                                          DecimalExponentType exponent) noexcept {
                        remove_trailing_zeros_traits<
                            remove_compact_t, Format, DecimalSignificand,
                            DecimalExponentType>::remove_trailing_zeros(significand, exponent);
                        return {significand, exponent};
                    }

                    template <class Format, class DecimalSignificand, class DecimalExponentType>
                    static constexpr unsigned_decimal_fp<DecimalSignificand, DecimalExponentType, false>
                    no_trailing_zeros(DecimalSignificand significand,
                                      DecimalExponentType exponent) noexcept {
                        return {significand, exponent};
                    }
                } remove_compact = {};

                JKJ_INLINE_VARIABLE struct report_t {
                    using trailing_zero_policy = report_t;
                    static constexpr bool report_trailing_zeros = true;

                    template <class Format, class DecimalSignificand, class DecimalExponentType>
                    static constexpr unsigned_decimal_fp<DecimalSignificand, DecimalExponentType, true>
                    on_trailing_zeros(DecimalSignificand significand,
                                      DecimalExponentType exponent) noexcept {
                        return {significand, exponent, true};
                    }

                    template <class Format, class DecimalSignificand, class DecimalExponentType>
                    static constexpr unsigned_decimal_fp<DecimalSignificand, DecimalExponentType, true>
                    no_trailing_zeros(DecimalSignificand significand,
                                      DecimalExponentType exponent) noexcept {
                        return {significand, exponent, false};
                    }
                } report = {};
            }

            namespace decimal_to_binary_rounding {
                enum class tag_t { to_nearest, left_closed_directed, right_closed_directed };

                namespace interval_type {
                    struct symmetric_boundary {
                        static constexpr bool is_symmetric = true;
                        bool is_closed;
                        constexpr bool include_left_endpoint() const noexcept { return is_closed; }
                        constexpr bool include_right_endpoint() const noexcept { return is_closed; }
                    };
                    struct asymmetric_boundary {
                        static constexpr bool is_symmetric = false;
                        bool is_left_closed;
                        constexpr bool include_left_endpoint() const noexcept { return is_left_closed; }
                        constexpr bool include_right_endpoint() const noexcept {
                            return !is_left_closed;
                        }
                    };
                    struct closed {
                        static constexpr bool is_symmetric = true;
                        static constexpr bool include_left_endpoint() noexcept { return true; }
                        static constexpr bool include_right_endpoint() noexcept { return true; }
                    };
                    struct open {
                        static constexpr bool is_symmetric = true;
                        static constexpr bool include_left_endpoint() noexcept { return false; }
                        static constexpr bool include_right_endpoint() noexcept { return false; }
                    };
                    struct left_closed_right_open {
                        static constexpr bool is_symmetric = false;
                        static constexpr bool include_left_endpoint() noexcept { return true; }
                        static constexpr bool include_right_endpoint() noexcept { return false; }
                    };
                    struct right_closed_left_open {
                        static constexpr bool is_symmetric = false;
                        static constexpr bool include_left_endpoint() noexcept { return false; }
                        static constexpr bool include_right_endpoint() noexcept { return true; }
                    };
                }

                JKJ_INLINE_VARIABLE struct nearest_to_even_t {
                    using decimal_to_binary_rounding_policy = nearest_to_even_t;
                    using interval_type_provider = nearest_to_even_t;
                    static constexpr auto tag = tag_t::to_nearest;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        dragonbox::detail::declval<nearest_to_even_t>(), Args{}...))
                    delegate(SignedSignificandBits, Func f, Args... args) noexcept {
                        return f(nearest_to_even_t{}, args...);
                    }

                    template <class SignedSignificandBits>
                    static constexpr interval_type::symmetric_boundary
                    normal_interval(SignedSignificandBits s) noexcept {
                        return {s.has_even_significand_bits()};
                    }

                    template <class SignedSignificandBits>
                    static constexpr interval_type::closed
                    shorter_interval(SignedSignificandBits) noexcept {
                        return {};
                    }
                } nearest_to_even = {};

                JKJ_INLINE_VARIABLE struct nearest_to_odd_t {
                    using decimal_to_binary_rounding_policy = nearest_to_odd_t;
                    using interval_type_provider = nearest_to_odd_t;
                    static constexpr auto tag = tag_t::to_nearest;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        dragonbox::detail::declval<nearest_to_odd_t>(), Args{}...))
                    delegate(SignedSignificandBits, Func f, Args... args) noexcept {
                        return f(nearest_to_odd_t{}, args...);
                    }

                    template <class SignedSignificandBits>
                    static constexpr interval_type::symmetric_boundary
                    normal_interval(SignedSignificandBits s) noexcept {
                        return {!s.has_even_significand_bits()};
                    }
                    template <class SignedSignificandBits>
                    static constexpr interval_type::open
                    shorter_interval(SignedSignificandBits) noexcept {
                        return {};
                    }
                } nearest_to_odd = {};

                JKJ_INLINE_VARIABLE struct nearest_toward_plus_infinity_t {
                    using decimal_to_binary_rounding_policy = nearest_toward_plus_infinity_t;
                    using interval_type_provider = nearest_toward_plus_infinity_t;
                    static constexpr auto tag = tag_t::to_nearest;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        dragonbox::detail::declval<nearest_toward_plus_infinity_t>(), Args{}...))
                    delegate(SignedSignificandBits, Func f, Args... args) noexcept {
                        return f(nearest_toward_plus_infinity_t{}, args...);
                    }

                    template <class SignedSignificandBits>
                    static constexpr interval_type::asymmetric_boundary
                    normal_interval(SignedSignificandBits s) noexcept {
                        return {!s.is_negative()};
                    }
                    template <class SignedSignificandBits>
                    static constexpr interval_type::asymmetric_boundary
                    shorter_interval(SignedSignificandBits s) noexcept {
                        return {!s.is_negative()};
                    }
                } nearest_toward_plus_infinity = {};

                JKJ_INLINE_VARIABLE struct nearest_toward_minus_infinity_t {
                    using decimal_to_binary_rounding_policy = nearest_toward_minus_infinity_t;
                    using interval_type_provider = nearest_toward_minus_infinity_t;
                    static constexpr auto tag = tag_t::to_nearest;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        dragonbox::detail::declval<nearest_toward_minus_infinity_t>(), Args{}...))
                    delegate(SignedSignificandBits, Func f, Args... args) noexcept {
                        return f(nearest_toward_minus_infinity_t{}, args...);
                    }

                    template <class SignedSignificandBits>
                    static constexpr interval_type::asymmetric_boundary
                    normal_interval(SignedSignificandBits s) noexcept {
                        return {s.is_negative()};
                    }
                    template <class SignedSignificandBits>
                    static constexpr interval_type::asymmetric_boundary
                    shorter_interval(SignedSignificandBits s) noexcept {
                        return {s.is_negative()};
                    }
                } nearest_toward_minus_infinity = {};

                JKJ_INLINE_VARIABLE struct nearest_toward_zero_t {
                    using decimal_to_binary_rounding_policy = nearest_toward_zero_t;
                    using interval_type_provider = nearest_toward_zero_t;
                    static constexpr auto tag = tag_t::to_nearest;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        dragonbox::detail::declval<nearest_toward_zero_t>(), Args{}...))
                    delegate(SignedSignificandBits, Func f, Args... args) noexcept {
                        return f(nearest_toward_zero_t{}, args...);
                    }

                    template <class SignedSignificandBits>
                    static constexpr interval_type::right_closed_left_open
                    normal_interval(SignedSignificandBits) noexcept {
                        return {};
                    }
                    template <class SignedSignificandBits>
                    static constexpr interval_type::right_closed_left_open
                    shorter_interval(SignedSignificandBits) noexcept {
                        return {};
                    }
                } nearest_toward_zero = {};

                JKJ_INLINE_VARIABLE struct nearest_away_from_zero_t {
                    using decimal_to_binary_rounding_policy = nearest_away_from_zero_t;
                    using interval_type_provider = nearest_away_from_zero_t;
                    static constexpr auto tag = tag_t::to_nearest;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        dragonbox::detail::declval<nearest_away_from_zero_t>(), Args{}...))
                    delegate(SignedSignificandBits, Func f, Args... args) noexcept {
                        return f(nearest_away_from_zero_t{}, args...);
                    }

                    template <class SignedSignificandBits>
                    static constexpr interval_type::left_closed_right_open
                    normal_interval(SignedSignificandBits) noexcept {
                        return {};
                    }
                    template <class SignedSignificandBits>
                    static constexpr interval_type::left_closed_right_open
                    shorter_interval(SignedSignificandBits) noexcept {
                        return {};
                    }
                } nearest_away_from_zero = {};

                namespace detail {
                    struct nearest_always_closed_t {
                        using interval_type_provider = nearest_always_closed_t;
                        static constexpr auto tag = tag_t::to_nearest;

                        template <class SignedSignificandBits>
                        static constexpr interval_type::closed
                        normal_interval(SignedSignificandBits) noexcept {
                            return {};
                        }
                        template <class SignedSignificandBits>
                        static constexpr interval_type::closed
                        shorter_interval(SignedSignificandBits) noexcept {
                            return {};
                        }
                    };
                    struct nearest_always_open_t {
                        using interval_type_provider = nearest_always_open_t;
                        static constexpr auto tag = tag_t::to_nearest;

                        template <class SignedSignificandBits>
                        static constexpr interval_type::open
                        normal_interval(SignedSignificandBits) noexcept {
                            return {};
                        }
                        template <class SignedSignificandBits>
                        static constexpr interval_type::open
                        shorter_interval(SignedSignificandBits) noexcept {
                            return {};
                        }
                    };
                }

                JKJ_INLINE_VARIABLE struct nearest_to_even_static_boundary_t {
                    using decimal_to_binary_rounding_policy = nearest_to_even_static_boundary_t;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        detail::nearest_always_closed_t{}, Args{}...))
                    delegate(SignedSignificandBits s, Func f, Args... args) noexcept {
                        return s.has_even_significand_bits()
                                   ? f(detail::nearest_always_closed_t{}, args...)
                                   : f(detail::nearest_always_open_t{}, args...);
                    }
                } nearest_to_even_static_boundary = {};

                JKJ_INLINE_VARIABLE struct nearest_to_odd_static_boundary_t {
                    using decimal_to_binary_rounding_policy = nearest_to_odd_static_boundary_t;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        detail::nearest_always_closed_t{}, Args{}...))
                    delegate(SignedSignificandBits s, Func f, Args... args) noexcept {
                        return s.has_even_significand_bits()
                                   ? f(detail::nearest_always_open_t{}, args...)
                                   : f(detail::nearest_always_closed_t{}, args...);
                    }
                } nearest_to_odd_static_boundary = {};

                JKJ_INLINE_VARIABLE struct nearest_toward_plus_infinity_static_boundary_t {
                    using decimal_to_binary_rounding_policy =
                        nearest_toward_plus_infinity_static_boundary_t;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE
                        JKJ_SAFEBUFFERS static constexpr decltype(Func{}(nearest_toward_zero,
                                                                         Args{}...))
                        delegate(SignedSignificandBits s, Func f, Args... args) noexcept {
                        return s.is_negative() ? f(nearest_toward_zero, args...)
                                               : f(nearest_away_from_zero, args...);
                    }
                } nearest_toward_plus_infinity_static_boundary = {};

                JKJ_INLINE_VARIABLE struct nearest_toward_minus_infinity_static_boundary_t {
                    using decimal_to_binary_rounding_policy =
                        nearest_toward_minus_infinity_static_boundary_t;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE
                        JKJ_SAFEBUFFERS static constexpr decltype(Func{}(nearest_toward_zero,
                                                                         Args{}...))
                        delegate(SignedSignificandBits s, Func f, Args... args) noexcept {
                        return s.is_negative() ? f(nearest_away_from_zero, args...)
                                               : f(nearest_toward_zero, args...);
                    }
                } nearest_toward_minus_infinity_static_boundary = {};

                namespace detail {
                    struct left_closed_directed_t {
                        static constexpr auto tag = tag_t::left_closed_directed;
                    };
                    struct right_closed_directed_t {
                        static constexpr auto tag = tag_t::right_closed_directed;
                    };
                }

                JKJ_INLINE_VARIABLE struct toward_plus_infinity_t {
                    using decimal_to_binary_rounding_policy = toward_plus_infinity_t;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        detail::left_closed_directed_t{}, Args{}...))
                    delegate(SignedSignificandBits s, Func f, Args... args) noexcept {
                        return s.is_negative() ? f(detail::left_closed_directed_t{}, args...)
                                               : f(detail::right_closed_directed_t{}, args...);
                    }
                } toward_plus_infinity = {};

                JKJ_INLINE_VARIABLE struct toward_minus_infinity_t {
                    using decimal_to_binary_rounding_policy = toward_minus_infinity_t;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        detail::left_closed_directed_t{}, Args{}...))
                    delegate(SignedSignificandBits s, Func f, Args... args) noexcept {
                        return s.is_negative() ? f(detail::right_closed_directed_t{}, args...)
                                               : f(detail::left_closed_directed_t{}, args...);
                    }
                } toward_minus_infinity = {};

                JKJ_INLINE_VARIABLE struct toward_zero_t {
                    using decimal_to_binary_rounding_policy = toward_zero_t;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        detail::left_closed_directed_t{}, Args{}...))
                    delegate(SignedSignificandBits, Func f, Args... args) noexcept {
                        return f(detail::left_closed_directed_t{}, args...);
                    }
                } toward_zero = {};

                JKJ_INLINE_VARIABLE struct away_from_zero_t {
                    using decimal_to_binary_rounding_policy = away_from_zero_t;

                    template <class SignedSignificandBits, class Func, class... Args>
                    JKJ_FORCEINLINE JKJ_SAFEBUFFERS static constexpr decltype(Func{}(
                        detail::right_closed_directed_t{}, Args{}...))
                    delegate(SignedSignificandBits, Func f, Args... args) noexcept {
                        return f(detail::right_closed_directed_t{}, args...);
                    }
                } away_from_zero = {};
            }

            namespace binary_to_decimal_rounding {
                // (Always assumes nearest rounding modes, as there can be no tie for other rounding
                // modes.)
                enum class tag_t { do_not_care, to_even, to_odd, away_from_zero, toward_zero };

                // The parameter significand corresponds to 10\tilde{s}+t in the paper.

                JKJ_INLINE_VARIABLE struct do_not_care_t {
                    using binary_to_decimal_rounding_policy = do_not_care_t;
                    static constexpr auto tag = tag_t::do_not_care;

                    template <class CarrierUInt>
                    static constexpr bool prefer_round_down(CarrierUInt) noexcept {
                        return false;
                    }
                } do_not_care = {};

                JKJ_INLINE_VARIABLE struct to_even_t {
                    using binary_to_decimal_rounding_policy = to_even_t;
                    static constexpr auto tag = tag_t::to_even;

                    template <class CarrierUInt>
                    static constexpr bool prefer_round_down(CarrierUInt significand) noexcept {
                        return significand % 2 != 0;
                    }
                } to_even = {};

                JKJ_INLINE_VARIABLE struct to_odd_t {
                    using binary_to_decimal_rounding_policy = to_odd_t;
                    static constexpr auto tag = tag_t::to_odd;

                    template <class CarrierUInt>
                    static constexpr bool prefer_round_down(CarrierUInt significand) noexcept {
                        return significand % 2 == 0;
                    }
                } to_odd = {};

                JKJ_INLINE_VARIABLE struct away_from_zero_t {
                    using binary_to_decimal_rounding_policy = away_from_zero_t;
                    static constexpr auto tag = tag_t::away_from_zero;

                    template <class CarrierUInt>
                    static constexpr bool prefer_round_down(CarrierUInt) noexcept {
                        return false;
                    }
                } away_from_zero = {};

                JKJ_INLINE_VARIABLE struct toward_zero_t {
                    using binary_to_decimal_rounding_policy = toward_zero_t;
                    static constexpr auto tag = tag_t::toward_zero;

                    template <class CarrierUInt>
                    static constexpr bool prefer_round_down(CarrierUInt) noexcept {
                        return true;
                    }
                } toward_zero = {};
            }

            namespace cache {
                JKJ_INLINE_VARIABLE struct full_t {
                    using cache_policy = full_t;
                    template <class FloatFormat>
                    using cache_holder_type = cache_holder<FloatFormat>;

                    template <class FloatFormat, class ShiftAmountType, class DecimalExponentType>
                    static constexpr typename cache_holder_type<FloatFormat>::cache_entry_type
                    get_cache(DecimalExponentType k) noexcept {
#if JKJ_HAS_CONSTEXPR14
                        assert(k >= cache_holder_type<FloatFormat>::min_k &&
                               k <= cache_holder_type<FloatFormat>::max_k);
#endif
                        return cache_holder_type<FloatFormat>::cache[detail::stdr::size_t(
                            k - cache_holder_type<FloatFormat>::min_k)];
                    }
                } full = {};

                JKJ_INLINE_VARIABLE struct compact_t {
                    using cache_policy = compact_t;
                    template <class FloatFormat>
                    using cache_holder_type = compressed_cache_holder<FloatFormat>;

                    template <class FloatFormat, class ShiftAmountType, class DecimalExponentType>
                    static JKJ_CONSTEXPR20 typename cache_holder<FloatFormat>::cache_entry_type
                    get_cache(DecimalExponentType k) noexcept {
                        assert(k >= cache_holder<FloatFormat>::min_k &&
                               k <= cache_holder<FloatFormat>::max_k);

                        return cache_holder_type<FloatFormat>::template get_cache<ShiftAmountType>(k);
                    }
                } compact = {};
            }

            namespace preferred_integer_types {
                JKJ_INLINE_VARIABLE struct match_t {
                    using preferred_integer_types_policy = match_t;

                    template <class FormatTraits, detail::stdr::uint_least64_t upper_bound>
                    using remainder_type = typename FormatTraits::carrier_uint;

                    template <class FormatTraits, detail::stdr::int_least32_t lower_bound,
                              detail::stdr::uint_least32_t upper_bound>
                    using decimal_exponent_type = typename FormatTraits::exponent_int;

                    template <class FormatTraits>
                    using shift_amount_type = typename FormatTraits::exponent_int;
                } match;

                JKJ_INLINE_VARIABLE struct prefer_32_t {
                    using preferred_integer_types_policy = prefer_32_t;

                    template <class FormatTraits, detail::stdr::uint_least64_t upper_bound>
                    using remainder_type = typename detail::stdr::conditional<
                        upper_bound <=
                            detail::stdr::numeric_limits<detail::stdr::uint_least32_t>::max(),
                        detail::stdr::uint_least32_t, typename FormatTraits::carrier_uint>::type;

                    template <class FormatTraits, detail::stdr::int_least32_t lower_bound,
                              detail::stdr::uint_least32_t upper_bound>
                    using decimal_exponent_type = typename detail::stdr::conditional<
                        FormatTraits::format::exponent_bits <=
                            detail::value_bits<detail::stdr::int_least32_t>::value,
                        detail::stdr::int_least32_t, typename FormatTraits::exponent_int>::type;

                    template <class FormatTraits>
                    using shift_amount_type = detail::stdr::int_least32_t;
                } prefer_32;

                JKJ_INLINE_VARIABLE struct minimal_t {
                    using preferred_integer_types_policy = minimal_t;

                    template <class FormatTraits, detail::stdr::uint_least64_t upper_bound>
                    using remainder_type = typename detail::stdr::conditional<
                        upper_bound <= detail::stdr::numeric_limits<detail::stdr::uint_least8_t>::max(),
                        detail::stdr::uint_least8_t,
                        typename detail::stdr::conditional<
                            upper_bound <=
                                detail::stdr::numeric_limits<detail::stdr::uint_least16_t>::max(),
                            detail::stdr::uint_least16_t,
                            typename detail::stdr::conditional<
                                upper_bound <=
                                    detail::stdr::numeric_limits<detail::stdr::uint_least32_t>::max(),
                                detail::stdr::uint_least32_t,
                                typename detail::stdr::conditional<
                                    upper_bound <= detail::stdr::numeric_limits<
                                                       detail::stdr::uint_least64_t>::max(),
                                    detail::stdr::uint_least64_t,
                                    typename FormatTraits::carrier_uint>::type>::type>::type>::type;

                    template <class FormatTraits, detail::stdr::int_least32_t lower_bound,
                              detail::stdr::uint_least32_t upper_bound>
                    using decimal_exponent_type = typename detail::stdr::conditional<
                        lower_bound >=
                                detail::stdr::numeric_limits<detail::stdr::int_least8_t>::min() &&
                            upper_bound <=
                                detail::stdr::numeric_limits<detail::stdr::int_least8_t>::max(),
                        detail::stdr::int_least8_t,
                        typename detail::stdr::conditional<
                            lower_bound >=
                                    detail::stdr::numeric_limits<detail::stdr::int_least16_t>::min() &&
                                upper_bound <=
                                    detail::stdr::numeric_limits<detail::stdr::int_least16_t>::max(),
                            detail::stdr::int_least16_t,
                            typename detail::stdr::conditional<
                                lower_bound >= detail::stdr::numeric_limits<
                                                   detail::stdr::int_least32_t>::min() &&
                                    upper_bound <= detail::stdr::numeric_limits<
                                                       detail::stdr::int_least32_t>::max(),
                                detail::stdr::int_least32_t,
                                typename FormatTraits::exponent_int>::type>::type>::type;

                    template <class FormatTraits>
                    using shift_amount_type = detail::stdr::int_least8_t;
                } minimal;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        // Specializations of user-specializable templates used in the main algorithm.
        ////////////////////////////////////////////////////////////////////////////////////////

        template <class DecimalExponentType>
        struct remove_trailing_zeros_traits<policy::trailing_zero::remove_t, ieee754_binary32,
                                            detail::stdr::uint_least32_t, DecimalExponentType> {
            JKJ_FORCEINLINE static JKJ_CONSTEXPR14 void
            remove_trailing_zeros(detail::stdr::uint_least32_t& significand,
                                  DecimalExponentType& exponent) noexcept {
                // See https://github.com/jk-jeon/rtz_benchmark.
                // The idea of branchless search below is by reddit users r/pigeon768 and
                // r/TheoreticalDumbass.

                auto r = detail::bits::rotr<32>(
                    detail::stdr::uint_least32_t(significand * UINT32_C(184254097)), 4);
                auto b = r < UINT32_C(429497);
                auto s = detail::stdr::size_t(b);
                significand = b ? r : significand;

                r = detail::bits::rotr<32>(
                    detail::stdr::uint_least32_t(significand * UINT32_C(42949673)), 2);
                b = r < UINT32_C(42949673);
                s = s * 2 + b;
                significand = b ? r : significand;

                r = detail::bits::rotr<32>(
                    detail::stdr::uint_least32_t(significand * UINT32_C(1288490189)), 1);
                b = r < UINT32_C(429496730);
                s = s * 2 + b;
                significand = b ? r : significand;

                exponent += s;
            }
        };

        template <class DecimalExponentType>
        struct remove_trailing_zeros_traits<policy::trailing_zero::remove_t, ieee754_binary64,
                                            detail::stdr::uint_least64_t, DecimalExponentType> {
            JKJ_FORCEINLINE static JKJ_CONSTEXPR14 void
            remove_trailing_zeros(detail::stdr::uint_least64_t& significand,
                                  DecimalExponentType& exponent) noexcept {
                // See https://github.com/jk-jeon/rtz_benchmark.
                // The idea of branchless search below is by reddit users r/pigeon768 and
                // r/TheoreticalDumbass.

                auto r = detail::bits::rotr<64>(
                    detail::stdr::uint_least64_t(significand * UINT64_C(28999941890838049)), 8);
                auto b = r < UINT64_C(184467440738);
                auto s = detail::stdr::size_t(b);
                significand = b ? r : significand;

                r = detail::bits::rotr<64>(
                    detail::stdr::uint_least64_t(significand * UINT64_C(182622766329724561)), 4);
                b = r < UINT64_C(1844674407370956);
                s = s * 2 + b;
                significand = b ? r : significand;

                r = detail::bits::rotr<64>(
                    detail::stdr::uint_least64_t(significand * UINT64_C(10330176681277348905)), 2);
                b = r < UINT64_C(184467440737095517);
                s = s * 2 + b;
                significand = b ? r : significand;

                r = detail::bits::rotr<64>(
                    detail::stdr::uint_least64_t(significand * UINT32_C(14757395258967641293)), 1);
                b = r < UINT64_C(1844674407370955162);
                s = s * 2 + b;
                significand = b ? r : significand;

                exponent += s;
            }
        };

        template <class DecimalExponentType>
        struct remove_trailing_zeros_traits<policy::trailing_zero::remove_compact_t, ieee754_binary32,
                                            detail::stdr::uint_least32_t, DecimalExponentType> {
            JKJ_FORCEINLINE static JKJ_CONSTEXPR14 void
            remove_trailing_zeros(detail::stdr::uint_least32_t& significand,
                                  DecimalExponentType& exponent) noexcept {
                // See https://github.com/jk-jeon/rtz_benchmark.
                while (true) {
                    auto const r = detail::stdr::uint_least32_t(significand * UINT32_C(1288490189));
                    if (r < UINT32_C(429496731)) {
                        significand = detail::stdr::uint_least32_t(r >> 1);
                        exponent += 1;
                    }
                    else {
                        break;
                    }
                }
            }
        };

        template <class DecimalExponentType>
        struct remove_trailing_zeros_traits<policy::trailing_zero::remove_compact_t, ieee754_binary64,
                                            detail::stdr::uint_least64_t, DecimalExponentType> {
            JKJ_FORCEINLINE static JKJ_CONSTEXPR14 void
            remove_trailing_zeros(detail::stdr::uint_least64_t& significand,
                                  DecimalExponentType& exponent) noexcept {
                // See https://github.com/jk-jeon/rtz_benchmark.
                while (true) {
                    auto const r =
                        detail::stdr::uint_least64_t(significand * UINT64_C(5534023222112865485));
                    if (r < UINT64_C(1844674407370955163)) {
                        significand = detail::stdr::uint_least64_t(r >> 1);
                        exponent += 1;
                    }
                    else {
                        break;
                    }
                }
            }
        };

        template <class ExponentInt>
        struct multiplication_traits<
            ieee754_binary_traits<ieee754_binary32, detail::stdr::uint_least32_t, ExponentInt>,
            detail::stdr::uint_least64_t, 64>
            : public multiplication_traits_base<
                  ieee754_binary_traits<ieee754_binary32, detail::stdr::uint_least32_t>,
                  detail::stdr::uint_least64_t, 64> {
            static JKJ_CONSTEXPR20 compute_mul_result
            compute_mul(carrier_uint u, cache_entry_type const& cache) noexcept {
                auto const r = detail::wuint::umul96_upper64(u, cache);
                return {carrier_uint(r >> 32), carrier_uint(r) == 0};
            }

            template <class ShiftAmountType>
            static constexpr detail::stdr::uint_least64_t compute_delta(cache_entry_type const& cache,
                                                                        ShiftAmountType beta) noexcept {
                return detail::stdr::uint_least64_t(cache >> ShiftAmountType(cache_bits - 1 - beta));
            }

            template <class ShiftAmountType>
            static JKJ_CONSTEXPR20 compute_mul_parity_result compute_mul_parity(
                carrier_uint two_f, cache_entry_type const& cache, ShiftAmountType beta) noexcept {
                assert(beta >= 1);
                assert(beta <= 32);

                auto const r = detail::wuint::umul96_lower64(two_f, cache);
                return {((r >> ShiftAmountType(64 - beta)) & 1) != 0,
                        (UINT32_C(0xffffffff) & (r >> ShiftAmountType(32 - beta))) == 0};
            }

            template <class ShiftAmountType>
            static constexpr carrier_uint
            compute_left_endpoint_for_shorter_interval_case(cache_entry_type const& cache,
                                                            ShiftAmountType beta) noexcept {
                return carrier_uint((cache - (cache >> (significand_bits + 2))) >>
                                    ShiftAmountType(cache_bits - significand_bits - 1 - beta));
            }

            template <class ShiftAmountType>
            static constexpr carrier_uint
            compute_right_endpoint_for_shorter_interval_case(cache_entry_type const& cache,
                                                             ShiftAmountType beta) noexcept {
                return carrier_uint((cache + (cache >> (significand_bits + 1))) >>
                                    ShiftAmountType(cache_bits - significand_bits - 1 - beta));
            }

            template <class ShiftAmountType>
            static constexpr carrier_uint
            compute_round_up_for_shorter_interval_case(cache_entry_type const& cache,
                                                       ShiftAmountType beta) noexcept {
                return (carrier_uint(cache >>
                                     ShiftAmountType(cache_bits - significand_bits - 2 - beta)) +
                        1) /
                       2;
            }
        };

        template <class ExponentInt>
        struct multiplication_traits<
            ieee754_binary_traits<ieee754_binary64, detail::stdr::uint_least64_t, ExponentInt>,
            detail::wuint::uint128, 128>
            : public multiplication_traits_base<
                  ieee754_binary_traits<ieee754_binary64, detail::stdr::uint_least64_t>,
                  detail::wuint::uint128, 128> {
            static JKJ_CONSTEXPR20 compute_mul_result
            compute_mul(carrier_uint u, cache_entry_type const& cache) noexcept {
                auto const r = detail::wuint::umul192_upper128(u, cache);
                return {r.high(), r.low() == 0};
            }

            template <class ShiftAmountType>
            static constexpr detail::stdr::uint_least64_t compute_delta(cache_entry_type const& cache,
                                                                        ShiftAmountType beta) noexcept {
                return detail::stdr::uint_least64_t(cache.high() >>
                                                    ShiftAmountType(total_bits - 1 - beta));
            }

            template <class ShiftAmountType>
            static JKJ_CONSTEXPR20 compute_mul_parity_result compute_mul_parity(
                carrier_uint two_f, cache_entry_type const& cache, ShiftAmountType beta) noexcept {
                assert(beta >= 1);
                assert(beta < 64);

                auto const r = detail::wuint::umul192_lower128(two_f, cache);
                return {((r.high() >> ShiftAmountType(64 - beta)) & 1) != 0,
                        (((r.high() << beta) & UINT64_C(0xffffffffffffffff)) |
                         (r.low() >> ShiftAmountType(64 - beta))) == 0};
            }

            template <class ShiftAmountType>
            static constexpr carrier_uint
            compute_left_endpoint_for_shorter_interval_case(cache_entry_type const& cache,
                                                            ShiftAmountType beta) noexcept {
                return (cache.high() - (cache.high() >> (significand_bits + 2))) >>
                       ShiftAmountType(total_bits - significand_bits - 1 - beta);
            }

            template <class ShiftAmountType>
            static constexpr carrier_uint
            compute_right_endpoint_for_shorter_interval_case(cache_entry_type const& cache,
                                                             ShiftAmountType beta) noexcept {
                return (cache.high() + (cache.high() >> (significand_bits + 1))) >>
                       ShiftAmountType(total_bits - significand_bits - 1 - beta);
            }

            template <class ShiftAmountType>
            static constexpr carrier_uint
            compute_round_up_for_shorter_interval_case(cache_entry_type const& cache,
                                                       ShiftAmountType beta) noexcept {
                return ((cache.high() >> ShiftAmountType(total_bits - significand_bits - 2 - beta)) +
                        1) /
                       2;
            }
        };

        namespace detail {
            ////////////////////////////////////////////////////////////////////////////////////////
            // The main algorithm.
            ////////////////////////////////////////////////////////////////////////////////////////

            template <class FormatTraits>
            struct impl : private FormatTraits::format {
                using format = typename FormatTraits::format;
                using carrier_uint = typename FormatTraits::carrier_uint;
                static constexpr int carrier_bits = FormatTraits::carrier_bits;
                using exponent_int = typename FormatTraits::exponent_int;

                using format::significand_bits;
                using format::min_exponent;
                using format::max_exponent;
                using format::exponent_bias;

                static constexpr int kappa =
                    log::floor_log10_pow2(carrier_bits - significand_bits - 2) - 1;
                static_assert(kappa >= 1, "");
                static_assert(carrier_bits >= significand_bits + 2 + log::floor_log2_pow10(kappa + 1),
                              "");

                static constexpr int min(int x, int y) noexcept { return x < y ? x : y; }
                static constexpr int max(int x, int y) noexcept { return x > y ? x : y; }

                static constexpr int min_k =
                    min(-log::floor_log10_pow2_minus_log10_4_over_3(max_exponent - significand_bits),
                        -log::floor_log10_pow2(max_exponent - significand_bits) + kappa);

                // We do invoke shorter_interval_case for exponent == min_exponent case,
                // so we should not add 1 here.
                static constexpr int max_k =
                    max(-log::floor_log10_pow2_minus_log10_4_over_3(min_exponent -
                                                                    significand_bits /*+ 1*/),
                        -log::floor_log10_pow2(min_exponent - significand_bits) + kappa);

                static constexpr int case_shorter_interval_left_endpoint_lower_threshold = 2;
                static constexpr int case_shorter_interval_left_endpoint_upper_threshold =
                    2 +
                    log::floor_log2(
                        compute_power<
                            count_factors<5>((carrier_uint(1) << (significand_bits + 2)) - 1) + 1>(10) /
                        3);

                static constexpr int case_shorter_interval_right_endpoint_lower_threshold = 0;
                static constexpr int case_shorter_interval_right_endpoint_upper_threshold =
                    2 +
                    log::floor_log2(
                        compute_power<
                            count_factors<5>((carrier_uint(1) << (significand_bits + 1)) + 1) + 1>(10) /
                        3);

                static constexpr int shorter_interval_tie_lower_threshold =
                    -log::floor_log5_pow2_minus_log5_3(significand_bits + 4) - 2 - significand_bits;
                static constexpr int shorter_interval_tie_upper_threshold =
                    -log::floor_log5_pow2(significand_bits + 2) - 2 - significand_bits;

                template <class PreferredIntegerTypesPolicy>
                using remainder_type = typename PreferredIntegerTypesPolicy::template remainder_type<
                    FormatTraits, compute_power<kappa + 1>(detail::stdr::uint_least64_t(10))>;

                template <class PreferredIntegerTypesPolicy>
                using decimal_exponent_type =
                    typename PreferredIntegerTypesPolicy::template decimal_exponent_type<
                        FormatTraits, detail::stdr::int_least32_t(min(-max_k, min_k)),
                        detail::stdr::int_least32_t(max(max_k, -min_k + kappa + 1))>;

                template <class SignPolicy, class TrailingZeroPolicy, class PreferredIntegerTypesPolicy>
                using return_type =
                    decimal_fp<carrier_uint, decimal_exponent_type<PreferredIntegerTypesPolicy>,
                               SignPolicy::return_has_sign, TrailingZeroPolicy::report_trailing_zeros>;

                //// The main algorithm assumes the input is a normal/subnormal finite number.

                template <class SignPolicy, class TrailingZeroPolicy, class IntervalTypeProvider,
                          class BinaryToDecimalRoundingPolicy, class CachePolicy,
                          class PreferredIntegerTypesPolicy>
                JKJ_SAFEBUFFERS static JKJ_CONSTEXPR20
                    return_type<SignPolicy, TrailingZeroPolicy, PreferredIntegerTypesPolicy>
                    compute_nearest(signed_significand_bits<FormatTraits> s,
                                    exponent_int exponent_bits) noexcept {
                    using cache_holder_type = typename CachePolicy::template cache_holder_type<format>;
                    static_assert(
                        min_k >= cache_holder_type::min_k && max_k <= cache_holder_type::max_k, "");

                    using remainder_type_ = remainder_type<PreferredIntegerTypesPolicy>;
                    using decimal_exponent_type_ = decimal_exponent_type<PreferredIntegerTypesPolicy>;
                    using shift_amount_type =
                        typename PreferredIntegerTypesPolicy::template shift_amount_type<FormatTraits>;

                    using multiplication_traits_ =
                        multiplication_traits<FormatTraits,
                                              typename cache_holder_type::cache_entry_type,
                                              cache_holder_type::cache_bits>;

                    auto two_fc = s.remove_sign_bit_and_shift();
                    auto binary_exponent = exponent_bits;

                    // Is the input a normal number?
                    if (binary_exponent != 0) {
                        binary_exponent += format::exponent_bias - format::significand_bits;

                        // Shorter interval case; proceed like Schubfach.
                        // One might think this condition is wrong, since when exponent_bits ==
                        // 1 and two_fc == 0, the interval is actually regular. However, it
                        // turns out that this seemingly wrong condition is actually fine,
                        // because the end result is anyway the same.
                        //
                        // [binary32]
                        // (fc-1/2) * 2^e = 1.175'494'28... * 10^-38
                        // (fc-1/4) * 2^e = 1.175'494'31... * 10^-38
                        //    fc    * 2^e = 1.175'494'35... * 10^-38
                        // (fc+1/2) * 2^e = 1.175'494'42... * 10^-38
                        //
                        // Hence, shorter_interval_case will return 1.175'494'4 * 10^-38.
                        // 1.175'494'3 * 10^-38 is also a correct shortest representation that
                        // will be rejected if we assume shorter interval, but 1.175'494'4 *
                        // 10^-38 is closer to the true value so it doesn't matter.
                        //
                        // [binary64]
                        // (fc-1/2) * 2^e = 2.225'073'858'507'201'13... * 10^-308
                        // (fc-1/4) * 2^e = 2.225'073'858'507'201'25... * 10^-308
                        //    fc    * 2^e = 2.225'073'858'507'201'38... * 10^-308
                        // (fc+1/2) * 2^e = 2.225'073'858'507'201'63... * 10^-308
                        //
                        // Hence, shorter_interval_case will return 2.225'073'858'507'201'4 *
                        // 10^-308. This is indeed of the shortest length, and it is the unique
                        // one closest to the true value among valid representations of the same
                        // length.
                        static_assert(stdr::is_same<format, ieee754_binary32>::value ||
                                          stdr::is_same<format, ieee754_binary64>::value,
                                      "");

                        // Shorter interval case.
                        if (two_fc == 0) {
                            auto interval_type = IntervalTypeProvider::shorter_interval(s);

                            // Compute k and beta.
                            auto const minus_k = log::floor_log10_pow2_minus_log10_4_over_3<
                                min_exponent - format::significand_bits,
                                max_exponent - format::significand_bits, decimal_exponent_type_>(
                                binary_exponent);
                            auto const beta = shift_amount_type(
                                binary_exponent +
                                log::floor_log2_pow10<min_k, max_k>(decimal_exponent_type_(-minus_k)));

                            // Compute xi and zi.
                            auto const cache =
                                CachePolicy::template get_cache<format, shift_amount_type>(
                                    decimal_exponent_type_(-minus_k));

                            auto xi =
                                multiplication_traits_::compute_left_endpoint_for_shorter_interval_case(
                                    cache, beta);
                            auto zi = multiplication_traits_::
                                compute_right_endpoint_for_shorter_interval_case(cache, beta);

                            // If we don't accept the right endpoint and
                            // if the right endpoint is an integer, decrease it.
                            if (!interval_type.include_right_endpoint() &&
                                is_right_endpoint_integer_shorter_interval(binary_exponent)) {
                                --zi;
                            }
                            // If we don't accept the left endpoint or
                            // if the left endpoint is not an integer, increase it.
                            if (!interval_type.include_left_endpoint() ||
                                !is_left_endpoint_integer_shorter_interval(binary_exponent)) {
                                ++xi;
                            }

                            // Try bigger divisor.
                            // zi is at most floor((f_c + 1/2) * 2^e * 10^k0).
                            // Substituting f_c = 2^p and k0 = -floor(log10(3 * 2^(e-2))), we get
                            // zi <= floor((2^(p+1) + 1) * 20/3) <= ceil((2^(p+1) + 1)/3) * 20.
                            // This computation does not overflow for any of the formats I care about.
                            carrier_uint decimal_significand = div::divide_by_pow10<
                                1, carrier_uint,
                                carrier_uint(
                                    ((((carrier_uint(1) << (significand_bits + 1)) + 1) / 3) + 1) *
                                    20)>(zi);

                            // If succeed, remove trailing zeros if necessary and return.
                            if (decimal_significand * 10 >= xi) {
                                return SignPolicy::handle_sign(
                                    s, TrailingZeroPolicy::template on_trailing_zeros<format>(
                                           decimal_significand, decimal_exponent_type_(minus_k + 1)));
                            }

                            // Otherwise, compute the round-up of y.
                            decimal_significand =
                                multiplication_traits_::compute_round_up_for_shorter_interval_case(
                                    cache, beta);

                            // When tie occurs, choose one of them according to the rule.
                            if (BinaryToDecimalRoundingPolicy::prefer_round_down(decimal_significand) &&
                                binary_exponent >= shorter_interval_tie_lower_threshold &&
                                binary_exponent <= shorter_interval_tie_upper_threshold) {
                                --decimal_significand;
                            }
                            else if (decimal_significand < xi) {
                                ++decimal_significand;
                            }
                            return SignPolicy::handle_sign(
                                s, TrailingZeroPolicy::template no_trailing_zeros<format>(
                                       decimal_significand, decimal_exponent_type_(minus_k)));
                        }

                        // Normal interval case.
                        two_fc |= (carrier_uint(1) << (format::significand_bits + 1));
                    }
                    // Is the input a subnormal number?
                    else {
                        // Normal interval case.
                        binary_exponent = format::min_exponent - format::significand_bits;
                    }

                    //////////////////////////////////////////////////////////////////////
                    // Step 1: Schubfach multiplier calculation.
                    //////////////////////////////////////////////////////////////////////

                    auto interval_type = IntervalTypeProvider::normal_interval(s);

                    // Compute k and beta.
                    auto const minus_k = decimal_exponent_type_(
                        log::floor_log10_pow2<min_exponent - format::significand_bits,
                                              max_exponent - format::significand_bits,
                                              decimal_exponent_type_>(binary_exponent) -
                        kappa);
                    auto const cache = CachePolicy::template get_cache<format, shift_amount_type>(
                        decimal_exponent_type_(-minus_k));
                    auto const beta =
                        shift_amount_type(binary_exponent + log::floor_log2_pow10<min_k, max_k>(
                                                                decimal_exponent_type_(-minus_k)));

                    // Compute zi and deltai.
                    // 10^kappa <= deltai < 10^(kappa + 1)
                    auto const deltai = static_cast<remainder_type_>(
                        multiplication_traits_::compute_delta(cache, beta));
                    // For the case of binary32, the result of integer check is not correct for
                    // 29711844 * 2^-82
                    // = 6.1442653300000000008655037797566933477355632930994033813476... * 10^-18
                    // and 29711844 * 2^-81
                    // = 1.2288530660000000001731007559513386695471126586198806762695... * 10^-17,
                    // and they are the unique counterexamples. However, since 29711844 is even,
                    // this does not cause any problem for the endpoints calculations; it can only
                    // cause a problem when we need to perform integer check for the center.
                    // Fortunately, with these inputs, that branch is never executed, so we are
                    // fine.
                    auto const z_result =
                        multiplication_traits_::compute_mul(carrier_uint((two_fc | 1) << beta), cache);


                    //////////////////////////////////////////////////////////////////////
                    // Step 2: Try larger divisor; remove trailing zeros if necessary.
                    //////////////////////////////////////////////////////////////////////

                    constexpr auto big_divisor = compute_power<kappa + 1>(remainder_type_(10));
                    constexpr auto small_divisor = compute_power<kappa>(remainder_type_(10));

                    // Using an upper bound on zi, we might be able to optimize the division
                    // better than the compiler; we are computing zi / big_divisor here.
                    carrier_uint decimal_significand = div::divide_by_pow10<
                        kappa + 1, carrier_uint,
                        carrier_uint((carrier_uint(1) << (significand_bits + 1)) * big_divisor - 1)>(
                        z_result.integer_part);
                    auto r = remainder_type_(z_result.integer_part - big_divisor * decimal_significand);

                    do {
                        if (r < deltai) {
                            // Exclude the right endpoint if necessary.
                            if ((r | remainder_type_(!z_result.is_integer) |
                                 remainder_type_(interval_type.include_right_endpoint())) == 0) {
                                JKJ_IF_CONSTEXPR(
                                    BinaryToDecimalRoundingPolicy::tag ==
                                    policy::binary_to_decimal_rounding::tag_t::do_not_care) {
                                    decimal_significand *= 10;
                                    --decimal_significand;
                                    return SignPolicy::handle_sign(
                                        s, TrailingZeroPolicy::template no_trailing_zeros<format>(
                                               decimal_significand,
                                               decimal_exponent_type_(minus_k + kappa)));
                                }
                                else {
                                    --decimal_significand;
                                    r = big_divisor;
                                    break;
                                }
                            }
                        }
                        else if (r > deltai) {
                            break;
                        }
                        else {
                            // r == deltai; compare fractional parts.
                            auto const x_result = multiplication_traits_::compute_mul_parity(
                                carrier_uint(two_fc - 1), cache, beta);

                            if (!(x_result.parity |
                                  (x_result.is_integer & interval_type.include_left_endpoint()))) {
                                break;
                            }
                        }

                        // We may need to remove trailing zeros.
                        return SignPolicy::handle_sign(
                            s, TrailingZeroPolicy::template on_trailing_zeros<format>(
                                   decimal_significand, decimal_exponent_type_(minus_k + kappa + 1)));
                    } while (false);


                    //////////////////////////////////////////////////////////////////////
                    // Step 3: Find the significand with the smaller divisor.
                    //////////////////////////////////////////////////////////////////////

                    decimal_significand *= 10;

                    JKJ_IF_CONSTEXPR(BinaryToDecimalRoundingPolicy::tag ==
                                     policy::binary_to_decimal_rounding::tag_t::do_not_care) {
                        // Normally, we want to compute
                        // significand += r / small_divisor
                        // and return, but we need to take care of the case that the resulting
                        // value is exactly the right endpoint, while that is not included in the
                        // interval.
                        if (!interval_type.include_right_endpoint()) {
                            // Is r divisible by 10^kappa?
                            if (div::check_divisibility_and_divide_by_pow10<kappa>(r) &&
                                z_result.is_integer) {
                                // This should be in the interval.
                                decimal_significand += r - 1;
                            }
                            else {
                                decimal_significand += r;
                            }
                        }
                        else {
                            decimal_significand += div::small_division_by_pow10<kappa>(r);
                        }
                    }
                    else {
                        // delta is equal to 10^(kappa + elog10(2) - floor(elog10(2))), so dist cannot
                        // be larger than r.
                        auto dist = remainder_type_(r - (deltai / 2) + (small_divisor / 2));
                        bool const approx_y_parity = ((dist ^ (small_divisor / 2)) & 1) != 0;

                        // Is dist divisible by 10^kappa?
                        bool const divisible_by_small_divisor =
                            div::check_divisibility_and_divide_by_pow10<kappa>(dist);

                        // Add dist / 10^kappa to the significand.
                        decimal_significand += dist;

                        if (divisible_by_small_divisor) {
                            // Check z^(f) >= epsilon^(f).
                            // We have either yi == zi - epsiloni or yi == (zi - epsiloni) - 1,
                            // where yi == zi - epsiloni if and only if z^(f) >= epsilon^(f).
                            // Since there are only 2 possibilities, we only need to care about the
                            // parity. Also, zi and r should have the same parity since the divisor
                            // is an even number.
                            auto const y_result =
                                multiplication_traits_::compute_mul_parity(two_fc, cache, beta);
                            if (y_result.parity != approx_y_parity) {
                                --decimal_significand;
                            }
                            else {
                                // If z^(f) >= epsilon^(f), we might have a tie
                                // when z^(f) == epsilon^(f), or equivalently, when y is an integer.
                                // For tie-to-up case, we can just choose the upper one.
                                if (BinaryToDecimalRoundingPolicy::prefer_round_down(
                                        decimal_significand) &
                                    y_result.is_integer) {
                                    --decimal_significand;
                                }
                            }
                        }
                    }
                    return SignPolicy::handle_sign(
                        s, TrailingZeroPolicy::template no_trailing_zeros<format>(
                               decimal_significand, decimal_exponent_type_(minus_k + kappa)));
                }

                template <class SignPolicy, class TrailingZeroPolicy, class CachePolicy,
                          class PreferredIntegerTypesPolicy>
                JKJ_FORCEINLINE JKJ_SAFEBUFFERS static JKJ_CONSTEXPR20
                    return_type<SignPolicy, TrailingZeroPolicy, PreferredIntegerTypesPolicy>
                    compute_left_closed_directed(signed_significand_bits<FormatTraits> s,
                                                 exponent_int exponent_bits) noexcept {
                    using cache_holder_type = typename CachePolicy::template cache_holder_type<format>;
                    static_assert(
                        min_k >= cache_holder_type::min_k && max_k <= cache_holder_type::max_k, "");

                    using remainder_type_ = remainder_type<PreferredIntegerTypesPolicy>;
                    using decimal_exponent_type_ = decimal_exponent_type<PreferredIntegerTypesPolicy>;
                    using shift_amount_type =
                        typename PreferredIntegerTypesPolicy::template shift_amount_type<FormatTraits>;

                    using multiplication_traits_ =
                        multiplication_traits<FormatTraits,
                                              typename cache_holder_type::cache_entry_type,
                                              cache_holder_type::cache_bits>;

                    auto two_fc = s.remove_sign_bit_and_shift();
                    auto binary_exponent = exponent_bits;

                    // Is the input a normal number?
                    if (binary_exponent != 0) {
                        binary_exponent += format::exponent_bias - format::significand_bits;
                        two_fc |= (carrier_uint(1) << (format::significand_bits + 1));
                    }
                    // Is the input a subnormal number?
                    else {
                        binary_exponent = format::min_exponent - format::significand_bits;
                    }

                    //////////////////////////////////////////////////////////////////////
                    // Step 1: Schubfach multiplier calculation.
                    //////////////////////////////////////////////////////////////////////

                    // Compute k and beta.
                    auto const minus_k = decimal_exponent_type_(
                        log::floor_log10_pow2<format::min_exponent - format::significand_bits,
                                              format::max_exponent - format::significand_bits,
                                              decimal_exponent_type_>(binary_exponent) -
                        kappa);
                    auto const cache = CachePolicy::template get_cache<format, shift_amount_type>(
                        decimal_exponent_type_(-minus_k));
                    auto const beta =
                        shift_amount_type(binary_exponent + log::floor_log2_pow10<min_k, max_k>(
                                                                decimal_exponent_type_(-minus_k)));

                    // Compute xi and deltai.
                    // 10^kappa <= deltai < 10^(kappa + 1)
                    auto const deltai = static_cast<remainder_type_>(
                        multiplication_traits_::compute_delta(cache, beta));
                    auto x_result =
                        multiplication_traits_::compute_mul(carrier_uint(two_fc << beta), cache);

                    // Deal with the unique exceptional cases
                    // 29711844 * 2^-82
                    // = 6.1442653300000000008655037797566933477355632930994033813476... * 10^-18
                    // and 29711844 * 2^-81
                    // = 1.2288530660000000001731007559513386695471126586198806762695... * 10^-17
                    // for binary32.
                    JKJ_IF_CONSTEXPR(stdr::is_same<format, ieee754_binary32>::value) {
                        if (binary_exponent <= -80) {
                            x_result.is_integer = false;
                        }
                    }

                    if (!x_result.is_integer) {
                        ++x_result.integer_part;
                    }

                    //////////////////////////////////////////////////////////////////////
                    // Step 2: Try larger divisor; remove trailing zeros if necessary.
                    //////////////////////////////////////////////////////////////////////

                    constexpr auto big_divisor = compute_power<kappa + 1>(remainder_type_(10));

                    // Using an upper bound on xi, we might be able to optimize the division
                    // better than the compiler; we are computing xi / big_divisor here.
                    carrier_uint decimal_significand = div::divide_by_pow10<
                        kappa + 1, carrier_uint,
                        carrier_uint((carrier_uint(1) << (significand_bits + 1)) * big_divisor - 1)>(
                        x_result.integer_part);
                    auto r = remainder_type_(x_result.integer_part - big_divisor * decimal_significand);

                    if (r != 0) {
                        ++decimal_significand;
                        r = remainder_type_(big_divisor - r);
                    }

                    do {
                        if (r > deltai) {
                            break;
                        }
                        else if (r == deltai) {
                            // Compare the fractional parts.
                            // This branch is never taken for the exceptional cases
                            // 2f_c = 29711482, e = -81
                            // (6.1442649164096937243516663440523473127541365101933479309082... *
                            // 10^-18) and 2f_c = 29711482, e = -80
                            // (1.2288529832819387448703332688104694625508273020386695861816... *
                            // 10^-17).
                            // For the case of compressed cache for binary32, there is another
                            // exceptional case 2f_c = 33554430, e = -10 (16383.9990234375). In this
                            // case, the recovered cache is two large to make compute_mul_parity
                            // mistakenly conclude that z is not an integer, but actually z = 16384 is
                            // an integer.
                            JKJ_IF_CONSTEXPR(
                                stdr::is_same<cache_holder_type,
                                              compressed_cache_holder<ieee754_binary32>>::value) {
                                if (two_fc == 33554430 && binary_exponent == -10) {
                                    break;
                                }
                            }
                            auto const z_result = multiplication_traits_::compute_mul_parity(
                                carrier_uint(two_fc + 2), cache, beta);
                            if (z_result.parity || z_result.is_integer) {
                                break;
                            }
                        }

                        // The ceiling is inside, so we are done.
                        return SignPolicy::handle_sign(
                            s, TrailingZeroPolicy::template on_trailing_zeros<format>(
                                   decimal_significand, decimal_exponent_type_(minus_k + kappa + 1)));
                    } while (false);


                    //////////////////////////////////////////////////////////////////////
                    // Step 3: Find the significand with the smaller divisor.
                    //////////////////////////////////////////////////////////////////////

                    decimal_significand *= 10;
                    decimal_significand -= div::small_division_by_pow10<kappa>(r);
                    return SignPolicy::handle_sign(
                        s, TrailingZeroPolicy::template no_trailing_zeros<format>(
                               decimal_significand, decimal_exponent_type_(minus_k + kappa)));
                }

                template <class SignPolicy, class TrailingZeroPolicy, class CachePolicy,
                          class PreferredIntegerTypesPolicy>
                JKJ_FORCEINLINE JKJ_SAFEBUFFERS static JKJ_CONSTEXPR20
                    return_type<SignPolicy, TrailingZeroPolicy, PreferredIntegerTypesPolicy>
                    compute_right_closed_directed(signed_significand_bits<FormatTraits> s,
                                                  exponent_int exponent_bits) noexcept {
                    using cache_holder_type = typename CachePolicy::template cache_holder_type<format>;
                    static_assert(
                        min_k >= cache_holder_type::min_k && max_k <= cache_holder_type::max_k, "");

                    using remainder_type_ = remainder_type<PreferredIntegerTypesPolicy>;
                    using decimal_exponent_type_ = decimal_exponent_type<PreferredIntegerTypesPolicy>;
                    using shift_amount_type =
                        typename PreferredIntegerTypesPolicy::template shift_amount_type<FormatTraits>;

                    using multiplication_traits_ =
                        multiplication_traits<FormatTraits,
                                              typename cache_holder_type::cache_entry_type,
                                              cache_holder_type::cache_bits>;

                    auto two_fc = s.remove_sign_bit_and_shift();
                    auto binary_exponent = exponent_bits;
                    bool shorter_interval = false;

                    // Is the input a normal number?
                    if (binary_exponent != 0) {
                        if (two_fc == 0 && binary_exponent != 1) {
                            shorter_interval = true;
                        }
                        binary_exponent += format::exponent_bias - format::significand_bits;
                        two_fc |= (carrier_uint(1) << (format::significand_bits + 1));
                    }
                    // Is the input a subnormal number?
                    else {
                        binary_exponent = format::min_exponent - format::significand_bits;
                    }

                    //////////////////////////////////////////////////////////////////////
                    // Step 1: Schubfach multiplier calculation.
                    //////////////////////////////////////////////////////////////////////

                    // Compute k and beta.
                    auto const minus_k = decimal_exponent_type_(
                        log::floor_log10_pow2<format::min_exponent - format::significand_bits,
                                              format::max_exponent - format::significand_bits,
                                              decimal_exponent_type_>(
                            exponent_int(binary_exponent - (shorter_interval ? 1 : 0))) -
                        kappa);
                    auto const cache = CachePolicy::template get_cache<format, shift_amount_type>(
                        decimal_exponent_type_(-minus_k));
                    auto const beta = shift_amount_type(
                        binary_exponent + log::floor_log2_pow10(decimal_exponent_type_(-minus_k)));

                    // Compute zi and deltai.
                    // 10^kappa <= deltai < 10^(kappa + 1)
                    auto const deltai =
                        static_cast<remainder_type_>(multiplication_traits_::compute_delta(
                            cache, shift_amount_type(beta - (shorter_interval ? 1 : 0))));
                    carrier_uint const zi =
                        multiplication_traits_::compute_mul(carrier_uint(two_fc << beta), cache)
                            .integer_part;


                    //////////////////////////////////////////////////////////////////////
                    // Step 2: Try larger divisor; remove trailing zeros if necessary.
                    //////////////////////////////////////////////////////////////////////

                    constexpr auto big_divisor = compute_power<kappa + 1>(remainder_type_(10));

                    // Using an upper bound on zi, we might be able to optimize the division better
                    // than the compiler; we are computing zi / big_divisor here.
                    carrier_uint decimal_significand = div::divide_by_pow10<
                        kappa + 1, carrier_uint,
                        carrier_uint((carrier_uint(1) << (significand_bits + 1)) * big_divisor - 1)>(
                        zi);
                    auto const r = remainder_type_(zi - big_divisor * decimal_significand);

                    do {
                        if (r > deltai) {
                            break;
                        }
                        else if (r == deltai) {
                            // Compare the fractional parts.
                            if (!multiplication_traits_::compute_mul_parity(
                                     carrier_uint(two_fc - (shorter_interval ? 1 : 2)), cache, beta)
                                     .parity) {
                                break;
                            }
                        }

                        // The floor is inside, so we are done.
                        return SignPolicy::handle_sign(
                            s, TrailingZeroPolicy::template on_trailing_zeros<format>(
                                   decimal_significand, decimal_exponent_type_(minus_k + kappa + 1)));
                    } while (false);


                    //////////////////////////////////////////////////////////////////////
                    // Step 3: Find the significand with the small divisor.
                    //////////////////////////////////////////////////////////////////////

                    decimal_significand *= 10;
                    decimal_significand += div::small_division_by_pow10<kappa>(r);
                    return SignPolicy::handle_sign(
                        s, TrailingZeroPolicy::template no_trailing_zeros<format>(
                               decimal_significand, decimal_exponent_type_(minus_k + kappa)));
                }

                static constexpr bool
                is_right_endpoint_integer_shorter_interval(exponent_int binary_exponent) noexcept {
                    return binary_exponent >= case_shorter_interval_right_endpoint_lower_threshold &&
                           binary_exponent <= case_shorter_interval_right_endpoint_upper_threshold;
                }

                static constexpr bool
                is_left_endpoint_integer_shorter_interval(exponent_int binary_exponent) noexcept {
                    return binary_exponent >= case_shorter_interval_left_endpoint_lower_threshold &&
                           binary_exponent <= case_shorter_interval_left_endpoint_upper_threshold;
                }
            };


            ////////////////////////////////////////////////////////////////////////////////////////
            // Policy holder.
            ////////////////////////////////////////////////////////////////////////////////////////

            // The library will specify a list of accepted kinds of policies and their defaults,
            // and the user will pass a list of policies parameters. The policy parameters are
            // supposed to be stateless and only convey information through their types.
            // The aim of the helper classes/functions given below is to do the following:
            //   1. Check if the policy parameters given by the user are all valid; that means,
            //      each of them should be at least of one of the kinds specified by the library.
            //      If that's not the case, then the compilation fails.
            //   2. Check if multiple policy parameters for the same kind is specified by the
            //      user. If that's the case, then the compilation fails.
            //   3. Build a class deriving from all policies the user have given, and also from
            //      the default policies if the user did not specify one for some kinds.
            // The library considers a certain policy parameter to belong to a specific kind if and only
            // if the parameter's type has a member type with a specific name; for example, it belongs
            // to "sign policy" kind if there is a member type sign_policy.

            // For a given kind, find a policy belonging to that kind.
            // Check if there are more than one such policies.
            enum class policy_found_info { not_found, unique, repeated };
            template <class Policy, policy_found_info info>
            struct found_policy_pair {
                // Either the policy parameter type given by the user, or the default policy.
                using policy = Policy;
                static constexpr auto found_info = info;
            };

            template <class KindDetector, class DefaultPolicy>
            struct detector_default_pair {
                using kind_detector = KindDetector;

                // Iterate through all given policy parameter types and see if there is a policy
                // parameter type belonging to the policy kind specified by KindDetector.
                // 1. If there is none, get_found_policy_pair returns
                //    found_policy_pair<DefaultPolicy, policy_found_info::not_found>.
                // 2. If there is only one parameter type belonging to the specified kind, then
                //    get_found_policy_pair returns
                //    found_policy_pair<Policy, policy_found_info::unique>
                //    where Policy is the unique parameter type belonging to the specified kind.
                // 3. If there are multiple parameter types belonging to the specified kind, then
                //    get_found_policy_pair returns
                //    found_policy_pair<FirstPolicy, policy_found_info::repeated>
                //    where FirstPolicy is the first parameter type belonging to the specified kind.
                //    The compilation must fail if this happens.
                // This is done by first setting FoundPolicyInfo below to
                // found_policy_pair<DefaultPolicy, policy_found_info::not_found>, and then iterate
                // over Policies, replacing FoundPolicyInfo by the appropriate one if a parameter
                // type belonging to the specified kind is found.

                template <class FoundPolicyInfo, class... Policies>
                struct get_found_policy_pair_impl;

                template <class FoundPolicyInfo>
                struct get_found_policy_pair_impl<FoundPolicyInfo> {
                    using type = FoundPolicyInfo;
                };

                template <class FoundPolicyInfo, class FirstPolicy, class... RemainingPolicies>
                struct get_found_policy_pair_impl<FoundPolicyInfo, FirstPolicy, RemainingPolicies...> {
                    using type = typename stdr::conditional<
                        KindDetector{}(dummy<FirstPolicy>{}),
                        typename stdr::conditional<
                            FoundPolicyInfo::found_info == policy_found_info::not_found,
                            typename get_found_policy_pair_impl<
                                found_policy_pair<FirstPolicy, policy_found_info::unique>,
                                RemainingPolicies...>::type,
                            typename get_found_policy_pair_impl<
                                found_policy_pair<FirstPolicy, policy_found_info::repeated>,
                                RemainingPolicies...>::type>::type,
                        typename get_found_policy_pair_impl<FoundPolicyInfo,
                                                            RemainingPolicies...>::type>::type;
                };

                template <class... Policies>
                using get_found_policy_pair = typename get_found_policy_pair_impl<
                    found_policy_pair<DefaultPolicy, policy_found_info::not_found>, Policies...>::type;
            };

            // Simple typelist of detector_default_pair's.
            template <class... DetectorDefaultPairs>
            struct detector_default_pair_list {};

            // Check if a given policy belongs to one of the kinds specified by the library.
            template <class Policy>
            constexpr bool check_policy_validity(dummy<Policy>, detector_default_pair_list<>) noexcept {
                return false;
            }
            template <class Policy, class FirstDetectorDefaultPair,
                      class... RemainingDetectorDefaultPairs>
            constexpr bool check_policy_validity(
                dummy<Policy>, detector_default_pair_list<FirstDetectorDefaultPair,
                                                          RemainingDetectorDefaultPairs...>) noexcept {
                return typename FirstDetectorDefaultPair::kind_detector{}(dummy<Policy>{}) ||
                       check_policy_validity(
                           dummy<Policy>{},
                           detector_default_pair_list<RemainingDetectorDefaultPairs...>{});
            }

            // Check if all of policies belong to some of the kinds specified by the library.
            template <class DetectorDefaultPairList>
            constexpr bool check_policy_list_validity(DetectorDefaultPairList) noexcept {
                return true;
            }
            template <class DetectorDefaultPairList, class FirstPolicy, class... RemainingPolicies>
            constexpr bool check_policy_list_validity(DetectorDefaultPairList,
                                                      dummy<FirstPolicy> first_policy,
                                                      dummy<RemainingPolicies>... remaining_policies) {
                return check_policy_validity(first_policy, DetectorDefaultPairList{}) &&
                       check_policy_list_validity(DetectorDefaultPairList{}, remaining_policies...);
            }

            // Actual policy holder class deriving from all specified policy types.
            template <class... Policies>
            struct policy_holder : Policies... {};

            // Iterate through the library-specified list of base-default pairs, i.e., the list of
            // policy kinds and their defaults. For each base-default pair, call
            // base_default_pair::get_found_policy_pair on the list of user-specified list of
            // policies to get found_policy_pair, and build the list of them.

            template <bool repeated_, class... FoundPolicyPairs>
            struct found_policy_pair_list {
                // This will be set to be true if and only if there exists at least one
                // found_policy_pair inside FoundPolicyPairs with
                // found_info == policy_found_info::repeated, in which case the compilation must
                // fail.
                static constexpr bool repeated = repeated_;
            };

            // Iterate through DetectorDefaultPairList and augment FoundPolicyPairList by one at each
            // iteration.
            template <class DetectorDefaultPairList, class FoundPolicyPairList, class... Policies>
            struct make_policy_pair_list_impl;

            // When there is no more detector-default pair to iterate, then the current
            // found_policy_pair_list is the final result.
            template <bool repeated, class... FoundPolicyPairs, class... Policies>
            struct make_policy_pair_list_impl<detector_default_pair_list<>,
                                              found_policy_pair_list<repeated, FoundPolicyPairs...>,
                                              Policies...> {
                using type = found_policy_pair_list<repeated, FoundPolicyPairs...>;
            };

            // For the first detector-default pair in the remaining list, call
            // detector_default_pair::get_found_policy_pair on Policies and add the returned
            // found_policy_pair into the current list of found_policy_pair's, and move to the next
            // detector-default pair.
            template <class FirstDetectorDefaultPair, class... RemainingDetectorDefaultPairs,
                      bool repeated, class... FoundPolicyPairs, class... Policies>
            struct make_policy_pair_list_impl<
                detector_default_pair_list<FirstDetectorDefaultPair, RemainingDetectorDefaultPairs...>,
                found_policy_pair_list<repeated, FoundPolicyPairs...>, Policies...> {
                using new_found_policy_pair =
                    typename FirstDetectorDefaultPair::template get_found_policy_pair<Policies...>;

                using type = typename make_policy_pair_list_impl<
                    detector_default_pair_list<RemainingDetectorDefaultPairs...>,
                    found_policy_pair_list<(repeated || new_found_policy_pair::found_info ==
                                                            policy_found_info::repeated),
                                           new_found_policy_pair, FoundPolicyPairs...>,
                    Policies...>::type;
            };

            template <class DetectorDefaultPairList, class... Policies>
            using policy_pair_list =
                typename make_policy_pair_list_impl<DetectorDefaultPairList,
                                                    found_policy_pair_list<false>, Policies...>::type;

            // Unpack FoundPolicyPairList into found_policy_pair's and build the policy_holder type
            // from the corresponding typelist of found_policy_pair::policy's.
            template <class FoundPolicyPairList, class... RawPolicies>
            struct convert_to_policy_holder_impl;

            template <bool repeated, class... RawPolicies>
            struct convert_to_policy_holder_impl<found_policy_pair_list<repeated>, RawPolicies...> {
                using type = policy_holder<RawPolicies...>;
            };

            template <bool repeated, class FirstFoundPolicyPair, class... RemainingFoundPolicyPairs,
                      class... RawPolicies>
            struct convert_to_policy_holder_impl<
                found_policy_pair_list<repeated, FirstFoundPolicyPair, RemainingFoundPolicyPairs...>,
                RawPolicies...> {
                using type = typename convert_to_policy_holder_impl<
                    found_policy_pair_list<repeated, RemainingFoundPolicyPairs...>,
                    typename FirstFoundPolicyPair::policy, RawPolicies...>::type;
            };

            template <class FoundPolicyPairList>
            using convert_to_policy_holder =
                typename convert_to_policy_holder_impl<FoundPolicyPairList>::type;

            template <class DetectorDefaultPairList, class... Policies>
            struct make_policy_holder_impl {
                static_assert(check_policy_list_validity(DetectorDefaultPairList{},
                                                         dummy<Policies>{}...),
                              "jkj::dragonbox: an invalid policy is specified");

                static_assert(
                    !policy_pair_list<DetectorDefaultPairList, Policies...>::repeated,
                    "jkj::dragonbox: at most one policy should be specified for each policy kind");

                using type =
                    convert_to_policy_holder<policy_pair_list<DetectorDefaultPairList, Policies...>>;
            };

            template <class DetectorDefaultPairList, class... Policies>
            using make_policy_holder =
                typename make_policy_holder_impl<DetectorDefaultPairList, Policies...>::type;


            // Policy kind detectors.
            struct is_sign_policy {
                constexpr bool operator()(...) noexcept { return false; }
                template <class Policy, class = typename Policy::sign_policy>
                constexpr bool operator()(dummy<Policy>) noexcept {
                    return true;
                }
            };
            struct is_trailing_zero_policy {
                constexpr bool operator()(...) noexcept { return false; }
                template <class Policy, class = typename Policy::trailing_zero_policy>
                constexpr bool operator()(dummy<Policy>) noexcept {
                    return true;
                }
            };
            struct is_decimal_to_binary_rounding_policy {
                constexpr bool operator()(...) noexcept { return false; }
                template <class Policy, class = typename Policy::decimal_to_binary_rounding_policy>
                constexpr bool operator()(dummy<Policy>) noexcept {
                    return true;
                }
            };
            struct is_binary_to_decimal_rounding_policy {
                constexpr bool operator()(...) noexcept { return false; }
                template <class Policy, class = typename Policy::binary_to_decimal_rounding_policy>
                constexpr bool operator()(dummy<Policy>) noexcept {
                    return true;
                }
            };
            struct is_cache_policy {
                constexpr bool operator()(...) noexcept { return false; }
                template <class Policy, class = typename Policy::cache_policy>
                constexpr bool operator()(dummy<Policy>) noexcept {
                    return true;
                }
            };
            struct is_preferred_integer_types_policy {
                constexpr bool operator()(...) noexcept { return false; }
                template <class Policy, class = typename Policy::preferred_integer_types_policy>
                constexpr bool operator()(dummy<Policy>) noexcept {
                    return true;
                }
            };

            template <class... Policies>
            using to_decimal_policy_holder = make_policy_holder<
                detector_default_pair_list<
                    detector_default_pair<is_sign_policy, policy::sign::return_sign_t>,
                    detector_default_pair<is_trailing_zero_policy, policy::trailing_zero::remove_t>,
                    detector_default_pair<is_decimal_to_binary_rounding_policy,
                                          policy::decimal_to_binary_rounding::nearest_to_even_t>,
                    detector_default_pair<is_binary_to_decimal_rounding_policy,
                                          policy::binary_to_decimal_rounding::to_even_t>,
                    detector_default_pair<is_cache_policy, policy::cache::full_t>,
                    detector_default_pair<is_preferred_integer_types_policy,
                                          policy::preferred_integer_types::match_t>>,
                Policies...>;

            template <class FormatTraits, class... Policies>
            using to_decimal_return_type = typename impl<FormatTraits>::template return_type<
                typename to_decimal_policy_holder<Policies...>::sign_policy,
                typename to_decimal_policy_holder<Policies...>::trailing_zero_policy,
                typename to_decimal_policy_holder<Policies...>::preferred_integer_types_policy>;

            template <class FormatTraits, class PolicyHolder>
            struct to_decimal_dispatcher {
                using sign_policy = typename PolicyHolder::sign_policy;
                using trailing_zero_policy = typename PolicyHolder::trailing_zero_policy;
                using binary_to_decimal_rounding_policy =
                    typename PolicyHolder::binary_to_decimal_rounding_policy;
                using cache_policy = typename PolicyHolder::cache_policy;
                using preferred_integer_types_policy =
                    typename PolicyHolder::preferred_integer_types_policy;
                using return_type =
                    typename impl<FormatTraits>::template return_type<sign_policy, trailing_zero_policy,
                                                                      preferred_integer_types_policy>;

                template <class IntervalTypeProvider>
                JKJ_FORCEINLINE JKJ_SAFEBUFFERS JKJ_CONSTEXPR20 return_type
                operator()(IntervalTypeProvider, signed_significand_bits<FormatTraits> s,
                           typename FormatTraits::exponent_int exponent_bits) noexcept {
                    constexpr auto tag = IntervalTypeProvider::tag;

                    JKJ_IF_CONSTEXPR(tag == policy::decimal_to_binary_rounding::tag_t::to_nearest) {
                        return impl<FormatTraits>::template compute_nearest<
                            sign_policy, trailing_zero_policy, IntervalTypeProvider,
                            binary_to_decimal_rounding_policy, cache_policy,
                            preferred_integer_types_policy>(s, exponent_bits);
                    }
                    else JKJ_IF_CONSTEXPR(
                        tag == policy::decimal_to_binary_rounding::tag_t::left_closed_directed) {
                        return impl<FormatTraits>::template compute_left_closed_directed<
                            sign_policy, trailing_zero_policy, cache_policy,
                            preferred_integer_types_policy>(s, exponent_bits);
                    }
                    else {
#if JKJ_HAS_IF_CONSTEXPR
                        static_assert(
                            tag == policy::decimal_to_binary_rounding::tag_t::right_closed_directed,
                            "");
#endif
                        return impl<FormatTraits>::template compute_right_closed_directed<
                            sign_policy, trailing_zero_policy, cache_policy,
                            preferred_integer_types_policy>(s, exponent_bits);
                    }
                }
            };
        }


        ////////////////////////////////////////////////////////////////////////////////////////
        // The interface function.
        ////////////////////////////////////////////////////////////////////////////////////////

        template <class FormatTraits, class ExponentBits, class... Policies>
        JKJ_FORCEINLINE
            JKJ_SAFEBUFFERS JKJ_CONSTEXPR20 detail::to_decimal_return_type<FormatTraits, Policies...>
            to_decimal_ex(signed_significand_bits<FormatTraits> s, ExponentBits exponent_bits,
                          Policies...) noexcept {
            // Build policy holder type.
            using policy_holder = detail::to_decimal_policy_holder<Policies...>;

            return policy_holder::delegate(
                s, detail::to_decimal_dispatcher<FormatTraits, policy_holder>{}, s, exponent_bits);
        }

        template <class Float,
                  class ConversionTraits = default_float_bit_carrier_conversion_traits<Float>,
                  class FormatTraits = ieee754_binary_traits<typename ConversionTraits::format,
                                                             typename ConversionTraits::carrier_uint>,
                  class... Policies>
        JKJ_FORCEINLINE
            JKJ_SAFEBUFFERS JKJ_CONSTEXPR20 detail::to_decimal_return_type<FormatTraits, Policies...>
            to_decimal(Float x, Policies... policies) noexcept {
            auto const br = make_float_bits<Float, ConversionTraits, FormatTraits>(x);
            auto const exponent_bits = br.extract_exponent_bits();
            auto const s = br.remove_exponent_bits();
            assert(br.is_finite() && br.is_nonzero());

            return to_decimal_ex(s, exponent_bits, policies...);
        }
    }
}
}

#undef JKJ_HAS_BUILTIN
#undef JKJ_FORCEINLINE
#undef JKJ_SAFEBUFFERS
#undef JKJ_CONSTEXPR20
#undef JKJ_USE_IS_CONSTANT_EVALUATED
#undef JKJ_CAN_BRANCH_ON_CONSTEVAL
#undef JKJ_IF_NOT_CONSTEVAL
#undef JKJ_IF_CONSTEVAL
#undef JKJ_HAS_BIT_CAST
#undef JKJ_IF_CONSTEXPR
#undef JKJ_HAS_IF_CONSTEXPR
#undef JKJ_INLINE_VARIABLE
#undef JKJ_HAS_INLINE_VARIABLE
#undef JKJ_HAS_CONSTEXPR17
#undef JKJ_CONSTEXPR14
#undef JKJ_HAS_CONSTEXPR14
#if JKJ_STD_REPLACEMENT_NAMESPACE_DEFINED
    #undef JKJ_STD_REPLACEMENT_NAMESPACE_DEFINED
#else
    #undef JKJ_STD_REPLACEMENT_NAMESPACE
#endif
#if JKJ_STATIC_DATA_SECTION_DEFINED
    #undef JKJ_STATIC_DATA_SECTION_DEFINED
#else
    #undef JKJ_STATIC_DATA_SECTION
#endif

#endif
// ====== END yaml-cpp/src/contrib/dragonbox.h ======


#include <array>
#include <cassert>
#include <cmath>
#include <limits>
#include <sstream>
#include <tuple>

namespace YAML {
namespace detail {
namespace fp_formatting {

/**
 * Converts a integer into its ASCII digits.
 *
 * @param begin/end - a buffer, must be at least 20bytes long.
 * @param value     - input value.
 * @param width     - minimum number of digits, fill with '0' to the left. Must be equal or smaller than the buffer size.
 * @return          - number of digits filled into the buffer (or -1 if preconditions are not meet)
 *
 * Example:
 * std::array<char, 20> buffer;
 * auto ct = ConvertToChars(buffer.begin(), buffer.end(), 23, 3);
 * assert(ct = 3);
 * assert(buffer[0] == '0');
 * assert(buffer[1] == '2');
 * assert(buffer[2] == '3');
 */
int ConvertToChars(char* begin, char* end, size_t value, int width=1) {
  // precondition of this function (will trigger in debug build)
  assert(width >= 1);
  assert(end >= begin);       // end must be after begin
  assert(end-begin >= width); // Buffer must be large enough
  assert(end-begin >= 20);    // 2^64 has 20digits, so at least 20 digits must be available

  // defensive programming, abort if precondition are not met (will trigger in release build)
  if (width < 1) {
    return -1;
  }
  if (end < begin) {
    return -1;
  }
  if (end-begin < width) {
    return -1;
  }
  if (end-begin < 20) {
    return -1;
  }


  // count number of digits, and fill digits array accordingly
  int digits_ct{};
  while (value > 0) {
    char c = value % 10 + '0';
    value = value / 10;
    digits_ct += 1;
    *(end-digits_ct) = c;
  }
  while(digits_ct < width) {
    assert(digits_ct < 64);
    digits_ct += 1;
    *(end-digits_ct) = '0';
  }
  // move data to the front of the array
  std::memmove(begin, end-digits_ct, digits_ct);
  return digits_ct;
}

/**
 * Converts a float or double to a string.
 *
 * converts a value 'v' to a string. Uses dragonbox for formatting.
 */
template <typename T>
std::string FpToString(T v, int precision = 0) {
  // hard coded constant, at which exponent should switch to a scientific notation
  int const lowerExponentThreshold = -5;
  int const upperExponentThreshold =  (precision==0)?6:precision;
  if (precision == 0) {
    precision = 6;
  }

  // dragonbox/to_decimal does not handle value 0, inf, NaN
  if (v == 0 || std::isinf(v) || std::isnan(v)) {
    std::stringstream ss;
    ss.imbue(std::locale("C"));
    ss << v;
    return ss.str();
  }

  auto r = jkj::dragonbox::to_decimal(v);

  auto digits  = std::array<char, 20>{}; // max digits of size_t is 20.
  auto digits_ct = ConvertToChars(digits.data(), digits.data() + digits.size(), r.significand);

  // defensive programming, ConvertToChars arguments are invalid
  if (digits_ct == -1) {
    std::stringstream ss;
    ss.imbue(std::locale("C"));
    ss << v;
    return ss.str();
  }

  // check if requested precision is lower than
  // required digits for exact representation
  if (digits_ct > precision) {
    auto diff = digits_ct - precision;
    r.exponent += diff;
    digits_ct = precision;

    // round numbers if required
    if (digits[digits_ct] >= '5') {
      int i{digits_ct-1};
      digits[i] += 1;
      while (digits[i] == '9'+1) {
        digits_ct -= 1;
        r.exponent += 1;
        if (i > 0) {
          digits[i-1] += 1;
          i -= 1;
        } else {
          digits_ct = 1;
          digits[0] = '1';
          break;
        }
      }
    }
  }

  std::array<char, 28> output_buffer; // max digits of size_t plus sign, a dot and 2 letters for 'e+' or 'e-' and 4 letters for the exponent
  auto output_ptr = &output_buffer[0];

  // print '-' symbol for negative numbers
  if (r.is_negative) {
    *(output_ptr++) = '-';
  }

  // exponent if only a single non-zero digit is before the decimal point
  int const exponent = r.exponent + digits_ct - 1;

  // case 1: scientific notation
  if (exponent >= upperExponentThreshold || exponent <= lowerExponentThreshold) {
    // print first digit
    *(output_ptr++) = digits[0];

    // print digits after decimal point
    if (digits_ct > 1) {
      *(output_ptr++) = '.';
      // print significant numbers after decimal point
      for (int i{1}; i < digits_ct; ++i) {
         *(output_ptr++) = digits[i];
      }
    }
    *(output_ptr++) = 'e';
    *(output_ptr++) = (exponent>=0)?'+':'-';
    auto exp_digits = std::array<char, 20>{};
    auto exp_digits_ct = ConvertToChars(exp_digits.data(), exp_digits.data() + exp_digits.size(), std::abs(exponent), /*.precision=*/ 2);

    // defensive programming, ConvertToChars arguments are invalid
    if (exp_digits_ct == -1) {
      std::stringstream ss;
      ss.imbue(std::locale("C"));
      ss << v;
      return ss.str();
    }

    for (int i{0}; i < exp_digits_ct; ++i) {
      *(output_ptr++) = exp_digits[i];
    }

  // case 2: default notation
  } else {
    auto const digits_end   = digits.begin() + digits_ct;
    auto digits_iter    = digits.begin();

    // print digits before point
    int const before_decimal_digits = digits_ct + r.exponent;
    if (before_decimal_digits > 0) {
      // print digits before point
      for (int i{0}; i < std::min(before_decimal_digits, digits_ct); ++i) {
        *(output_ptr++) = *(digits_iter++);
      }
      // print trailing zeros before point
      for (int i{0}; i < before_decimal_digits - digits_ct; ++i) {
        *(output_ptr++) = '0';
      }

    // print 0 before point if none where printed before
    } else {
      *(output_ptr++) = '0';
    }

    if (digits_iter != digits_end) {
      *(output_ptr++) = '.';
      // print 0 after decimal point, to fill until first digits
      int const after_decimal_zeros = -digits_ct - r.exponent;
      for (int i{0}; i < after_decimal_zeros; ++i) {
         *(output_ptr++) = '0';
      }

      // print significant numbers after decimal point
      for (;digits_iter < digits_end; ++digits_iter) {
         *(output_ptr++) = *digits_iter;
      }
    }
  }
  *output_ptr = '\0';
  return std::string{&output_buffer[0], output_ptr};
}

}
}

std::string FpToString(float v, size_t precision) {
  return detail::fp_formatting::FpToString(v, precision);
}

std::string FpToString(double v, size_t precision) {
  return detail::fp_formatting::FpToString(v, precision);
}

/**
 * dragonbox only works for floats/doubles not long double
 */
std::string FpToString(long double v, size_t precision) {
  std::stringstream ss;
  ss.imbue(std::locale("C"));
  if (precision == 0) {
     precision = std::numeric_limits<long double>::max_digits10;
  }
  ss.precision(precision);
  ss << v;
  return ss.str();
}

}
// ====== END yaml-cpp/src/fptostring.cpp ======


// ====== BEGIN yaml-cpp/src/memory.cpp ======
// Expanding include: yaml-cpp/node/detail/memory.h
// Expanding include: yaml-cpp/node/detail/node.h
// Expanding include: yaml-cpp/node/ptr.h

namespace YAML {
namespace detail {

void memory_holder::merge(memory_holder& rhs) {
  if (m_pMemory == rhs.m_pMemory)
    return;

  m_pMemory->merge(*rhs.m_pMemory);
  rhs.m_pMemory = m_pMemory;
}

node& memory::create_node() {
  shared_node pNode(new node);
  m_nodes.insert(pNode);
  return *pNode;
}

void memory::merge(const memory& rhs) {
  m_nodes.insert(rhs.m_nodes.begin(), rhs.m_nodes.end());
}
}  // namespace detail
}  // namespace YAML
// ====== END yaml-cpp/src/memory.cpp ======


// ====== BEGIN yaml-cpp/src/nodebuilder.cpp ======
#include <cassert>

// Expanding include: nodebuilder.h

// ====== BEGIN yaml-cpp/src/nodebuilder.h ======
#ifndef NODE_NODEBUILDER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_NODEBUILDER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <vector>

// Expanding include: yaml-cpp/anchor.h
// Expanding include: yaml-cpp/emitterstyle.h
// Expanding include: yaml-cpp/eventhandler.h
// Expanding include: yaml-cpp/node/ptr.h

namespace YAML {
namespace detail {
class node;
}  // namespace detail
struct Mark;
}  // namespace YAML

namespace YAML {
class Node;

class NodeBuilder : public EventHandler {
 public:
  NodeBuilder();
  NodeBuilder(const NodeBuilder&) = delete;
  NodeBuilder(NodeBuilder&&) = delete;
  NodeBuilder& operator=(const NodeBuilder&) = delete;
  NodeBuilder& operator=(NodeBuilder&&) = delete;
  ~NodeBuilder() override;

  Node Root();

  void OnDocumentStart(const Mark& mark) override;
  void OnDocumentEnd() override;

  void OnNull(const Mark& mark, anchor_t anchor) override;
  void OnAlias(const Mark& mark, anchor_t anchor) override;
  void OnScalar(const Mark& mark, const std::string& tag,
                        anchor_t anchor, const std::string& value) override;

  void OnSequenceStart(const Mark& mark, const std::string& tag,
                               anchor_t anchor, EmitterStyle::value style) override;
  void OnSequenceEnd() override;

  void OnMapStart(const Mark& mark, const std::string& tag,
                          anchor_t anchor, EmitterStyle::value style) override;
  void OnMapEnd() override;

 private:
  detail::node& Push(const Mark& mark, anchor_t anchor);
  void Push(detail::node& node);
  void Pop();
  void RegisterAnchor(anchor_t anchor, detail::node& node);

 private:
  detail::shared_memory_holder m_pMemory;
  detail::node* m_pRoot;

  using Nodes = std::vector<detail::node *>;
  Nodes m_stack;
  Nodes m_anchors;

  using PushedKey = std::pair<detail::node*, bool>;
  std::vector<PushedKey> m_keys;
  std::size_t m_mapDepth;
};
}  // namespace YAML

#endif  // NODE_NODEBUILDER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/nodebuilder.h ======

// Expanding include: yaml-cpp/node/detail/node.h
// Expanding include: yaml-cpp/node/impl.h
// Expanding include: yaml-cpp/node/node.h
// Expanding include: yaml-cpp/node/type.h

namespace YAML {
struct Mark;

NodeBuilder::NodeBuilder()
    : m_pMemory(new detail::memory_holder),
      m_pRoot(nullptr),
      m_stack{},
      m_anchors{},
      m_keys{},
      m_mapDepth(0) {
  m_anchors.push_back(nullptr);  // since the anchors start at 1
}

NodeBuilder::~NodeBuilder() = default;

Node NodeBuilder::Root() {
  if (!m_pRoot)
    return Node();

  return Node(*m_pRoot, m_pMemory);
}

void NodeBuilder::OnDocumentStart(const Mark&) {}

void NodeBuilder::OnDocumentEnd() {}

void NodeBuilder::OnNull(const Mark& mark, anchor_t anchor) {
  detail::node& node = Push(mark, anchor);
  node.set_null();
  Pop();
}

void NodeBuilder::OnAlias(const Mark& /* mark */, anchor_t anchor) {
  detail::node& node = *m_anchors[anchor];
  Push(node);
  Pop();
}

void NodeBuilder::OnScalar(const Mark& mark, const std::string& tag,
                           anchor_t anchor, const std::string& value) {
  detail::node& node = Push(mark, anchor);
  node.set_scalar(value);
  node.set_tag(tag);
  Pop();
}

void NodeBuilder::OnSequenceStart(const Mark& mark, const std::string& tag,
                                  anchor_t anchor, EmitterStyle::value style) {
  detail::node& node = Push(mark, anchor);
  node.set_tag(tag);
  node.set_type(NodeType::Sequence);
  node.set_style(style);
}

void NodeBuilder::OnSequenceEnd() { Pop(); }

void NodeBuilder::OnMapStart(const Mark& mark, const std::string& tag,
                             anchor_t anchor, EmitterStyle::value style) {
  detail::node& node = Push(mark, anchor);
  node.set_type(NodeType::Map);
  node.set_tag(tag);
  node.set_style(style);
  m_mapDepth++;
}

void NodeBuilder::OnMapEnd() {
  assert(m_mapDepth > 0);
  m_mapDepth--;
  Pop();
}

detail::node& NodeBuilder::Push(const Mark& mark, anchor_t anchor) {
  detail::node& node = m_pMemory->create_node();
  node.set_mark(mark);
  RegisterAnchor(anchor, node);
  Push(node);
  return node;
}

void NodeBuilder::Push(detail::node& node) {
  const bool needsKey =
      (!m_stack.empty() && m_stack.back()->type() == NodeType::Map &&
       m_keys.size() < m_mapDepth);

  m_stack.push_back(&node);
  if (needsKey)
    m_keys.emplace_back(&node, false);
}

void NodeBuilder::Pop() {
  assert(!m_stack.empty());
  if (m_stack.size() == 1) {
    m_pRoot = m_stack[0];
    m_stack.pop_back();
    return;
  }

  detail::node& node = *m_stack.back();
  m_stack.pop_back();

  detail::node& collection = *m_stack.back();

  if (collection.type() == NodeType::Sequence) {
    collection.push_back(node, m_pMemory);
  } else if (collection.type() == NodeType::Map) {
    assert(!m_keys.empty());
    PushedKey& key = m_keys.back();
    if (key.second) {
      collection.insert(*key.first, node, m_pMemory);
      m_keys.pop_back();
    } else {
      key.second = true;
    }
  } else {
    assert(false);
    m_stack.clear();
  }
}

void NodeBuilder::RegisterAnchor(anchor_t anchor, detail::node& node) {
  if (anchor) {
    assert(anchor == m_anchors.size());
    m_anchors.push_back(&node);
  }
}
}  // namespace YAML
// ====== END yaml-cpp/src/nodebuilder.cpp ======


// ====== BEGIN yaml-cpp/src/node.cpp ======
// Expanding include: yaml-cpp/node/node.h
// Expanding include: nodebuilder.h
// Expanding include: nodeevents.h

namespace YAML {
Node Clone(const Node& node) {
  NodeEvents events(node);
  NodeBuilder builder;
  events.Emit(builder);
  return builder.Root();
}
}  // namespace YAML
// ====== END yaml-cpp/src/node.cpp ======


// ====== BEGIN yaml-cpp/src/node_data.cpp ======
#include <algorithm>
#include <cassert>
#include <iterator>
#include <sstream>

// Expanding include: yaml-cpp/exceptions.h
// Expanding include: yaml-cpp/node/detail/memory.h
// Expanding include: yaml-cpp/node/detail/node.h
// Expanding include: yaml-cpp/node/detail/node_data.h
// Expanding include: yaml-cpp/node/detail/node_iterator.h
// Expanding include: yaml-cpp/node/ptr.h
// Expanding include: yaml-cpp/node/type.h

namespace YAML {
namespace detail {
YAML_CPP_API std::atomic<size_t> node::m_amount{0};

const std::string& node_data::empty_scalar() {
  static const std::string svalue;
  return svalue;
}

node_data::node_data()
    : m_isDefined(false),
      m_mark(Mark::null_mark()),
      m_type(NodeType::Null),
      m_tag{},
      m_style(EmitterStyle::Default),
      m_scalar{},
      m_sequence{},
      m_seqSize(0),
      m_map{},
      m_undefinedPairs{} {}

void node_data::mark_defined() {
  if (m_type == NodeType::Undefined)
    m_type = NodeType::Null;
  m_isDefined = true;
}

void node_data::set_mark(const Mark& mark) { m_mark = mark; }

void node_data::set_type(NodeType::value type) {
  if (type == NodeType::Undefined) {
    m_type = type;
    m_isDefined = false;
    return;
  }

  m_isDefined = true;
  if (type == m_type)
    return;

  m_type = type;

  switch (m_type) {
    case NodeType::Null:
      break;
    case NodeType::Scalar:
      m_scalar.clear();
      break;
    case NodeType::Sequence:
      reset_sequence();
      break;
    case NodeType::Map:
      reset_map();
      break;
    case NodeType::Undefined:
      assert(false);
      break;
  }
}

void node_data::set_tag(const std::string& tag) { m_tag = tag; }

void node_data::set_style(EmitterStyle::value style) { m_style = style; }

void node_data::set_null() {
  m_isDefined = true;
  m_type = NodeType::Null;
}

void node_data::set_scalar(const std::string& scalar) {
  m_isDefined = true;
  m_type = NodeType::Scalar;
  m_scalar = scalar;
}

// size/iterator
std::size_t node_data::size() const {
  if (!m_isDefined)
    return 0;

  switch (m_type) {
    case NodeType::Sequence:
      compute_seq_size();
      return m_seqSize;
    case NodeType::Map:
      compute_map_size();
      return m_map.size() - m_undefinedPairs.size();
    default:
      return 0;
  }
  return 0;
}

void node_data::compute_seq_size() const {
  while (m_seqSize < m_sequence.size() && m_sequence[m_seqSize]->is_defined())
    m_seqSize++;
}

void node_data::compute_map_size() const {
  auto it = m_undefinedPairs.begin();
  while (it != m_undefinedPairs.end()) {
    auto jt = std::next(it);
    if (it->first->is_defined() && it->second->is_defined())
      m_undefinedPairs.erase(it);
    it = jt;
  }
}

const_node_iterator node_data::begin() const {
  if (!m_isDefined)
    return {};

  switch (m_type) {
    case NodeType::Sequence:
      return const_node_iterator(m_sequence.begin());
    case NodeType::Map:
      return const_node_iterator(m_map.begin(), m_map.end());
    default:
      return {};
  }
}

node_iterator node_data::begin() {
  if (!m_isDefined)
    return {};

  switch (m_type) {
    case NodeType::Sequence:
      return node_iterator(m_sequence.begin());
    case NodeType::Map:
      return node_iterator(m_map.begin(), m_map.end());
    default:
      return {};
  }
}

const_node_iterator node_data::end() const {
  if (!m_isDefined)
    return {};

  switch (m_type) {
    case NodeType::Sequence:
      return const_node_iterator(m_sequence.end());
    case NodeType::Map:
      return const_node_iterator(m_map.end(), m_map.end());
    default:
      return {};
  }
}

node_iterator node_data::end() {
  if (!m_isDefined)
    return {};

  switch (m_type) {
    case NodeType::Sequence:
      return node_iterator(m_sequence.end());
    case NodeType::Map:
      return node_iterator(m_map.end(), m_map.end());
    default:
      return {};
  }
}

// sequence
void node_data::push_back(node& node,
                          const shared_memory_holder& /* pMemory */) {
  if (m_type == NodeType::Undefined || m_type == NodeType::Null) {
    m_type = NodeType::Sequence;
    reset_sequence();
  }

  if (m_type != NodeType::Sequence)
    throw BadPushback();

  m_sequence.push_back(&node);
}

void node_data::insert(node& key, node& value,
                       const shared_memory_holder& pMemory) {
  switch (m_type) {
    case NodeType::Map:
      break;
    case NodeType::Undefined:
    case NodeType::Null:
    case NodeType::Sequence:
      convert_to_map(pMemory);
      break;
    case NodeType::Scalar:
      throw BadSubscript(m_mark, key);
  }

  insert_map_pair(key, value);
}

// indexing
node* node_data::get(node& key,
                     const shared_memory_holder& /* pMemory */) const {
  if (m_type != NodeType::Map) {
    return nullptr;
  }

  for (const auto& it : m_map) {
    if (it.first->is(key))
      return it.second;
  }

  return nullptr;
}

node& node_data::get(node& key, const shared_memory_holder& pMemory) {
  switch (m_type) {
    case NodeType::Map:
      break;
    case NodeType::Undefined:
    case NodeType::Null:
    case NodeType::Sequence:
      convert_to_map(pMemory);
      break;
    case NodeType::Scalar:
      throw BadSubscript(m_mark, key);
  }

  for (const auto& it : m_map) {
    if (it.first->is(key))
      return *it.second;
  }

  node& value = pMemory->create_node();
  insert_map_pair(key, value);
  return value;
}

bool node_data::remove(node& key, const shared_memory_holder& /* pMemory */) {
  if (m_type != NodeType::Map)
    return false;

  for (auto it = m_undefinedPairs.begin(); it != m_undefinedPairs.end();) {
    auto jt = std::next(it);
    if (it->first->is(key))
      m_undefinedPairs.erase(it);
    it = jt;
  }

  auto it =
      std::find_if(m_map.begin(), m_map.end(),
                   [&](std::pair<YAML::detail::node*, YAML::detail::node*> j) {
                     return (j.first->is(key));
                   });

  if (it != m_map.end()) {
    m_map.erase(it);
    return true;
  }

  return false;
}

void node_data::reset_sequence() {
  m_sequence.clear();
  m_seqSize = 0;
}

void node_data::reset_map() {
  m_map.clear();
  m_undefinedPairs.clear();
}

void node_data::insert_map_pair(node& key, node& value) {
  m_map.emplace_back(&key, &value);

  if (!key.is_defined() || !value.is_defined())
    m_undefinedPairs.emplace_back(&key, &value);
}

void node_data::convert_to_map(const shared_memory_holder& pMemory) {
  switch (m_type) {
    case NodeType::Undefined:
    case NodeType::Null:
      reset_map();
      m_type = NodeType::Map;
      break;
    case NodeType::Sequence:
      convert_sequence_to_map(pMemory);
      break;
    case NodeType::Map:
      break;
    case NodeType::Scalar:
      assert(false);
      break;
  }
}

void node_data::convert_sequence_to_map(const shared_memory_holder& pMemory) {
  assert(m_type == NodeType::Sequence);

  reset_map();
  for (std::size_t i = 0; i < m_sequence.size(); i++) {
    std::stringstream stream;
    stream.imbue(std::locale("C"));
    stream << i;

    node& key = pMemory->create_node();
    key.set_scalar(stream.str());
    insert_map_pair(key, *m_sequence[i]);
  }

  reset_sequence();
  m_type = NodeType::Map;
}
}  // namespace detail
}  // namespace YAML
// ====== END yaml-cpp/src/node_data.cpp ======


// ====== BEGIN yaml-cpp/src/nodeevents.cpp ======
// Expanding include: nodeevents.h
// Expanding include: yaml-cpp/eventhandler.h
// Expanding include: yaml-cpp/mark.h
// Expanding include: yaml-cpp/node/detail/node.h
// Expanding include: yaml-cpp/node/detail/node_iterator.h
// Expanding include: yaml-cpp/node/node.h
// Expanding include: yaml-cpp/node/type.h

namespace YAML {
void NodeEvents::AliasManager::RegisterReference(const detail::node& node) {
  m_anchorByIdentity.insert(std::make_pair(node.ref(), _CreateNewAnchor()));
}

anchor_t NodeEvents::AliasManager::LookupAnchor(
    const detail::node& node) const {
  auto it = m_anchorByIdentity.find(node.ref());
  if (it == m_anchorByIdentity.end())
    return 0;
  return it->second;
}

NodeEvents::NodeEvents(const Node& node)
    : m_pMemory(node.m_pMemory), m_root(node.m_pNode), m_refCount{} {
  if (m_root)
    Setup(*m_root);
}

void NodeEvents::Setup(const detail::node& node) {
  int& refCount = m_refCount[node.ref()];
  refCount++;
  if (refCount > 1)
    return;

  if (node.type() == NodeType::Sequence) {
    for (auto element : node)
      Setup(*element);
  } else if (node.type() == NodeType::Map) {
    for (auto element : node) {
      Setup(*element.first);
      Setup(*element.second);
    }
  }
}

void NodeEvents::Emit(EventHandler& handler) {
  AliasManager am;

  handler.OnDocumentStart(Mark());
  if (m_root)
    Emit(*m_root, handler, am);
  handler.OnDocumentEnd();
}

void NodeEvents::Emit(const detail::node& node, EventHandler& handler,
                      AliasManager& am) const {
  anchor_t anchor = NullAnchor;
  if (IsAliased(node)) {
    anchor = am.LookupAnchor(node);
    if (anchor) {
      handler.OnAlias(Mark(), anchor);
      return;
    }

    am.RegisterReference(node);
    anchor = am.LookupAnchor(node);
  }

  switch (node.type()) {
    case NodeType::Undefined:
      break;
    case NodeType::Null:
      handler.OnNull(Mark(), anchor);
      break;
    case NodeType::Scalar:
      handler.OnScalar(Mark(), node.tag(), anchor, node.scalar());
      break;
    case NodeType::Sequence:
      handler.OnSequenceStart(Mark(), node.tag(), anchor, node.style());
      for (auto element : node)
        Emit(*element, handler, am);
      handler.OnSequenceEnd();
      break;
    case NodeType::Map:
      handler.OnMapStart(Mark(), node.tag(), anchor, node.style());
      for (auto element : node) {
        Emit(*element.first, handler, am);
        Emit(*element.second, handler, am);
      }
      handler.OnMapEnd();
      break;
  }
}

bool NodeEvents::IsAliased(const detail::node& node) const {
  auto it = m_refCount.find(node.ref());
  return it != m_refCount.end() && it->second > 1;
}
}  // namespace YAML
// ====== END yaml-cpp/src/nodeevents.cpp ======


// ====== BEGIN yaml-cpp/src/null.cpp ======
// Expanding include: yaml-cpp/null.h
#include <cstring>

namespace YAML {
_Null Null;

template <std::size_t N>
static bool same(const char* str, std::size_t size, const char (&literal)[N]) {
  constexpr int literalSize = N - 1; // minus null terminator
  return size == literalSize && std::strncmp(str, literal, literalSize) == 0;
}

bool IsNullString(const char* str, std::size_t size) {
  return size == 0 || same(str, size, "~") || same(str, size, "null") ||
         same(str, size, "Null") || same(str, size, "NULL");
}
}  // namespace YAML
// ====== END yaml-cpp/src/null.cpp ======


// ====== BEGIN yaml-cpp/src/ostream_wrapper.cpp ======
// Expanding include: yaml-cpp/ostream_wrapper.h

#include <algorithm>
#include <cstring>
#include <ostream>

namespace YAML {
ostream_wrapper::ostream_wrapper()
    : m_buffer(1, '\0'),
      m_pStream(nullptr),
      m_pos(0),
      m_row(0),
      m_col(0),
      m_comment(false) {}

ostream_wrapper::ostream_wrapper(std::ostream& stream)
    : m_buffer{},
      m_pStream(&stream),
      m_pos(0),
      m_row(0),
      m_col(0),
      m_comment(false) {}

ostream_wrapper::~ostream_wrapper() = default;

void ostream_wrapper::write(const std::string& str) {
  if (m_pStream) {
    m_pStream->write(str.c_str(), str.size());
  } else {
    m_buffer.resize(std::max(m_buffer.size(), m_pos + str.size() + 1));
    std::copy(str.begin(), str.end(), m_buffer.begin() + m_pos);
  }

  for (char ch : str) {
    update_pos(ch);
  }
}

void ostream_wrapper::write(const char* str, std::size_t size) {
  if (m_pStream) {
    m_pStream->write(str, size);
  } else {
    m_buffer.resize(std::max(m_buffer.size(), m_pos + size + 1));
    std::copy(str, str + size, m_buffer.begin() + m_pos);
  }

  for (std::size_t i = 0; i < size; i++) {
    update_pos(str[i]);
  }
}

void ostream_wrapper::update_pos(char ch) {
  m_pos++;
  m_col++;

  if (ch == '\n') {
    m_row++;
    m_col = 0;
    m_comment = false;
  }
}
}  // namespace YAML
// ====== END yaml-cpp/src/ostream_wrapper.cpp ======


// ====== BEGIN yaml-cpp/src/parse.cpp ======
// Expanding include: yaml-cpp/node/parse.h

#include <fstream>
#include <sstream>

// Expanding include: nodebuilder.h
// Expanding include: yaml-cpp/node/impl.h
// Expanding include: yaml-cpp/node/node.h
// Expanding include: yaml-cpp/parser.h

namespace YAML {
Node Load(const std::string& input) {
  std::stringstream stream(input);
  return Load(stream);
}

Node Load(const char* input) {
  std::stringstream stream(input);
  return Load(stream);
}

Node Load(std::istream& input) {
  Parser parser(input);
  NodeBuilder builder;
  if (!parser.HandleNextDocument(builder)) {
    return Node();
  }

  return builder.Root();
}

Node LoadFile(const std::string& filename) {
  std::ifstream fin(filename);
  if (!fin) {
    throw BadFile(filename);
  }
  return Load(fin);
}

std::vector<Node> LoadAll(const std::string& input) {
  std::stringstream stream(input);
  return LoadAll(stream);
}

std::vector<Node> LoadAll(const char* input) {
  std::stringstream stream(input);
  return LoadAll(stream);
}

std::vector<Node> LoadAll(std::istream& input) {
  std::vector<Node> docs;

  Parser parser(input);
  while (true) {
    NodeBuilder builder;
    if (!parser.HandleNextDocument(builder) || builder.Root().IsNull()) {
      break;
    }
    docs.push_back(builder.Root());
  }

  return docs;
}

std::vector<Node> LoadAllFromFile(const std::string& filename) {
  std::ifstream fin(filename);
  if (!fin) {
    throw BadFile(filename);
  }
  return LoadAll(fin);
}
}  // namespace YAML
// ====== END yaml-cpp/src/parse.cpp ======


// ====== BEGIN yaml-cpp/src/parser.cpp ======
#include <cstdio>
#include <sstream>

// Expanding include: directives.h
// Expanding include: scanner.h

// ====== BEGIN yaml-cpp/src/scanner.h ======
#ifndef SCANNER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define SCANNER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <cstddef>
#include <ios>
#include <queue>
#include <stack>
#include <string>

// Expanding include: ptr_vector.h

// ====== BEGIN yaml-cpp/src/ptr_vector.h ======
#ifndef PTR_VECTOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define PTR_VECTOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <cstddef>
#include <cstdlib>
#include <memory>
#include <vector>

namespace YAML {

// TODO: This class is no longer needed
template <typename T>
class ptr_vector {
 public:
  ptr_vector() : m_data{} {}
  ptr_vector(const ptr_vector&) = delete;
  ptr_vector(ptr_vector&&) = default;
  ptr_vector& operator=(const ptr_vector&) = delete;
  ptr_vector& operator=(ptr_vector&&) = default;

  void clear() { m_data.clear(); }

  std::size_t size() const { return m_data.size(); }
  bool empty() const { return m_data.empty(); }

  void push_back(std::unique_ptr<T>&& t) { m_data.push_back(std::move(t)); }
  T& operator[](std::size_t i) { return *m_data[i]; }
  const T& operator[](std::size_t i) const { return *m_data[i]; }

  T& back() { return *(m_data.back().get()); }

  const T& back() const { return *(m_data.back().get()); }

 private:
  std::vector<std::unique_ptr<T>> m_data;
};
}  // namespace YAML

#endif  // PTR_VECTOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/ptr_vector.h ======

// Expanding include: stream.h
// Expanding include: token.h

// ====== BEGIN yaml-cpp/src/token.h ======
#ifndef TOKEN_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define TOKEN_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// Expanding include: yaml-cpp/mark.h
#include <ostream>
#include <string>
#include <vector>

namespace YAML {
constexpr const char* TokenNames[] = {
    "DIRECTIVE",        "DOC_START",      "DOC_END",       "BLOCK_SEQ_START",
    "BLOCK_MAP_START",  "BLOCK_SEQ_END",  "BLOCK_MAP_END", "BLOCK_ENTRY",
    "FLOW_SEQ_START",   "FLOW_MAP_START", "FLOW_SEQ_END",  "FLOW_MAP_END",
    "FLOW_MAP_COMPACT", "FLOW_ENTRY",     "KEY",           "VALUE",
    "ANCHOR",           "ALIAS",          "TAG",           "SCALAR",
    "NON_PLAIN_SCALAR"};

struct Token {
  // enums
  enum STATUS { VALID, INVALID, UNVERIFIED };
  enum TYPE {
    DIRECTIVE,
    DOC_START,
    DOC_END,
    BLOCK_SEQ_START,
    BLOCK_MAP_START,
    BLOCK_SEQ_END,
    BLOCK_MAP_END,
    BLOCK_ENTRY,
    FLOW_SEQ_START,
    FLOW_MAP_START,
    FLOW_SEQ_END,
    FLOW_MAP_END,
    FLOW_MAP_COMPACT,
    FLOW_ENTRY,
    KEY,
    VALUE,
    ANCHOR,
    ALIAS,
    TAG,
    PLAIN_SCALAR,
    NON_PLAIN_SCALAR
  };

  // data
  Token(TYPE type_, const Mark& mark_)
      : status(VALID), type(type_), mark(mark_), value{}, params{}, data(0) {}

  friend std::ostream& operator<<(std::ostream& out, const Token& token) {
    out << TokenNames[token.type] << std::string(": ") << token.value;
    for (const std::string& param : token.params)
      out << std::string(" ") << param;
    return out;
  }

  STATUS status;
  TYPE type;
  Mark mark;
  std::string value;
  std::vector<std::string> params;
  int data;
};
}  // namespace YAML

#endif  // TOKEN_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/token.h ======

// Expanding include: yaml-cpp/mark.h

namespace YAML {
class Node;
class RegEx;

/**
 * A scanner transforms a stream of characters into a stream of tokens.
 */
class Scanner {
 public:
  explicit Scanner(std::istream &in);
  ~Scanner();

  /** Returns true if there are no more tokens to be read. */
  bool empty();

  /** Removes the next token in the queue. */
  void pop();

  /** Returns, but does not remove, the next token in the queue. */
  Token &peek();

  /** Returns the current mark in the input stream. */
  Mark mark() const;

 private:
  struct IndentMarker {
    enum INDENT_TYPE { MAP, SEQ, NONE };
    enum STATUS { VALID, INVALID, UNKNOWN };
    IndentMarker(int column_, INDENT_TYPE type_)
        : column(column_), type(type_), status(VALID), pStartToken(nullptr) {}

    int column;
    INDENT_TYPE type;
    STATUS status;
    Token *pStartToken;
  };

  enum FLOW_MARKER { FLOW_MAP, FLOW_SEQ };

 private:
  // scanning

  /**
   * Scans until there's a valid token at the front of the queue, or the queue
   * is empty. The state can be checked by {@link #empty}, and the next token
   * retrieved by {@link #peek}.
   */
  void EnsureTokensInQueue();

  /**
   * The main scanning function; this method branches out to scan whatever the
   * next token should be.
   */
  void ScanNextToken();

  /** Eats the input stream until it reaches the next token-like thing. */
  void ScanToNextToken();

  /** Sets the initial conditions for starting a stream. */
  void StartStream();

  /** Closes out the stream, finish up, etc. */
  void EndStream();

  Token *PushToken(Token::TYPE type);

  bool InFlowContext() const { return !m_flows.empty(); }
  bool InBlockContext() const { return m_flows.empty(); }
  std::size_t GetFlowLevel() const { return m_flows.size(); }

  Token::TYPE GetStartTokenFor(IndentMarker::INDENT_TYPE type) const;

  /**
   * Pushes an indentation onto the stack, and enqueues the proper token
   * (sequence start or mapping start).
   *
   * @return the indent marker it generates (if any).
   */
  IndentMarker *PushIndentTo(int column, IndentMarker::INDENT_TYPE type);

  /**
   * Pops indentations off the stack until it reaches the current indentation
   * level, and enqueues the proper token each time. Then pops all invalid
   * indentations off.
   */
  void PopIndentToHere();

  /**
   * Pops all indentations (except for the base empty one) off the stack, and
   * enqueues the proper token each time.
   */
  void PopAllIndents();

  /** Pops a single indent, pushing the proper token. */
  void PopIndent();
  int GetTopIndent() const;

  // checking input
  bool CanInsertPotentialSimpleKey() const;
  bool ExistsActiveSimpleKey() const;
  void InsertPotentialSimpleKey();
  void InvalidateSimpleKey();
  bool VerifySimpleKey();
  void PopAllSimpleKeys();

  /**
   * Throws a ParserException with the current token location (if available),
   * and does not parse any more tokens.
   */
  void ThrowParserException(const std::string &msg) const;

  bool IsWhitespaceToBeEaten(char ch);

  /**
   * Returns the appropriate regex to check if the next token is a value token.
   */
  const RegEx &GetValueRegex() const;

  struct SimpleKey {
    SimpleKey(const Mark &mark_, std::size_t flowLevel_);

    void Validate();
    void Invalidate();

    Mark mark;
    std::size_t flowLevel;
    IndentMarker *pIndent;
    Token *pMapStart, *pKey;
  };

  // and the tokens
  void ScanDirective();
  void ScanDocStart();
  void ScanDocEnd();
  void ScanBlockSeqStart();
  void ScanBlockMapSTart();
  void ScanBlockEnd();
  void ScanBlockEntry();
  void ScanFlowStart();
  void ScanFlowEnd();
  void ScanFlowEntry();
  void ScanKey();
  void ScanValue();
  void ScanAnchorOrAlias();
  void ScanTag();
  void ScanPlainScalar();
  void ScanQuotedScalar();
  void ScanBlockScalar();

 private:
  // the stream
  Stream INPUT;

  // the output (tokens)
  std::queue<Token> m_tokens;

  // state info
  bool m_startedStream, m_endedStream;
  bool m_simpleKeyAllowed;
  bool m_scalarValueAllowed;
  bool m_canBeJSONFlow;
  std::stack<SimpleKey> m_simpleKeys;
  std::stack<IndentMarker *> m_indents;
  ptr_vector<IndentMarker> m_indentRefs;  // for "garbage collection"
  std::stack<FLOW_MARKER> m_flows;
};
}

#endif  // SCANNER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/scanner.h ======

// Expanding include: singledocparser.h

// ====== BEGIN yaml-cpp/src/singledocparser.h ======
#ifndef SINGLEDOCPARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define SINGLEDOCPARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <map>
#include <memory>
#include <string>

// Expanding include: yaml-cpp/anchor.h

namespace YAML {
class CollectionStack;
template <int> class DepthGuard; // depthguard.h
class EventHandler;
class Node;
class Scanner;
struct Directives;
struct Mark;
struct Token;

class SingleDocParser {
 public:
  SingleDocParser(Scanner& scanner, const Directives& directives);
  SingleDocParser(const SingleDocParser&) = delete;
  SingleDocParser(SingleDocParser&&) = delete;
  SingleDocParser& operator=(const SingleDocParser&) = delete;
  SingleDocParser& operator=(SingleDocParser&&) = delete;
  ~SingleDocParser();

  void HandleDocument(EventHandler& eventHandler);

 private:
  void HandleNode(EventHandler& eventHandler);

  void HandleSequence(EventHandler& eventHandler);
  void HandleBlockSequence(EventHandler& eventHandler);
  void HandleFlowSequence(EventHandler& eventHandler);

  void HandleMap(EventHandler& eventHandler);
  void HandleBlockMap(EventHandler& eventHandler);
  void HandleFlowMap(EventHandler& eventHandler);
  void HandleCompactMap(EventHandler& eventHandler);
  void HandleCompactMapWithNoKey(EventHandler& eventHandler);

  void ParseProperties(std::string& tag, anchor_t& anchor,
                       std::string& anchor_name);
  void ParseTag(std::string& tag);
  void ParseAnchor(anchor_t& anchor, std::string& anchor_name);

  anchor_t RegisterAnchor(const std::string& name);
  anchor_t LookupAnchor(const Mark& mark, const std::string& name) const;

 private:
  int depth = 0;
  Scanner& m_scanner;
  const Directives& m_directives;
  std::unique_ptr<CollectionStack> m_pCollectionStack;

  using Anchors = std::map<std::string, anchor_t>;
  Anchors m_anchors;

  anchor_t m_curAnchor;
};
}  // namespace YAML

#endif  // SINGLEDOCPARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/singledocparser.h ======

// Expanding include: token.h
// Expanding include: yaml-cpp/exceptions.h
// Expanding include: yaml-cpp/parser.h

namespace YAML {
class EventHandler;

Parser::Parser() : m_pScanner{}, m_pDirectives{} {}

Parser::Parser(std::istream& in) : Parser() { Load(in); }

Parser::~Parser() = default;

Parser::operator bool() const { return m_pScanner && !m_pScanner->empty(); }

void Parser::Load(std::istream& in) {
  m_pScanner.reset(new Scanner(in));
  m_pDirectives.reset(new Directives);
}

bool Parser::HandleNextDocument(EventHandler& eventHandler) {
  if (!m_pScanner)
    return false;

  ParseDirectives();
  if (m_pScanner->empty()) {
    return false;
  }

  SingleDocParser sdp(*m_pScanner, *m_pDirectives);
  sdp.HandleDocument(eventHandler);
  return true;
}

void Parser::ParseDirectives() {
  bool readDirective = false;

  while (!m_pScanner->empty()) {
    Token& token = m_pScanner->peek();
    if (token.type != Token::DIRECTIVE) {
      break;
    }

    // we keep the directives from the last document if none are specified;
    // but if any directives are specific, then we reset them
    if (!readDirective) {
      m_pDirectives.reset(new Directives);
    }

    readDirective = true;
    HandleDirective(token);
    m_pScanner->pop();
  }
}

void Parser::HandleDirective(const Token& token) {
  if (token.value == "YAML") {
    HandleYamlDirective(token);
  } else if (token.value == "TAG") {
    HandleTagDirective(token);
  }
}

void Parser::HandleYamlDirective(const Token& token) {
  if (token.params.size() != 1) {
    throw ParserException(token.mark, ErrorMsg::YAML_DIRECTIVE_ARGS);
  }

  if (!m_pDirectives->version.isDefault) {
    throw ParserException(token.mark, ErrorMsg::REPEATED_YAML_DIRECTIVE);
  }

  std::stringstream str(token.params[0]);
  str.imbue(std::locale("C"));
  str >> m_pDirectives->version.major;
  str.get();
  str >> m_pDirectives->version.minor;
  if (!str || str.peek() != EOF) {
    throw ParserException(
        token.mark, std::string(ErrorMsg::YAML_VERSION) + token.params[0]);
  }

  if (m_pDirectives->version.major > 1) {
    throw ParserException(token.mark, ErrorMsg::YAML_MAJOR_VERSION);
  }

  m_pDirectives->version.isDefault = false;
  // TODO: warning on major == 1, minor > 2?
}

void Parser::HandleTagDirective(const Token& token) {
  if (token.params.size() != 2)
    throw ParserException(token.mark, ErrorMsg::TAG_DIRECTIVE_ARGS);

  const std::string& handle = token.params[0];
  const std::string& prefix = token.params[1];
  if (m_pDirectives->tags.find(handle) != m_pDirectives->tags.end()) {
    throw ParserException(token.mark, ErrorMsg::REPEATED_TAG_DIRECTIVE);
  }

  m_pDirectives->tags[handle] = prefix;
}

void Parser::PrintTokens(std::ostream& out) {
  if (!m_pScanner) {
    return;
  }

  while (!m_pScanner->empty()) {
    out << m_pScanner->peek() << "\n";
    m_pScanner->pop();
  }
}
}  // namespace YAML
// ====== END yaml-cpp/src/parser.cpp ======


// ====== BEGIN yaml-cpp/src/regex_yaml.cpp ======
// Expanding include: regex_yaml.h

namespace YAML {
// constructors

RegEx::RegEx(REGEX_OP op) : m_op(op), m_a(0), m_z(0), m_params{} {}
RegEx::RegEx() : RegEx(REGEX_EMPTY) {}

RegEx::RegEx(char ch) : m_op(REGEX_MATCH), m_a(ch), m_z(0), m_params{} {}

RegEx::RegEx(char a, char z) : m_op(REGEX_RANGE), m_a(a), m_z(z), m_params{} {}

RegEx::RegEx(const std::string& str, REGEX_OP op)
    : m_op(op), m_a(0), m_z(0), m_params(str.begin(), str.end()) {}

// combination constructors
RegEx operator!(const RegEx& ex) {
  RegEx ret(REGEX_NOT);
  ret.m_params.push_back(ex);
  return ret;
}

RegEx operator|(const RegEx& ex1, const RegEx& ex2) {
  RegEx ret(REGEX_OR);
  ret.m_params.push_back(ex1);
  ret.m_params.push_back(ex2);
  return ret;
}

RegEx operator&(const RegEx& ex1, const RegEx& ex2) {
  RegEx ret(REGEX_AND);
  ret.m_params.push_back(ex1);
  ret.m_params.push_back(ex2);
  return ret;
}

RegEx operator+(const RegEx& ex1, const RegEx& ex2) {
  RegEx ret(REGEX_SEQ);
  ret.m_params.push_back(ex1);
  ret.m_params.push_back(ex2);
  return ret;
}
}  // namespace YAML
// ====== END yaml-cpp/src/regex_yaml.cpp ======


// ====== BEGIN yaml-cpp/src/scanner.cpp ======
#include <cassert>
#include <memory>

// Expanding include: exp.h
// Expanding include: scanner.h
// Expanding include: token.h
// Expanding include: yaml-cpp/exceptions.h

namespace YAML {
Scanner::Scanner(std::istream& in)
    : INPUT(in),
      m_tokens{},
      m_startedStream(false),
      m_endedStream(false),
      m_simpleKeyAllowed(false),
      m_scalarValueAllowed(false),
      m_canBeJSONFlow(false),
      m_simpleKeys{},
      m_indents{},
      m_indentRefs{},
      m_flows{} {}

Scanner::~Scanner() = default;

bool Scanner::empty() {
  EnsureTokensInQueue();
  return m_tokens.empty();
}

void Scanner::pop() {
  EnsureTokensInQueue();
  if (!m_tokens.empty())
    m_tokens.pop();
}

Token& Scanner::peek() {
  EnsureTokensInQueue();
  assert(!m_tokens.empty());  // should we be asserting here? I mean, we really
                              // just be checking
                              // if it's empty before peeking.

#if 0
		static Token *pLast = 0;
		if(pLast != &m_tokens.front())
			std::cerr << "peek: " << m_tokens.front() << "\n";
		pLast = &m_tokens.front();
#endif

  return m_tokens.front();
}

Mark Scanner::mark() const { return INPUT.mark(); }

void Scanner::EnsureTokensInQueue() {
  while (true) {
    if (!m_tokens.empty()) {
      Token& token = m_tokens.front();

      // if this guy's valid, then we're done
      if (token.status == Token::VALID) {
        return;
      }

      // here's where we clean up the impossible tokens
      if (token.status == Token::INVALID) {
        m_tokens.pop();
        continue;
      }

      // note: what's left are the unverified tokens
    }

    // no token? maybe we've actually finished
    if (m_endedStream) {
      return;
    }

    // no? then scan...
    ScanNextToken();
  }
}

void Scanner::ScanNextToken() {
  if (m_endedStream) {
    return;
  }

  if (!m_startedStream) {
    return StartStream();
  }

  // get rid of whitespace, etc. (in between tokens it should be irrelevant)
  ScanToNextToken();

  // maybe need to end some blocks
  PopIndentToHere();

  // *****
  // And now branch based on the next few characters!
  // *****

  // end of stream
  if (!INPUT) {
    return EndStream();
  }

  if (INPUT.column() == 0 && INPUT.peek() == Keys::Directive) {
    return ScanDirective();
  }

  // document token
  if (INPUT.column() == 0 && Exp::DocStart().Matches(INPUT)) {
    return ScanDocStart();
  }

  if (INPUT.column() == 0 && Exp::DocEnd().Matches(INPUT)) {
    return ScanDocEnd();
  }

  // flow start/end/entry
  if (INPUT.peek() == Keys::FlowSeqStart ||
      INPUT.peek() == Keys::FlowMapStart) {
    return ScanFlowStart();
  }

  if (INPUT.peek() == Keys::FlowSeqEnd || INPUT.peek() == Keys::FlowMapEnd) {
    return ScanFlowEnd();
  }

  if (INPUT.peek() == Keys::FlowEntry) {
    // values starting with `,` are not allowed.
    // eg: reject `,foo`
    if (INPUT.column() == 0) {
      throw ParserException(INPUT.mark(), ErrorMsg::UNEXPECTED_FLOW);
    }
    // if we already parsed a quoted scalar value and we are not in a flow,
    // then `,` is not a valid character.
    // eg: reject `"foo",`
    if (!m_scalarValueAllowed) {
      throw ParserException(INPUT.mark(), ErrorMsg::UNEXPECTED_SCALAR);
    }
    return ScanFlowEntry();
  }

  // block/map stuff
  if (Exp::BlockEntry().Matches(INPUT)) {
    return ScanBlockEntry();
  }

  if ((InBlockContext() ? Exp::Key() : Exp::KeyInFlow()).Matches(INPUT)) {
    return ScanKey();
  }

  if (GetValueRegex().Matches(INPUT)) {
    return ScanValue();
  }

  // alias/anchor
  if (INPUT.peek() == Keys::Alias || INPUT.peek() == Keys::Anchor) {
    return ScanAnchorOrAlias();
  }

  // tag
  if (INPUT.peek() == Keys::Tag) {
    return ScanTag();
  }

  // special scalars
  if (InBlockContext() && (INPUT.peek() == Keys::LiteralScalar ||
                           INPUT.peek() == Keys::FoldedScalar)) {
    return ScanBlockScalar();
  }

  // if we already parsed a quoted scalar value in this line,
  // another scalar value is an error.
  // eg: reject `"foo" "bar"`
  if (!m_scalarValueAllowed) {
    throw ParserException(INPUT.mark(), ErrorMsg::UNEXPECTED_SCALAR);
  }

  if (INPUT.peek() == '\'' || INPUT.peek() == '\"') {
    return ScanQuotedScalar();
  }

  // plain scalars
  if ((InBlockContext() ? Exp::PlainScalar() : Exp::PlainScalarInFlow())
          .Matches(INPUT)) {
    return ScanPlainScalar();
  }

  // don't know what it is!
  throw ParserException(INPUT.mark(), ErrorMsg::UNKNOWN_TOKEN);
}

void Scanner::ScanToNextToken() {
  while (true) {
    // first eat whitespace
    while (INPUT && IsWhitespaceToBeEaten(INPUT.peek())) {
      if (InBlockContext() && Exp::Tab().Matches(INPUT)) {
        m_simpleKeyAllowed = false;
      }
      INPUT.eat(1);
    }

    // then eat a comment
    if (Exp::Comment().Matches(INPUT)) {
      // eat until line break
      while (INPUT && !Exp::Break().Matches(INPUT)) {
        INPUT.eat(1);
      }
    }

    // if it's NOT a line break, then we're done!
    if (!Exp::Break().Matches(INPUT)) {
      break;
    }

    // otherwise, let's eat the line break and keep going
    int n = Exp::Break().Match(INPUT);
    INPUT.eat(n);

    // oh yeah, and let's get rid of that simple key
    InvalidateSimpleKey();

    // new line - we accept a scalar value now
    m_scalarValueAllowed = true;

    // new line - we may be able to accept a simple key now
    if (InBlockContext()) {
      m_simpleKeyAllowed = true;
    }
  }
}

///////////////////////////////////////////////////////////////////////
// Misc. helpers

// IsWhitespaceToBeEaten
// . We can eat whitespace if it's a space or tab
// . Note: originally tabs in block context couldn't be eaten
//         "where a simple key could be allowed
//         (i.e., not at the beginning of a line, or following '-', '?', or
// ':')"
//   I think this is wrong, since tabs can be non-content whitespace; it's just
//   that they can't contribute to indentation, so once you've seen a tab in a
//   line, you can't start a simple key
bool Scanner::IsWhitespaceToBeEaten(char ch) {
  if (ch == ' ') {
    return true;
  }

  if (ch == '\t') {
    return true;
  }

  return false;
}

const RegEx& Scanner::GetValueRegex() const {
  if (InBlockContext()) {
    return Exp::Value();
  }

  return m_canBeJSONFlow ? Exp::ValueInJSONFlow() : Exp::ValueInFlow();
}

void Scanner::StartStream() {
  m_startedStream = true;
  m_simpleKeyAllowed = true;
  m_scalarValueAllowed = true;
  std::unique_ptr<IndentMarker> pIndent(
      new IndentMarker(-1, IndentMarker::NONE));
  m_indentRefs.push_back(std::move(pIndent));
  m_indents.push(&m_indentRefs.back());
}

void Scanner::EndStream() {
  // force newline
  if (INPUT.column() > 0) {
    INPUT.ResetColumn();
  }

  PopAllIndents();
  PopAllSimpleKeys();

  m_simpleKeyAllowed = false;
  m_scalarValueAllowed = false;
  m_endedStream = true;
}

Token* Scanner::PushToken(Token::TYPE type) {
  m_tokens.push(Token(type, INPUT.mark()));
  return &m_tokens.back();
}

Token::TYPE Scanner::GetStartTokenFor(IndentMarker::INDENT_TYPE type) const {
  switch (type) {
    case IndentMarker::SEQ:
      return Token::BLOCK_SEQ_START;
    case IndentMarker::MAP:
      return Token::BLOCK_MAP_START;
    case IndentMarker::NONE:
      assert(false);
      break;
  }
  assert(false);
  throw std::runtime_error("yaml-cpp: internal error, invalid indent type");
}

Scanner::IndentMarker* Scanner::PushIndentTo(int column,
                                             IndentMarker::INDENT_TYPE type) {
  // are we in flow?
  if (InFlowContext()) {
    return nullptr;
  }

  std::unique_ptr<IndentMarker> pIndent(new IndentMarker(column, type));
  IndentMarker& indent = *pIndent;
  const IndentMarker& lastIndent = *m_indents.top();

  // is this actually an indentation?
  if (indent.column < lastIndent.column) {
    return nullptr;
  }
  if (indent.column == lastIndent.column &&
      !(indent.type == IndentMarker::SEQ &&
        lastIndent.type == IndentMarker::MAP)) {
    return nullptr;
  }

  // push a start token
  indent.pStartToken = PushToken(GetStartTokenFor(type));

  // and then the indent
  m_indents.push(&indent);
  m_indentRefs.push_back(std::move(pIndent));
  return &m_indentRefs.back();
}

void Scanner::PopIndentToHere() {
  // are we in flow?
  if (InFlowContext()) {
    return;
  }

  // now pop away
  while (!m_indents.empty()) {
    const IndentMarker& indent = *m_indents.top();
    if (indent.column < INPUT.column()) {
      break;
    }
    if (indent.column == INPUT.column() &&
        !(indent.type == IndentMarker::SEQ &&
          !Exp::BlockEntry().Matches(INPUT))) {
      break;
    }

    PopIndent();
  }

  while (!m_indents.empty() &&
         m_indents.top()->status == IndentMarker::INVALID) {
    PopIndent();
  }
}

void Scanner::PopAllIndents() {
  // are we in flow?
  if (InFlowContext()) {
    return;
  }

  // now pop away
  while (!m_indents.empty()) {
    const IndentMarker& indent = *m_indents.top();
    if (indent.type == IndentMarker::NONE) {
      break;
    }

    PopIndent();
  }
}

void Scanner::PopIndent() {
  const IndentMarker& indent = *m_indents.top();
  m_indents.pop();

  if (indent.status != IndentMarker::VALID) {
    InvalidateSimpleKey();
    return;
  }

  if (indent.type == IndentMarker::SEQ) {
    m_tokens.push(Token(Token::BLOCK_SEQ_END, INPUT.mark()));
  } else if (indent.type == IndentMarker::MAP) {
    m_tokens.push(Token(Token::BLOCK_MAP_END, INPUT.mark()));
  }
}

int Scanner::GetTopIndent() const {
  if (m_indents.empty()) {
    return 0;
  }
  return m_indents.top()->column;
}

void Scanner::ThrowParserException(const std::string& msg) const {
  Mark mark = Mark::null_mark();
  if (!m_tokens.empty()) {
    const Token& token = m_tokens.front();
    mark = token.mark;
  }
  throw ParserException(mark, msg);
}
}  // namespace YAML
// ====== END yaml-cpp/src/scanner.cpp ======


// ====== BEGIN yaml-cpp/src/scanscalar.cpp ======
// Expanding include: scanscalar.h

// ====== BEGIN yaml-cpp/src/scanscalar.h ======
#ifndef SCANSCALAR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define SCANSCALAR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>

// Expanding include: regex_yaml.h
// Expanding include: stream.h

namespace YAML {
enum CHOMP { STRIP = -1, CLIP, KEEP };
enum ACTION { NONE, BREAK, THROW };
enum FOLD { DONT_FOLD, FOLD_BLOCK, FOLD_FLOW };

struct ScanScalarParams {
  ScanScalarParams()
      : end(nullptr),
        eatEnd(false),
        indent(0),
        detectIndent(false),
        eatLeadingWhitespace(0),
        escape(0),
        fold(DONT_FOLD),
        trimTrailingSpaces(0),
        chomp(CLIP),
        onDocIndicator(NONE),
        onTabInIndentation(NONE),
        leadingSpaces(false) {}

  // input:
  const RegEx* end;   // what condition ends this scalar?
                      // unowned.
  bool eatEnd;        // should we eat that condition when we see it?
  int indent;         // what level of indentation should be eaten and ignored?
  bool detectIndent;  // should we try to autodetect the indent?
  bool eatLeadingWhitespace;  // should we continue eating this delicious
                              // indentation after 'indent' spaces?
  char escape;  // what character do we escape on (i.e., slash or single quote)
                // (0 for none)
  FOLD fold;    // how do we fold line ends?
  bool trimTrailingSpaces;  // do we remove all trailing spaces (at the very
                            // end)
  CHOMP chomp;  // do we strip, clip, or keep trailing newlines (at the very
                // end)
  //   Note: strip means kill all, clip means keep at most one, keep means keep
  // all
  ACTION onDocIndicator;      // what do we do if we see a document indicator?
  ACTION onTabInIndentation;  // what do we do if we see a tab where we should
                              // be seeing indentation spaces

  // output:
  bool leadingSpaces;
};

std::string ScanScalar(Stream& INPUT, ScanScalarParams& params);
}

#endif  // SCANSCALAR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/scanscalar.h ======


#include <algorithm>

// Expanding include: exp.h
// Expanding include: regeximpl.h
// Expanding include: stream.h
// Expanding include: yaml-cpp/exceptions.h

namespace YAML {
// ScanScalar
// . This is where the scalar magic happens.
//
// . We do the scanning in three phases:
//   1. Scan until newline
//   2. Eat newline
//   3. Scan leading blanks.
//
// . Depending on the parameters given, we store or stop
//   and different places in the above flow.
std::string ScanScalar(Stream& INPUT, ScanScalarParams& params) {
  bool foundNonEmptyLine = false;
  bool pastOpeningBreak = (params.fold == FOLD_FLOW);
  bool emptyLine = false, moreIndented = false;
  int foldedNewlineCount = 0;
  bool foldedNewlineStartedMoreIndented = false;
  std::size_t lastEscapedChar = std::string::npos;
  std::string scalar;
  params.leadingSpaces = false;

  if (!params.end) {
    params.end = &Exp::Empty();
  }

  while (INPUT) {
    // ********************************
    // Phase #1: scan until line ending

    std::size_t lastNonWhitespaceChar = scalar.size();
    bool escapedNewline = false;
    while (!params.end->Matches(INPUT) && !Exp::Break().Matches(INPUT)) {
      if (!INPUT) {
        break;
      }

      // document indicator?
      if (INPUT.column() == 0 && Exp::DocIndicator().Matches(INPUT)) {
        if (params.onDocIndicator == BREAK) {
          break;
        }
        if (params.onDocIndicator == THROW) {
          throw ParserException(INPUT.mark(), ErrorMsg::DOC_IN_SCALAR);
        }
      }

      foundNonEmptyLine = true;
      pastOpeningBreak = true;

      // escaped newline? (only if we're escaping on slash)
      if (params.escape == '\\' && Exp::EscBreak().Matches(INPUT)) {
        // eat escape character and get out (but preserve trailing whitespace!)
        INPUT.get();
        lastNonWhitespaceChar = scalar.size();
        lastEscapedChar = scalar.size();
        escapedNewline = true;
        break;
      }

      // escape this?
      if (INPUT.peek() == params.escape) {
        scalar += Exp::Escape(INPUT);
        lastNonWhitespaceChar = scalar.size();
        lastEscapedChar = scalar.size();
        continue;
      }

      // otherwise, just add the damn character
      char ch = INPUT.get();
      scalar += ch;
      if (ch != ' ' && ch != '\t') {
        lastNonWhitespaceChar = scalar.size();
      }
    }

    // eof? if we're looking to eat something, then we throw
    if (!INPUT) {
      if (params.eatEnd) {
        throw ParserException(INPUT.mark(), ErrorMsg::EOF_IN_SCALAR);
      }
      break;
    }

    // doc indicator?
    if (params.onDocIndicator == BREAK && INPUT.column() == 0 &&
        Exp::DocIndicator().Matches(INPUT)) {
      break;
    }

    // are we done via character match?
    int n = params.end->Match(INPUT);
    if (n >= 0) {
      if (params.eatEnd) {
        INPUT.eat(n);
      }
      break;
    }

    // do we remove trailing whitespace?
    if (params.fold == FOLD_FLOW)
      scalar.erase(lastNonWhitespaceChar);

    // ********************************
    // Phase #2: eat line ending
    n = Exp::Break().Match(INPUT);
    INPUT.eat(n);

    // ********************************
    // Phase #3: scan initial spaces

    // first the required indentation
    while (INPUT.peek() == ' ' &&
           (INPUT.column() < params.indent ||
            (params.detectIndent && !foundNonEmptyLine)) &&
           !params.end->Matches(INPUT)) {
      INPUT.eat(1);
    }

    // update indent if we're auto-detecting
    if (params.detectIndent && !foundNonEmptyLine) {
      params.indent = std::max(params.indent, INPUT.column());
    }

    // and then the rest of the whitespace
    while (Exp::Blank().Matches(INPUT)) {
      // we check for tabs that masquerade as indentation
      if (INPUT.peek() == '\t' && INPUT.column() < params.indent &&
          params.onTabInIndentation == THROW) {
        throw ParserException(INPUT.mark(), ErrorMsg::TAB_IN_INDENTATION);
      }

      if (!params.eatLeadingWhitespace) {
        break;
      }

      if (params.end->Matches(INPUT)) {
        break;
      }

      INPUT.eat(1);
    }

    // was this an empty line?
    bool nextEmptyLine = Exp::Break().Matches(INPUT);
    bool nextMoreIndented = Exp::Blank().Matches(INPUT);
    if (params.fold == FOLD_BLOCK && foldedNewlineCount == 0 && nextEmptyLine)
      foldedNewlineStartedMoreIndented = moreIndented;

    // for block scalars, we always start with a newline, so we should ignore it
    // (not fold or keep)
    if (pastOpeningBreak) {
      switch (params.fold) {
        case DONT_FOLD:
          scalar += "\n";
          break;
        case FOLD_BLOCK:
          if (!emptyLine && !nextEmptyLine && !moreIndented &&
              !nextMoreIndented && INPUT.column() >= params.indent) {
            scalar += " ";
          } else if (nextEmptyLine) {
            foldedNewlineCount++;
          } else {
            scalar += "\n";
          }

          if (!nextEmptyLine && foldedNewlineCount > 0) {
            scalar += std::string(foldedNewlineCount - 1, '\n');
            if (foldedNewlineStartedMoreIndented ||
                nextMoreIndented | !foundNonEmptyLine) {
              scalar += "\n";
            }
            foldedNewlineCount = 0;
          }
          break;
        case FOLD_FLOW:
          if (nextEmptyLine) {
            scalar += "\n";
          } else if (!emptyLine && !escapedNewline) {
            scalar += " ";
          }
          break;
      }
    }

    emptyLine = nextEmptyLine;
    moreIndented = nextMoreIndented;
    pastOpeningBreak = true;

    // are we done via indentation?
    if (!emptyLine && INPUT.column() < params.indent) {
      params.leadingSpaces = true;
      break;
    }
  }

  // post-processing
  if (params.trimTrailingSpaces) {
    std::size_t pos = scalar.find_last_not_of(" \t");
    if (lastEscapedChar != std::string::npos) {
      if (pos < lastEscapedChar || pos == std::string::npos) {
        pos = lastEscapedChar;
      }
    }
    if (pos < scalar.size()) {
      scalar.erase(pos + 1);
    }
  }

  switch (params.chomp) {
    case CLIP: {
      std::size_t pos = scalar.find_last_not_of('\n');
      if (lastEscapedChar != std::string::npos) {
        if (pos < lastEscapedChar || pos == std::string::npos) {
          pos = lastEscapedChar;
        }
      }
      if (pos == std::string::npos) {
        scalar.erase();
      } else if (pos + 1 < scalar.size()) {
        scalar.erase(pos + 2);
      }
    } break;
    case STRIP: {
      std::size_t pos = scalar.find_last_not_of('\n');
      if (lastEscapedChar != std::string::npos) {
        if (pos < lastEscapedChar || pos == std::string::npos) {
          pos = lastEscapedChar;
        }
      }
      if (pos == std::string::npos) {
        scalar.erase();
      } else if (pos < scalar.size()) {
        scalar.erase(pos + 1);
      }
    } break;
    default:
      break;
  }

  return scalar;
}
}  // namespace YAML
// ====== END yaml-cpp/src/scanscalar.cpp ======


// ====== BEGIN yaml-cpp/src/scantag.cpp ======
// Expanding include: exp.h
// Expanding include: regex_yaml.h
// Expanding include: regeximpl.h
// Expanding include: stream.h
// Expanding include: yaml-cpp/exceptions.h
// Expanding include: yaml-cpp/mark.h

namespace YAML {
const std::string ScanVerbatimTag(Stream& INPUT) {
  std::string tag;

  // eat the start character
  INPUT.get();

  while (INPUT) {
    if (INPUT.peek() == Keys::VerbatimTagEnd) {
      // eat the end character
      INPUT.get();
      return tag;
    }

    int n = Exp::URI().Match(INPUT);
    if (n <= 0)
      break;

    tag += INPUT.get(n);
  }

  throw ParserException(INPUT.mark(), ErrorMsg::END_OF_VERBATIM_TAG);
}

const std::string ScanTagHandle(Stream& INPUT, bool& canBeHandle) {
  std::string tag;
  canBeHandle = true;
  Mark firstNonWordChar;

  while (INPUT) {
    if (INPUT.peek() == Keys::Tag) {
      if (!canBeHandle)
        throw ParserException(firstNonWordChar, ErrorMsg::CHAR_IN_TAG_HANDLE);
      break;
    }

    int n = 0;
    if (canBeHandle) {
      n = Exp::Word().Match(INPUT);
      if (n <= 0) {
        canBeHandle = false;
        firstNonWordChar = INPUT.mark();
      }
    }

    if (!canBeHandle)
      n = Exp::Tag().Match(INPUT);

    if (n <= 0)
      break;

    tag += INPUT.get(n);
  }

  return tag;
}

const std::string ScanTagSuffix(Stream& INPUT) {
  std::string tag;

  while (INPUT) {
    int n = Exp::Tag().Match(INPUT);
    if (n <= 0)
      break;

    tag += INPUT.get(n);
  }

  if (tag.empty())
    throw ParserException(INPUT.mark(), ErrorMsg::TAG_WITH_NO_SUFFIX);

  return tag;
}
}  // namespace YAML
// ====== END yaml-cpp/src/scantag.cpp ======


// ====== BEGIN yaml-cpp/src/scantoken.cpp ======
#include <sstream>

// Expanding include: exp.h
// Expanding include: regex_yaml.h
// Expanding include: regeximpl.h
// Expanding include: scanner.h
// Expanding include: scanscalar.h
// Expanding include: scantag.h

// ====== BEGIN yaml-cpp/src/scantag.h ======
#ifndef SCANTAG_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define SCANTAG_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>
// Expanding include: stream.h

namespace YAML {
const std::string ScanVerbatimTag(Stream& INPUT);
const std::string ScanTagHandle(Stream& INPUT, bool& canBeHandle);
const std::string ScanTagSuffix(Stream& INPUT);
}

#endif  // SCANTAG_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/scantag.h ======

// Expanding include: tag.h

// ====== BEGIN yaml-cpp/src/tag.h ======
#ifndef TAG_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define TAG_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>

namespace YAML {
struct Directives;
struct Token;

struct Tag {
  enum TYPE {
    VERBATIM,
    PRIMARY_HANDLE,
    SECONDARY_HANDLE,
    NAMED_HANDLE,
    NON_SPECIFIC
  };

  Tag(const Token& token);
  std::string Translate(const Directives& directives);

  TYPE type;
  std::string handle, value;
};
}

#endif  // TAG_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/tag.h ======

// Expanding include: token.h
// Expanding include: yaml-cpp/exceptions.h
// Expanding include: yaml-cpp/mark.h

namespace YAML {
///////////////////////////////////////////////////////////////////////
// Specialization for scanning specific tokens

// Directive
// . Note: no semantic checking is done here (that's for the parser to do)
void Scanner::ScanDirective() {
  std::string name;
  std::vector<std::string> params;

  // pop indents and simple keys
  PopAllIndents();
  PopAllSimpleKeys();

  m_simpleKeyAllowed = false;
  m_canBeJSONFlow = false;

  // store pos and eat indicator
  Token token(Token::DIRECTIVE, INPUT.mark());
  INPUT.eat(1);

  // read name
  while (INPUT && !Exp::BlankOrBreak().Matches(INPUT))
    token.value += INPUT.get();

  // read parameters
  while (true) {
    // first get rid of whitespace
    while (Exp::Blank().Matches(INPUT))
      INPUT.eat(1);

    // break on newline or comment
    if (!INPUT || Exp::Break().Matches(INPUT) || Exp::Comment().Matches(INPUT))
      break;

    // now read parameter
    std::string param;
    while (INPUT && !Exp::BlankOrBreak().Matches(INPUT))
      param += INPUT.get();

    token.params.push_back(param);
  }

  m_tokens.push(token);
}

// DocStart
void Scanner::ScanDocStart() {
  PopAllIndents();
  PopAllSimpleKeys();
  m_simpleKeyAllowed = false;
  m_canBeJSONFlow = false;

  // eat
  Mark mark = INPUT.mark();
  INPUT.eat(3);
  m_tokens.push(Token(Token::DOC_START, mark));
}

// DocEnd
void Scanner::ScanDocEnd() {
  PopAllIndents();
  PopAllSimpleKeys();
  m_simpleKeyAllowed = false;
  m_canBeJSONFlow = false;

  // eat
  Mark mark = INPUT.mark();
  INPUT.eat(3);
  m_tokens.push(Token(Token::DOC_END, mark));
}

// FlowStart
void Scanner::ScanFlowStart() {
  // flows can be simple keys
  InsertPotentialSimpleKey();
  m_simpleKeyAllowed = true;
  m_canBeJSONFlow = false;

  // eat
  Mark mark = INPUT.mark();
  char ch = INPUT.get();
  FLOW_MARKER flowType = (ch == Keys::FlowSeqStart ? FLOW_SEQ : FLOW_MAP);
  m_flows.push(flowType);
  Token::TYPE type =
      (flowType == FLOW_SEQ ? Token::FLOW_SEQ_START : Token::FLOW_MAP_START);
  m_tokens.push(Token(type, mark));
}

// FlowEnd
void Scanner::ScanFlowEnd() {
  if (InBlockContext())
    throw ParserException(INPUT.mark(), ErrorMsg::FLOW_END);

  // we might have a solo entry in the flow context
  if (InFlowContext()) {
    if (m_flows.top() == FLOW_MAP && VerifySimpleKey())
      m_tokens.push(Token(Token::VALUE, INPUT.mark()));
    else if (m_flows.top() == FLOW_SEQ)
      InvalidateSimpleKey();
  }

  m_simpleKeyAllowed = false;
  m_canBeJSONFlow = true;

  // eat
  Mark mark = INPUT.mark();
  char ch = INPUT.get();

  // check that it matches the start
  FLOW_MARKER flowType = (ch == Keys::FlowSeqEnd ? FLOW_SEQ : FLOW_MAP);
  if (m_flows.top() != flowType)
    throw ParserException(mark, ErrorMsg::FLOW_END);
  m_flows.pop();

  Token::TYPE type = (flowType ? Token::FLOW_SEQ_END : Token::FLOW_MAP_END);
  m_tokens.push(Token(type, mark));
}

// FlowEntry
void Scanner::ScanFlowEntry() {
  // we might have a solo entry in the flow context
  if (InFlowContext()) {
    if (m_flows.top() == FLOW_MAP && VerifySimpleKey())
      m_tokens.push(Token(Token::VALUE, INPUT.mark()));
    else if (m_flows.top() == FLOW_SEQ)
      InvalidateSimpleKey();
  }

  m_simpleKeyAllowed = true;
  m_canBeJSONFlow = false;

  // eat
  Mark mark = INPUT.mark();
  INPUT.eat(1);
  m_tokens.push(Token(Token::FLOW_ENTRY, mark));
}

// BlockEntry
void Scanner::ScanBlockEntry() {
  // we better be in the block context!
  if (InFlowContext())
    throw ParserException(INPUT.mark(), ErrorMsg::BLOCK_ENTRY);

  // can we put it here?
  if (!m_simpleKeyAllowed)
    throw ParserException(INPUT.mark(), ErrorMsg::BLOCK_ENTRY);

  PushIndentTo(INPUT.column(), IndentMarker::SEQ);
  m_simpleKeyAllowed = true;
  m_canBeJSONFlow = false;

  // eat
  Mark mark = INPUT.mark();
  INPUT.eat(1);
  m_tokens.push(Token(Token::BLOCK_ENTRY, mark));
}

// Key
void Scanner::ScanKey() {
  // handle keys differently in the block context (and manage indents)
  if (InBlockContext()) {
    if (!m_simpleKeyAllowed)
      throw ParserException(INPUT.mark(), ErrorMsg::MAP_KEY);

    PushIndentTo(INPUT.column(), IndentMarker::MAP);
  }

  // can only put a simple key here if we're in block context
  m_simpleKeyAllowed = InBlockContext();

  // eat
  Mark mark = INPUT.mark();
  INPUT.eat(1);
  m_tokens.push(Token(Token::KEY, mark));
}

// Value
void Scanner::ScanValue() {
  // and check that simple key
  bool isSimpleKey = VerifySimpleKey();
  m_canBeJSONFlow = false;

  if (isSimpleKey) {
    // can't follow a simple key with another simple key (dunno why, though - it
    // seems fine)
    m_simpleKeyAllowed = false;
  } else {
    // handle values differently in the block context (and manage indents)
    if (InBlockContext()) {
      if (!m_simpleKeyAllowed)
        throw ParserException(INPUT.mark(), ErrorMsg::MAP_VALUE);

      PushIndentTo(INPUT.column(), IndentMarker::MAP);
    }

    // can only put a simple key here if we're in block context
    m_simpleKeyAllowed = InBlockContext();
  }

  // we are parsing a `key: value` pair; scalars are always allowed
  m_scalarValueAllowed = true;

  // eat
  Mark mark = INPUT.mark();
  INPUT.eat(1);
  m_tokens.push(Token(Token::VALUE, mark));
}

// AnchorOrAlias
void Scanner::ScanAnchorOrAlias() {
  bool alias;
  std::string name;

  // insert a potential simple key
  InsertPotentialSimpleKey();
  m_simpleKeyAllowed = false;
  m_canBeJSONFlow = false;

  // eat the indicator
  Mark mark = INPUT.mark();
  char indicator = INPUT.get();
  alias = (indicator == Keys::Alias);

  // now eat the content
  while (INPUT && Exp::Anchor().Matches(INPUT))
    name += INPUT.get();

  // we need to have read SOMETHING!
  if (name.empty())
    throw ParserException(INPUT.mark(), alias ? ErrorMsg::ALIAS_NOT_FOUND
                                              : ErrorMsg::ANCHOR_NOT_FOUND);

  // and needs to end correctly
  if (INPUT && !Exp::AnchorEnd().Matches(INPUT))
    throw ParserException(INPUT.mark(), alias ? ErrorMsg::CHAR_IN_ALIAS
                                              : ErrorMsg::CHAR_IN_ANCHOR);

  // and we're done
  Token token(alias ? Token::ALIAS : Token::ANCHOR, mark);
  token.value = name;
  m_tokens.push(token);
}

// Tag
void Scanner::ScanTag() {
  // insert a potential simple key
  InsertPotentialSimpleKey();
  m_simpleKeyAllowed = false;
  m_canBeJSONFlow = false;

  Token token(Token::TAG, INPUT.mark());

  // eat the indicator
  INPUT.get();

  if (INPUT && INPUT.peek() == Keys::VerbatimTagStart) {
    std::string tag = ScanVerbatimTag(INPUT);

    token.value = tag;
    token.data = Tag::VERBATIM;
  } else {
    bool canBeHandle;
    token.value = ScanTagHandle(INPUT, canBeHandle);
    if (!canBeHandle && token.value.empty())
      token.data = Tag::NON_SPECIFIC;
    else if (token.value.empty())
      token.data = Tag::SECONDARY_HANDLE;
    else
      token.data = Tag::PRIMARY_HANDLE;

    // is there a suffix?
    if (canBeHandle && INPUT.peek() == Keys::Tag) {
      // eat the indicator
      INPUT.get();
      token.params.push_back(ScanTagSuffix(INPUT));
      token.data = Tag::NAMED_HANDLE;
    }
  }

  m_tokens.push(token);
}

// PlainScalar
void Scanner::ScanPlainScalar() {
  std::string scalar;

  // set up the scanning parameters
  ScanScalarParams params;
  params.end =
      (InFlowContext() ? &Exp::ScanScalarEndInFlow() : &Exp::ScanScalarEnd());
  params.eatEnd = false;
  params.indent = (InFlowContext() ? 0 : GetTopIndent() + 1);
  params.fold = FOLD_FLOW;
  params.eatLeadingWhitespace = true;
  params.trimTrailingSpaces = true;
  params.chomp = STRIP;
  params.onDocIndicator = BREAK;
  params.onTabInIndentation = THROW;

  // insert a potential simple key
  InsertPotentialSimpleKey();

  Mark mark = INPUT.mark();
  scalar = ScanScalar(INPUT, params);

  // can have a simple key only if we ended the scalar by starting a new line
  m_simpleKeyAllowed = params.leadingSpaces;
  m_canBeJSONFlow = false;

  // finally, check and see if we ended on an illegal character
  // if(Exp::IllegalCharInScalar.Matches(INPUT))
  //	throw ParserException(INPUT.mark(), ErrorMsg::CHAR_IN_SCALAR);

  Token token(Token::PLAIN_SCALAR, mark);
  token.value = scalar;
  m_tokens.push(token);
}

// QuotedScalar
void Scanner::ScanQuotedScalar() {
  std::string scalar;

  // peek at single or double quote (don't eat because we need to preserve (for
  // the time being) the input position)
  char quote = INPUT.peek();
  bool single = (quote == '\'');

  // setup the scanning parameters
  ScanScalarParams params;
  RegEx end = (single ? RegEx(quote) & !Exp::EscSingleQuote() : RegEx(quote));
  params.end = &end;
  params.eatEnd = true;
  params.escape = (single ? '\'' : '\\');
  params.indent = 0;
  params.fold = FOLD_FLOW;
  params.eatLeadingWhitespace = true;
  params.trimTrailingSpaces = false;
  params.chomp = CLIP;
  params.onDocIndicator = THROW;

  // insert a potential simple key
  InsertPotentialSimpleKey();

  Mark mark = INPUT.mark();

  // now eat that opening quote
  INPUT.get();

  // and scan
  scalar = ScanScalar(INPUT, params);
  m_simpleKeyAllowed = false;
  // we just scanned a quoted scalar;
  // we can only have another scalar in this line
  // if we are in a flow, eg: `[ "foo", "bar" ]` is ok, but `"foo", "bar"` isn't.
  m_scalarValueAllowed = InFlowContext();
  m_canBeJSONFlow = true;

  Token token(Token::NON_PLAIN_SCALAR, mark);
  token.value = scalar;
  m_tokens.push(token);
}

// BlockScalarToken
// . These need a little extra processing beforehand.
// . We need to scan the line where the indicator is (this doesn't count as part
// of the scalar),
//   and then we need to figure out what level of indentation we'll be using.
void Scanner::ScanBlockScalar() {
  std::string scalar;

  ScanScalarParams params;
  params.indent = 1;
  params.detectIndent = true;

  // eat block indicator ('|' or '>')
  Mark mark = INPUT.mark();
  char indicator = INPUT.get();
  params.fold = (indicator == Keys::FoldedScalar ? FOLD_BLOCK : DONT_FOLD);

  // eat chomping/indentation indicators
  params.chomp = CLIP;
  int n = Exp::Chomp().Match(INPUT);
  for (int i = 0; i < n; i++) {
    char ch = INPUT.get();
    if (ch == '+')
      params.chomp = KEEP;
    else if (ch == '-')
      params.chomp = STRIP;
    else if (Exp::Digit().Matches(ch)) {
      if (ch == '0')
        throw ParserException(INPUT.mark(), ErrorMsg::ZERO_INDENT_IN_BLOCK);

      params.indent = ch - '0';
      params.detectIndent = false;
    }
  }

  // now eat whitespace
  while (Exp::Blank().Matches(INPUT))
    INPUT.eat(1);

  // and comments to the end of the line
  if (Exp::Comment().Matches(INPUT))
    while (INPUT && !Exp::Break().Matches(INPUT))
      INPUT.eat(1);

  // if it's not a line break, then we ran into a bad character inline
  if (INPUT && !Exp::Break().Matches(INPUT))
    throw ParserException(INPUT.mark(), ErrorMsg::CHAR_IN_BLOCK);

  // set the initial indentation
  if (GetTopIndent() >= 0)
    params.indent += GetTopIndent();

  params.eatLeadingWhitespace = false;
  params.trimTrailingSpaces = false;
  params.onTabInIndentation = THROW;

  scalar = ScanScalar(INPUT, params);

  // simple keys always ok after block scalars (since we're gonna start a new
  // line anyways)
  m_simpleKeyAllowed = true;
  m_canBeJSONFlow = false;

  Token token(Token::NON_PLAIN_SCALAR, mark);
  token.value = scalar;
  m_tokens.push(token);
}
}  // namespace YAML
// ====== END yaml-cpp/src/scantoken.cpp ======


// ====== BEGIN yaml-cpp/src/simplekey.cpp ======
// Expanding include: scanner.h
// Expanding include: token.h

namespace YAML {
struct Mark;

Scanner::SimpleKey::SimpleKey(const Mark& mark_, std::size_t flowLevel_)
    : mark(mark_),
      flowLevel(flowLevel_),
      pIndent(nullptr),
      pMapStart(nullptr),
      pKey(nullptr) {}

void Scanner::SimpleKey::Validate() {
  // Note: pIndent will *not* be garbage here;
  //       we "garbage collect" them so we can
  //       always refer to them
  if (pIndent)
    pIndent->status = IndentMarker::VALID;
  if (pMapStart)
    pMapStart->status = Token::VALID;
  if (pKey)
    pKey->status = Token::VALID;
}

void Scanner::SimpleKey::Invalidate() {
  if (pIndent)
    pIndent->status = IndentMarker::INVALID;
  if (pMapStart)
    pMapStart->status = Token::INVALID;
  if (pKey)
    pKey->status = Token::INVALID;
}

// CanInsertPotentialSimpleKey
bool Scanner::CanInsertPotentialSimpleKey() const {
  if (!m_simpleKeyAllowed)
    return false;

  return !ExistsActiveSimpleKey();
}

// ExistsActiveSimpleKey
// . Returns true if there's a potential simple key at our flow level
//   (there's allowed at most one per flow level, i.e., at the start of the flow
// start token)
bool Scanner::ExistsActiveSimpleKey() const {
  if (m_simpleKeys.empty())
    return false;

  const SimpleKey& key = m_simpleKeys.top();
  return key.flowLevel == GetFlowLevel();
}

// InsertPotentialSimpleKey
// . If we can, add a potential simple key to the queue,
//   and save it on a stack.
void Scanner::InsertPotentialSimpleKey() {
  if (!CanInsertPotentialSimpleKey())
    return;

  SimpleKey key(INPUT.mark(), GetFlowLevel());

  // first add a map start, if necessary
  if (InBlockContext()) {
    key.pIndent = PushIndentTo(INPUT.column(), IndentMarker::MAP);
    if (key.pIndent) {
      key.pIndent->status = IndentMarker::UNKNOWN;
      key.pMapStart = key.pIndent->pStartToken;
      key.pMapStart->status = Token::UNVERIFIED;
    }
  }

  // then add the (now unverified) key
  m_tokens.push(Token(Token::KEY, INPUT.mark()));
  key.pKey = &m_tokens.back();
  key.pKey->status = Token::UNVERIFIED;

  m_simpleKeys.push(key);
}

// InvalidateSimpleKey
// . Automatically invalidate the simple key in our flow level
void Scanner::InvalidateSimpleKey() {
  if (m_simpleKeys.empty())
    return;

  // grab top key
  SimpleKey& key = m_simpleKeys.top();
  if (key.flowLevel != GetFlowLevel())
    return;

  key.Invalidate();
  m_simpleKeys.pop();
}

// VerifySimpleKey
// . Determines whether the latest simple key to be added is valid,
//   and if so, makes it valid.
bool Scanner::VerifySimpleKey() {
  if (m_simpleKeys.empty())
    return false;

  // grab top key
  SimpleKey key = m_simpleKeys.top();

  // only validate if we're in the correct flow level
  if (key.flowLevel != GetFlowLevel())
    return false;

  m_simpleKeys.pop();

  bool isValid = true;

  // needs to be less than 1024 characters and inline
  if (INPUT.line() != key.mark.line || INPUT.pos() - key.mark.pos > 1024)
    isValid = false;

  // invalidate key
  if (isValid)
    key.Validate();
  else
    key.Invalidate();

  return isValid;
}

void Scanner::PopAllSimpleKeys() {
  while (!m_simpleKeys.empty())
    m_simpleKeys.pop();
}
}  // namespace YAML
// ====== END yaml-cpp/src/simplekey.cpp ======


// ====== BEGIN yaml-cpp/src/singledocparser.cpp ======
#include <cstdio>
#include <sstream>

// Expanding include: collectionstack.h

// ====== BEGIN yaml-cpp/src/collectionstack.h ======
#ifndef COLLECTIONSTACK_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define COLLECTIONSTACK_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <cassert>
#include <stack>

namespace YAML {
struct CollectionType {
  enum value { NoCollection, BlockMap, BlockSeq, FlowMap, FlowSeq, CompactMap };
};

class CollectionStack {
 public:
  CollectionStack() : collectionStack{} {}
  CollectionType::value GetCurCollectionType() const {
    if (collectionStack.empty())
      return CollectionType::NoCollection;
    return collectionStack.top();
  }

  void PushCollectionType(CollectionType::value type) {
    collectionStack.push(type);
  }
  void PopCollectionType(CollectionType::value type) {
    assert(type == GetCurCollectionType());
    (void)type;
    collectionStack.pop();
  }

 private:
  std::stack<CollectionType::value> collectionStack;
};
}  // namespace YAML

#endif  // COLLECTIONSTACK_H_62B23520_7C8E_11DE_8A39_0800200C9A66
// ====== END yaml-cpp/src/collectionstack.h ======

// Expanding include: scanner.h
// Expanding include: singledocparser.h
// Expanding include: tag.h
// Expanding include: token.h
// Expanding include: yaml-cpp/depthguard.h
// Expanding include: yaml-cpp/emitterstyle.h
// Expanding include: yaml-cpp/eventhandler.h
// Expanding include: yaml-cpp/exceptions.h
// Expanding include: yaml-cpp/mark.h
// Expanding include: yaml-cpp/null.h

namespace YAML {
SingleDocParser::SingleDocParser(Scanner& scanner, const Directives& directives)
    : m_scanner(scanner),
      m_directives(directives),
      m_pCollectionStack(new CollectionStack),
      m_anchors{},
      m_curAnchor(0) {}

SingleDocParser::~SingleDocParser() = default;

// HandleDocument
// . Handles the next document
// . Throws a ParserException on error.
void SingleDocParser::HandleDocument(EventHandler& eventHandler) {
  assert(!m_scanner.empty());  // guaranteed that there are tokens
  assert(!m_curAnchor);

  eventHandler.OnDocumentStart(m_scanner.peek().mark);

  // eat doc start
  if (m_scanner.peek().type == Token::DOC_START)
    m_scanner.pop();

  // recurse!
  HandleNode(eventHandler);

  eventHandler.OnDocumentEnd();

  // and finally eat any doc ends we see
  while (!m_scanner.empty() && m_scanner.peek().type == Token::DOC_END)
    m_scanner.pop();
}

void SingleDocParser::HandleNode(EventHandler& eventHandler) {
  DepthGuard<500> depthguard(depth, m_scanner.mark(), ErrorMsg::BAD_FILE);

  // an empty node *is* a possibility
  if (m_scanner.empty()) {
    eventHandler.OnNull(m_scanner.mark(), NullAnchor);
    return;
  }

  // save location
  Mark mark = m_scanner.peek().mark;

  // special case: a value node by itself must be a map, with no header
  if (m_scanner.peek().type == Token::VALUE) {
    eventHandler.OnMapStart(mark, "?", NullAnchor, EmitterStyle::Default);
    HandleMap(eventHandler);
    eventHandler.OnMapEnd();
    return;
  }

  // special case: an alias node
  if (m_scanner.peek().type == Token::ALIAS) {
    eventHandler.OnAlias(mark, LookupAnchor(mark, m_scanner.peek().value));
    m_scanner.pop();
    return;
  }

  std::string tag;
  std::string anchor_name;
  anchor_t anchor;
  ParseProperties(tag, anchor, anchor_name);

  if (!anchor_name.empty())
    eventHandler.OnAnchor(mark, anchor_name);

  // after parsing properties, an empty node is again a possibility
  if (m_scanner.empty()) {
    eventHandler.OnNull(mark, anchor);
    return;
  }

  const Token& token = m_scanner.peek();

  // add non-specific tags
  if (tag.empty())
    tag = (token.type == Token::NON_PLAIN_SCALAR ? "!" : "?");

  if (token.type == Token::PLAIN_SCALAR
      && tag.compare("?") == 0 && IsNullString(token.value.data(), token.value.size())) {
    eventHandler.OnNull(mark, anchor);
    m_scanner.pop();
    return;
  }

  // now split based on what kind of node we should be
  switch (token.type) {
    case Token::PLAIN_SCALAR:
    case Token::NON_PLAIN_SCALAR:
      eventHandler.OnScalar(mark, tag, anchor, token.value);
      m_scanner.pop();
      return;
    case Token::FLOW_SEQ_START:
      eventHandler.OnSequenceStart(mark, tag, anchor, EmitterStyle::Flow);
      HandleSequence(eventHandler);
      eventHandler.OnSequenceEnd();
      return;
    case Token::BLOCK_SEQ_START:
      eventHandler.OnSequenceStart(mark, tag, anchor, EmitterStyle::Block);
      HandleSequence(eventHandler);
      eventHandler.OnSequenceEnd();
      return;
    case Token::FLOW_MAP_START:
      eventHandler.OnMapStart(mark, tag, anchor, EmitterStyle::Flow);
      HandleMap(eventHandler);
      eventHandler.OnMapEnd();
      return;
    case Token::BLOCK_MAP_START:
      eventHandler.OnMapStart(mark, tag, anchor, EmitterStyle::Block);
      HandleMap(eventHandler);
      eventHandler.OnMapEnd();
      return;
    case Token::KEY:
      // compact maps can only go in a flow sequence
      if (m_pCollectionStack->GetCurCollectionType() ==
          CollectionType::FlowSeq) {
        eventHandler.OnMapStart(mark, tag, anchor, EmitterStyle::Flow);
        HandleMap(eventHandler);
        eventHandler.OnMapEnd();
        return;
      }
      break;
    default:
      break;
  }

  if (tag == "?")
    eventHandler.OnNull(mark, anchor);
  else
    eventHandler.OnScalar(mark, tag, anchor, "");
}

void SingleDocParser::HandleSequence(EventHandler& eventHandler) {
  // split based on start token
  switch (m_scanner.peek().type) {
    case Token::BLOCK_SEQ_START:
      HandleBlockSequence(eventHandler);
      break;
    case Token::FLOW_SEQ_START:
      HandleFlowSequence(eventHandler);
      break;
    default:
      break;
  }
}

void SingleDocParser::HandleBlockSequence(EventHandler& eventHandler) {
  // eat start token
  m_scanner.pop();
  m_pCollectionStack->PushCollectionType(CollectionType::BlockSeq);

  while (true) {
    if (m_scanner.empty())
      throw ParserException(m_scanner.mark(), ErrorMsg::END_OF_SEQ);

    Token token = m_scanner.peek();
    if (token.type != Token::BLOCK_ENTRY && token.type != Token::BLOCK_SEQ_END)
      throw ParserException(token.mark, ErrorMsg::END_OF_SEQ);

    m_scanner.pop();
    if (token.type == Token::BLOCK_SEQ_END)
      break;

    // check for null
    if (!m_scanner.empty()) {
      const Token& nextToken = m_scanner.peek();
      if (nextToken.type == Token::BLOCK_ENTRY ||
          nextToken.type == Token::BLOCK_SEQ_END) {
        eventHandler.OnNull(nextToken.mark, NullAnchor);
        continue;
      }
    }

    HandleNode(eventHandler);
  }

  m_pCollectionStack->PopCollectionType(CollectionType::BlockSeq);
}

void SingleDocParser::HandleFlowSequence(EventHandler& eventHandler) {
  // eat start token
  m_scanner.pop();
  m_pCollectionStack->PushCollectionType(CollectionType::FlowSeq);

  while (true) {
    if (m_scanner.empty())
      throw ParserException(m_scanner.mark(), ErrorMsg::END_OF_SEQ_FLOW);

    // first check for end
    if (m_scanner.peek().type == Token::FLOW_SEQ_END) {
      m_scanner.pop();
      break;
    }

    // then read the node
    HandleNode(eventHandler);

    if (m_scanner.empty())
      throw ParserException(m_scanner.mark(), ErrorMsg::END_OF_SEQ_FLOW);

    // now eat the separator (or could be a sequence end, which we ignore - but
    // if it's neither, then it's a bad node)
    Token& token = m_scanner.peek();
    if (token.type == Token::FLOW_ENTRY)
      m_scanner.pop();
    else if (token.type != Token::FLOW_SEQ_END)
      throw ParserException(token.mark, ErrorMsg::END_OF_SEQ_FLOW);
  }

  m_pCollectionStack->PopCollectionType(CollectionType::FlowSeq);
}

void SingleDocParser::HandleMap(EventHandler& eventHandler) {
  // split based on start token
  switch (m_scanner.peek().type) {
    case Token::BLOCK_MAP_START:
      HandleBlockMap(eventHandler);
      break;
    case Token::FLOW_MAP_START:
      HandleFlowMap(eventHandler);
      break;
    case Token::KEY:
      HandleCompactMap(eventHandler);
      break;
    case Token::VALUE:
      HandleCompactMapWithNoKey(eventHandler);
      break;
    default:
      break;
  }
}

void SingleDocParser::HandleBlockMap(EventHandler& eventHandler) {
  // eat start token
  m_scanner.pop();
  m_pCollectionStack->PushCollectionType(CollectionType::BlockMap);

  while (true) {
    if (m_scanner.empty())
      throw ParserException(m_scanner.mark(), ErrorMsg::END_OF_MAP);

    Token token = m_scanner.peek();
    if (token.type != Token::KEY && token.type != Token::VALUE &&
        token.type != Token::BLOCK_MAP_END)
      throw ParserException(token.mark, ErrorMsg::END_OF_MAP);

    if (token.type == Token::BLOCK_MAP_END) {
      m_scanner.pop();
      break;
    }

    // grab key (if non-null)
    if (token.type == Token::KEY) {
      m_scanner.pop();
      HandleNode(eventHandler);
    } else {
      eventHandler.OnNull(token.mark, NullAnchor);
    }

    // now grab value (optional)
    if (!m_scanner.empty() && m_scanner.peek().type == Token::VALUE) {
      m_scanner.pop();
      HandleNode(eventHandler);
    } else {
      eventHandler.OnNull(token.mark, NullAnchor);
    }
  }

  m_pCollectionStack->PopCollectionType(CollectionType::BlockMap);
}

void SingleDocParser::HandleFlowMap(EventHandler& eventHandler) {
  // eat start token
  m_scanner.pop();
  m_pCollectionStack->PushCollectionType(CollectionType::FlowMap);

  while (true) {
    if (m_scanner.empty())
      throw ParserException(m_scanner.mark(), ErrorMsg::END_OF_MAP_FLOW);

    Token& token = m_scanner.peek();
    const Mark mark = token.mark;
    // first check for end
    if (token.type == Token::FLOW_MAP_END) {
      m_scanner.pop();
      break;
    }

    // grab key (if non-null)
    if (token.type == Token::KEY) {
      m_scanner.pop();
      HandleNode(eventHandler);
    } else {
      eventHandler.OnNull(mark, NullAnchor);
    }

    // now grab value (optional)
    if (!m_scanner.empty() && m_scanner.peek().type == Token::VALUE) {
      m_scanner.pop();
      HandleNode(eventHandler);
    } else {
      eventHandler.OnNull(mark, NullAnchor);
    }

    if (m_scanner.empty())
      throw ParserException(m_scanner.mark(), ErrorMsg::END_OF_MAP_FLOW);

    // now eat the separator (or could be a map end, which we ignore - but if
    // it's neither, then it's a bad node)
    Token& nextToken = m_scanner.peek();
    if (nextToken.type == Token::FLOW_ENTRY)
      m_scanner.pop();
    else if (nextToken.type != Token::FLOW_MAP_END)
      throw ParserException(nextToken.mark, ErrorMsg::END_OF_MAP_FLOW);
  }

  m_pCollectionStack->PopCollectionType(CollectionType::FlowMap);
}

// . Single "key: value" pair in a flow sequence
void SingleDocParser::HandleCompactMap(EventHandler& eventHandler) {
  m_pCollectionStack->PushCollectionType(CollectionType::CompactMap);

  // grab key
  Mark mark = m_scanner.peek().mark;
  m_scanner.pop();
  HandleNode(eventHandler);

  // now grab value (optional)
  if (!m_scanner.empty() && m_scanner.peek().type == Token::VALUE) {
    m_scanner.pop();
    HandleNode(eventHandler);
  } else {
    eventHandler.OnNull(mark, NullAnchor);
  }

  m_pCollectionStack->PopCollectionType(CollectionType::CompactMap);
}

// . Single ": value" pair in a flow sequence
void SingleDocParser::HandleCompactMapWithNoKey(EventHandler& eventHandler) {
  m_pCollectionStack->PushCollectionType(CollectionType::CompactMap);

  // null key
  eventHandler.OnNull(m_scanner.peek().mark, NullAnchor);

  // grab value
  m_scanner.pop();
  HandleNode(eventHandler);

  m_pCollectionStack->PopCollectionType(CollectionType::CompactMap);
}

// ParseProperties
// . Grabs any tag or anchor tokens and deals with them.
void SingleDocParser::ParseProperties(std::string& tag, anchor_t& anchor,
                                      std::string& anchor_name) {
  tag.clear();
  anchor_name.clear();
  anchor = NullAnchor;

  while (true) {
    if (m_scanner.empty())
      return;

    switch (m_scanner.peek().type) {
      case Token::TAG:
        ParseTag(tag);
        break;
      case Token::ANCHOR:
        ParseAnchor(anchor, anchor_name);
        break;
      default:
        return;
    }
  }
}

void SingleDocParser::ParseTag(std::string& tag) {
  Token& token = m_scanner.peek();
  if (!tag.empty())
    throw ParserException(token.mark, ErrorMsg::MULTIPLE_TAGS);

  Tag tagInfo(token);
  tag = tagInfo.Translate(m_directives);
  m_scanner.pop();
}

void SingleDocParser::ParseAnchor(anchor_t& anchor, std::string& anchor_name) {
  Token& token = m_scanner.peek();
  if (anchor)
    throw ParserException(token.mark, ErrorMsg::MULTIPLE_ANCHORS);

  anchor_name = token.value;
  anchor = RegisterAnchor(token.value);
  m_scanner.pop();
}

anchor_t SingleDocParser::RegisterAnchor(const std::string& name) {
  if (name.empty())
    return NullAnchor;

  return m_anchors[name] = ++m_curAnchor;
}

anchor_t SingleDocParser::LookupAnchor(const Mark& mark,
                                       const std::string& name) const {
  auto it = m_anchors.find(name);
  if (it == m_anchors.end()) {
    std::stringstream ss;
    ss << ErrorMsg::UNKNOWN_ANCHOR << name;
    throw ParserException(mark, ss.str());
  }

  return it->second;
}
}  // namespace YAML
// ====== END yaml-cpp/src/singledocparser.cpp ======


// ====== BEGIN yaml-cpp/src/stream.cpp ======
#include <istream>

// Expanding include: stream.h

#ifndef YAML_PREFETCH_SIZE
#define YAML_PREFETCH_SIZE 2048
#endif

#define S_ARRAY_SIZE(A) (sizeof(A) / sizeof(*(A)))
#define S_ARRAY_END(A) ((A) + S_ARRAY_SIZE(A))

#define CP_REPLACEMENT_CHARACTER (0xFFFD)

namespace YAML {
enum UtfIntroState {
  uis_start,
  uis_utfbe_b1,
  uis_utf32be_b2,
  uis_utf32be_bom3,
  uis_utf32be,
  uis_utf16be,
  uis_utf16be_bom1,
  uis_utfle_bom1,
  uis_utf16le_bom2,
  uis_utf32le_bom3,
  uis_utf16le,
  uis_utf32le,
  uis_utf8_imp,
  uis_utf16le_imp,
  uis_utf32le_imp3,
  uis_utf8_bom1,
  uis_utf8_bom2,
  uis_utf8,
  uis_error
};

enum UtfIntroCharType {
  uict00,
  uictBB,
  uictBF,
  uictEF,
  uictFE,
  uictFF,
  uictAscii,
  uictOther,
  uictMax
};

static bool s_introFinalState[] = {
    false,  // uis_start
    false,  // uis_utfbe_b1
    false,  // uis_utf32be_b2
    false,  // uis_utf32be_bom3
    true,   // uis_utf32be
    true,   // uis_utf16be
    false,  // uis_utf16be_bom1
    false,  // uis_utfle_bom1
    false,  // uis_utf16le_bom2
    false,  // uis_utf32le_bom3
    true,   // uis_utf16le
    true,   // uis_utf32le
    false,  // uis_utf8_imp
    false,  // uis_utf16le_imp
    false,  // uis_utf32le_imp3
    false,  // uis_utf8_bom1
    false,  // uis_utf8_bom2
    true,   // uis_utf8
    true,   // uis_error
};

static UtfIntroState s_introTransitions[][uictMax] = {
    // uict00,           uictBB,           uictBF,           uictEF,
    // uictFE,           uictFF,           uictAscii,        uictOther
    {uis_utfbe_b1, uis_utf8, uis_utf8, uis_utf8_bom1, uis_utf16be_bom1,
     uis_utfle_bom1, uis_utf8_imp, uis_utf8},
    {uis_utf32be_b2, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8,
     uis_utf16be, uis_utf8},
    {uis_utf32be, uis_utf8, uis_utf8, uis_utf8, uis_utf32be_bom3, uis_utf8,
     uis_utf8, uis_utf8},
    {uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf32be, uis_utf8,
     uis_utf8},
    {uis_utf32be, uis_utf32be, uis_utf32be, uis_utf32be, uis_utf32be,
     uis_utf32be, uis_utf32be, uis_utf32be},
    {uis_utf16be, uis_utf16be, uis_utf16be, uis_utf16be, uis_utf16be,
     uis_utf16be, uis_utf16be, uis_utf16be},
    {uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf16be, uis_utf8,
     uis_utf8},
    {uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf16le_bom2, uis_utf8,
     uis_utf8, uis_utf8},
    {uis_utf32le_bom3, uis_utf16le, uis_utf16le, uis_utf16le, uis_utf16le,
     uis_utf16le, uis_utf16le, uis_utf16le},
    {uis_utf32le, uis_utf16le, uis_utf16le, uis_utf16le, uis_utf16le,
     uis_utf16le, uis_utf16le, uis_utf16le},
    {uis_utf16le, uis_utf16le, uis_utf16le, uis_utf16le, uis_utf16le,
     uis_utf16le, uis_utf16le, uis_utf16le},
    {uis_utf32le, uis_utf32le, uis_utf32le, uis_utf32le, uis_utf32le,
     uis_utf32le, uis_utf32le, uis_utf32le},
    {uis_utf16le_imp, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8,
     uis_utf8, uis_utf8},
    {uis_utf32le_imp3, uis_utf16le, uis_utf16le, uis_utf16le, uis_utf16le,
     uis_utf16le, uis_utf16le, uis_utf16le},
    {uis_utf32le, uis_utf16le, uis_utf16le, uis_utf16le, uis_utf16le,
     uis_utf16le, uis_utf16le, uis_utf16le},
    {uis_utf8, uis_utf8_bom2, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8,
     uis_utf8},
    {uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8,
     uis_utf8},
    {uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8, uis_utf8,
     uis_utf8},
};

static char s_introUngetCount[][uictMax] = {
    // uict00, uictBB, uictBF, uictEF, uictFE, uictFF, uictAscii, uictOther
    {0, 1, 1, 0, 0, 0, 0, 1}, {0, 2, 2, 2, 2, 2, 2, 2},
    {3, 3, 3, 3, 0, 3, 3, 3}, {4, 4, 4, 4, 4, 0, 4, 4},
    {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
    {2, 2, 2, 2, 2, 0, 2, 2}, {2, 2, 2, 2, 0, 2, 2, 2},
    {0, 1, 1, 1, 1, 1, 1, 1}, {0, 2, 2, 2, 2, 2, 2, 2},
    {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 2, 2, 2, 2, 2, 2, 2}, {0, 3, 3, 3, 3, 3, 3, 3},
    {4, 4, 4, 4, 4, 4, 4, 4}, {2, 0, 2, 2, 2, 2, 2, 2},
    {3, 3, 0, 3, 3, 3, 3, 3}, {1, 1, 1, 1, 1, 1, 1, 1},
};

inline UtfIntroCharType IntroCharTypeOf(std::istream::int_type ch) {
  if (std::istream::traits_type::eof() == ch) {
    return uictOther;
  }

  switch (ch) {
    case 0:
      return uict00;
    case 0xBB:
      return uictBB;
    case 0xBF:
      return uictBF;
    case 0xEF:
      return uictEF;
    case 0xFE:
      return uictFE;
    case 0xFF:
      return uictFF;
  }

  if ((ch > 0) && (ch < 0xFF)) {
    return uictAscii;
  }

  return uictOther;
}

inline char Utf8Adjust(unsigned long ch, unsigned char lead_bits,
                       unsigned char rshift) {
  const unsigned char header =
      static_cast<unsigned char>(((1 << lead_bits) - 1) << (8 - lead_bits));
  const unsigned char mask = (0xFF >> (lead_bits + 1));
  return static_cast<char>(
      static_cast<unsigned char>(header | ((ch >> rshift) & mask)));
}

inline void QueueUnicodeCodepoint(std::deque<char>& q, unsigned long ch) {
  // We are not allowed to queue the Stream::eof() codepoint, so
  // replace it with CP_REPLACEMENT_CHARACTER
  if (static_cast<unsigned long>(Stream::eof()) == ch) {
    ch = CP_REPLACEMENT_CHARACTER;
  }

  if (ch < 0x80) {
    q.push_back(Utf8Adjust(ch, 0, 0));
  } else if (ch < 0x800) {
    q.push_back(Utf8Adjust(ch, 2, 6));
    q.push_back(Utf8Adjust(ch, 1, 0));
  } else if (ch < 0x10000) {
    q.push_back(Utf8Adjust(ch, 3, 12));
    q.push_back(Utf8Adjust(ch, 1, 6));
    q.push_back(Utf8Adjust(ch, 1, 0));
  } else {
    q.push_back(Utf8Adjust(ch, 4, 18));
    q.push_back(Utf8Adjust(ch, 1, 12));
    q.push_back(Utf8Adjust(ch, 1, 6));
    q.push_back(Utf8Adjust(ch, 1, 0));
  }
}

Stream::Stream(std::istream& input)
    : m_input(input),
      m_mark{},
      m_charSet{},
      m_readahead{},
      m_pPrefetched(new unsigned char[YAML_PREFETCH_SIZE]),
      m_nPrefetchedAvailable(0),
      m_nPrefetchedUsed(0) {
  using char_traits = std::istream::traits_type;

  if (!input)
    return;

  // Determine (or guess) the character-set by reading the BOM, if any.  See
  // the YAML specification for the determination algorithm.
  char_traits::int_type intro[4]{};
  int nIntroUsed = 0;
  UtfIntroState state = uis_start;
  for (; !s_introFinalState[state];) {
    std::istream::int_type ch = input.get();
    intro[nIntroUsed++] = ch;
    UtfIntroCharType charType = IntroCharTypeOf(ch);
    UtfIntroState newState = s_introTransitions[state][charType];
    int nUngets = s_introUngetCount[state][charType];
    if (nUngets > 0) {
      input.clear();
      for (; nUngets > 0; --nUngets) {
        if (char_traits::eof() != intro[--nIntroUsed])
          input.putback(char_traits::to_char_type(intro[nIntroUsed]));
      }
    }
    state = newState;
  }

  switch (state) {
    case uis_utf8:
      m_charSet = utf8;
      break;
    case uis_utf16le:
      m_charSet = utf16le;
      break;
    case uis_utf16be:
      m_charSet = utf16be;
      break;
    case uis_utf32le:
      m_charSet = utf32le;
      break;
    case uis_utf32be:
      m_charSet = utf32be;
      break;
    default:
      m_charSet = utf8;
      break;
  }

  ReadAheadTo(0);
}

Stream::~Stream() { delete[] m_pPrefetched; }

char Stream::peek() const {
  if (m_readahead.empty()) {
    return Stream::eof();
  }

  return m_readahead[0];
}

Stream::operator bool() const {
  return m_input.good() ||
         (!m_readahead.empty() && m_readahead[0] != Stream::eof());
}

// get
// . Extracts a character from the stream and updates our position
char Stream::get() {
  char ch = peek();
  AdvanceCurrent();
  m_mark.column++;

  // if line ending symbol is unknown, set it to the first
  // encountered line ending.
  // if line ending '\r' set ending symbol to '\r'
  // other wise set it to '\n'
  if (!m_lineEndingSymbol) {
    if (ch == '\n') { // line ending is '\n'
      m_lineEndingSymbol = '\n';
    } else if (ch == '\r') {
      auto ch2 = peek();
      if (ch2 == '\n') { // line ending is '\r\n'
        m_lineEndingSymbol = '\n';
      } else { // line ending is '\r'
        m_lineEndingSymbol = '\r';
      }
    }
  }

  if (ch == m_lineEndingSymbol) {
    m_mark.column = 0;
    m_mark.line++;
  }

  return ch;
}

// get
// . Extracts 'n' characters from the stream and updates our position
std::string Stream::get(int n) {
  std::string ret;
  if (n > 0) {
    ret.reserve(static_cast<std::string::size_type>(n));
    for (int i = 0; i < n; i++)
      ret += get();
  }
  return ret;
}

// eat
// . Eats 'n' characters and updates our position.
void Stream::eat(int n) {
  for (int i = 0; i < n; i++)
    get();
}

void Stream::AdvanceCurrent() {
  if (!m_readahead.empty()) {
    m_readahead.pop_front();
    m_mark.pos++;
  }

  ReadAheadTo(0);
}

bool Stream::_ReadAheadTo(size_t i) const {
  while (m_input.good() && (m_readahead.size() <= i)) {
    switch (m_charSet) {
      case utf8:
        StreamInUtf8();
        break;
      case utf16le:
        StreamInUtf16();
        break;
      case utf16be:
        StreamInUtf16();
        break;
      case utf32le:
        StreamInUtf32();
        break;
      case utf32be:
        StreamInUtf32();
        break;
    }
  }

  // signal end of stream
  if (!m_input.good())
    m_readahead.push_back(Stream::eof());

  return m_readahead.size() > i;
}

void Stream::StreamInUtf8() const {
  unsigned char b = GetNextByte();
  if (m_input.good()) {
    m_readahead.push_back(static_cast<char>(b));
  }
}

void Stream::StreamInUtf16() const {
  unsigned long ch = 0;
  unsigned char bytes[2];
  int nBigEnd = (m_charSet == utf16be) ? 0 : 1;

  bytes[0] = GetNextByte();
  bytes[1] = GetNextByte();
  if (!m_input.good()) {
    return;
  }
  ch = (static_cast<unsigned long>(bytes[nBigEnd]) << 8) |
       static_cast<unsigned long>(bytes[1 ^ nBigEnd]);

  if (ch >= 0xDC00 && ch < 0xE000) {
    // Trailing (low) surrogate...ugh, wrong order
    QueueUnicodeCodepoint(m_readahead, CP_REPLACEMENT_CHARACTER);
    return;
  }

  if (ch >= 0xD800 && ch < 0xDC00) {
    // ch is a leading (high) surrogate

    // Four byte UTF-8 code point

    // Read the trailing (low) surrogate
    for (;;) {
      bytes[0] = GetNextByte();
      bytes[1] = GetNextByte();
      if (!m_input.good()) {
        QueueUnicodeCodepoint(m_readahead, CP_REPLACEMENT_CHARACTER);
        return;
      }
      unsigned long chLow = (static_cast<unsigned long>(bytes[nBigEnd]) << 8) |
                            static_cast<unsigned long>(bytes[1 ^ nBigEnd]);
      if (chLow < 0xDC00 || chLow >= 0xE000) {
        // Trouble...not a low surrogate.  Dump a REPLACEMENT CHARACTER into the
        // stream.
        QueueUnicodeCodepoint(m_readahead, CP_REPLACEMENT_CHARACTER);

        // Deal with the next UTF-16 unit
        if (chLow < 0xD800 || chLow >= 0xE000) {
          // Easiest case: queue the codepoint and return
          QueueUnicodeCodepoint(m_readahead, ch);
          return;
        }
        // Start the loop over with the new high surrogate
        ch = chLow;
        continue;
      }

      // Select the payload bits from the high surrogate
      ch &= 0x3FF;
      ch <<= 10;

      // Include bits from low surrogate
      ch |= (chLow & 0x3FF);

      // Add the surrogacy offset
      ch += 0x10000;
      break;
    }
  }

  QueueUnicodeCodepoint(m_readahead, ch);
}

inline char* ReadBuffer(unsigned char* pBuffer) {
  return reinterpret_cast<char*>(pBuffer);
}

unsigned char Stream::GetNextByte() const {
  if (m_nPrefetchedUsed >= m_nPrefetchedAvailable) {
    std::streambuf* pBuf = m_input.rdbuf();
    m_nPrefetchedAvailable = static_cast<std::size_t>(
        pBuf->sgetn(ReadBuffer(m_pPrefetched), YAML_PREFETCH_SIZE));
    m_nPrefetchedUsed = 0;
    if (!m_nPrefetchedAvailable) {
      m_input.setstate(std::ios_base::eofbit);
    }

    if (0 == m_nPrefetchedAvailable) {
      return 0;
    }
  }

  return m_pPrefetched[m_nPrefetchedUsed++];
}

void Stream::StreamInUtf32() const {
  static int indexes[2][4] = {{3, 2, 1, 0}, {0, 1, 2, 3}};

  unsigned long ch = 0;
  unsigned char bytes[4];
  int* pIndexes = (m_charSet == utf32be) ? indexes[1] : indexes[0];

  bytes[0] = GetNextByte();
  bytes[1] = GetNextByte();
  bytes[2] = GetNextByte();
  bytes[3] = GetNextByte();
  if (!m_input.good()) {
    return;
  }

  for (int i = 0; i < 4; ++i) {
    ch <<= 8;
    ch |= bytes[pIndexes[i]];
  }

  QueueUnicodeCodepoint(m_readahead, ch);
}
}  // namespace YAML
// ====== END yaml-cpp/src/stream.cpp ======


// ====== BEGIN yaml-cpp/src/tag.cpp ======
#include <cassert>
#include <stdexcept>

// Expanding include: directives.h
// Expanding include: tag.h
// Expanding include: token.h

namespace YAML {
Tag::Tag(const Token& token)
    : type(static_cast<TYPE>(token.data)), handle{}, value{} {
  switch (type) {
    case VERBATIM:
      value = token.value;
      break;
    case PRIMARY_HANDLE:
      value = token.value;
      break;
    case SECONDARY_HANDLE:
      value = token.value;
      break;
    case NAMED_HANDLE:
      handle = token.value;
      value = token.params[0];
      break;
    case NON_SPECIFIC:
      break;
    default:
      assert(false);
  }
}

std::string Tag::Translate(const Directives& directives) {
  switch (type) {
    case VERBATIM:
      return value;
    case PRIMARY_HANDLE:
      return directives.TranslateTagHandle("!") + value;
    case SECONDARY_HANDLE:
      return directives.TranslateTagHandle("!!") + value;
    case NAMED_HANDLE:
      return directives.TranslateTagHandle("!" + handle + "!") + value;
    case NON_SPECIFIC:
      // TODO:
      return "!";
    default:
      assert(false);
  }
  throw std::runtime_error("yaml-cpp: internal error, bad tag type");
}
}  // namespace YAML
// ====== END yaml-cpp/src/tag.cpp ======

