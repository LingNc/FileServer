// Auto-generated amalgamated yaml-cpp header-only file
// 版本: 1.0.0 (原版 YAML-CPP: 0.8.0)
// 构建日期: 2025-04-26 01:57:52
// 构建系统: Linux LingNc 5.15.167.4-microsoft-standard-WSL2 #1 SMP Tue Nov 5 00:21:55 UTC 2024 x86_64 GNU/Linux
// 注意: 此文件只包含头文件，需要配合 libyaml.a 静态库使用
#pragma once

// ====== 头文件开始 ======

// ====== BEGIN yaml-cpp/include/yaml-cpp/yaml.h ======
#ifndef YAML_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define YAML_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/parser.h

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

// 展开 include: yaml-cpp/dll.h

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

// 展开 include: yaml-cpp/emitter.h

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

// 展开 include: yaml-cpp/binary.h

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

// 展开 include: yaml-cpp/dll.h

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

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/emitterdef.h

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

// 展开 include: yaml-cpp/emittermanip.h

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

// 展开 include: yaml-cpp/null.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/null.h ======
#ifndef NULL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NULL_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/dll.h
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

// 展开 include: yaml-cpp/ostream_wrapper.h

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

// 展开 include: yaml-cpp/dll.h

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

// 展开 include: yaml-cpp/fptostring.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/fptostring.h ======
#ifndef YAML_H_FPTOSTRING
#define YAML_H_FPTOSTRING

// 展开 include: yaml-cpp/dll.h

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

// 展开 include: yaml-cpp/emitterstyle.h

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

// 展开 include: yaml-cpp/stlemitter.h

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

// 展开 include: yaml-cpp/exceptions.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/exceptions.h ======
#ifndef EXCEPTIONS_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define EXCEPTIONS_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/mark.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/mark.h ======
#ifndef MARK_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define MARK_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/dll.h

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

// 展开 include: yaml-cpp/noexcept.h

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

// 展开 include: yaml-cpp/traits.h

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


// 展开 include: yaml-cpp/node/node.h

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

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/emitterstyle.h
// 展开 include: yaml-cpp/mark.h
// 展开 include: yaml-cpp/node/detail/iterator_fwd.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/iterator_fwd.h ======
#ifndef VALUE_DETAIL_ITERATOR_FWD_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_ITERATOR_FWD_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/dll.h
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

// 展开 include: yaml-cpp/node/ptr.h

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

// 展开 include: yaml-cpp/node/type.h

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

// 展开 include: yaml-cpp/node/impl.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/impl.h ======
#ifndef NODE_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/exceptions.h
// 展开 include: yaml-cpp/node/detail/memory.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/memory.h ======
#ifndef VALUE_DETAIL_MEMORY_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_MEMORY_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <set>

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/node/ptr.h

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

// 展开 include: yaml-cpp/node/detail/node.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/node.h ======
#ifndef NODE_DETAIL_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_DETAIL_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/emitterstyle.h
// 展开 include: yaml-cpp/node/detail/node_ref.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/node_ref.h ======
#ifndef VALUE_DETAIL_NODE_REF_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_NODE_REF_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/node/type.h
// 展开 include: yaml-cpp/node/ptr.h
// 展开 include: yaml-cpp/node/detail/node_data.h

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

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/node/detail/node_iterator.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/node_iterator.h ======
#ifndef VALUE_DETAIL_NODE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_NODE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/node/ptr.h
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

// 展开 include: yaml-cpp/node/iterator.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/iterator.h ======
#ifndef VALUE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/node/node.h
// 展开 include: yaml-cpp/node/detail/iterator_fwd.h
// 展开 include: yaml-cpp/node/detail/iterator.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/iterator.h ======
#ifndef VALUE_DETAIL_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define VALUE_DETAIL_ITERATOR_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/dll.h
// 展开 include: yaml-cpp/node/detail/node_iterator.h
// 展开 include: yaml-cpp/node/node.h
// 展开 include: yaml-cpp/node/ptr.h
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

// 展开 include: yaml-cpp/node/ptr.h
// 展开 include: yaml-cpp/node/type.h

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

// 展开 include: yaml-cpp/node/ptr.h
// 展开 include: yaml-cpp/node/type.h
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

// 展开 include: yaml-cpp/node/iterator.h
// 展开 include: yaml-cpp/node/node.h
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

// 展开 include: yaml-cpp/node/convert.h

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

// 展开 include: yaml-cpp/binary.h
// 展开 include: yaml-cpp/node/impl.h
// 展开 include: yaml-cpp/node/iterator.h
// 展开 include: yaml-cpp/node/node.h
// 展开 include: yaml-cpp/node/type.h
// 展开 include: yaml-cpp/null.h
// 展开 include: yaml-cpp/fptostring.h


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

// 展开 include: yaml-cpp/node/iterator.h
// 展开 include: yaml-cpp/node/detail/impl.h

// ====== BEGIN yaml-cpp/include/yaml-cpp/node/detail/impl.h ======
#ifndef NODE_DETAIL_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_DETAIL_IMPL_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

// 展开 include: yaml-cpp/node/detail/node.h
// 展开 include: yaml-cpp/node/detail/node_data.h

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

// 展开 include: yaml-cpp/node/parse.h

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

// 展开 include: yaml-cpp/dll.h

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

// 展开 include: yaml-cpp/node/emit.h

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

// 展开 include: yaml-cpp/dll.h

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

