#include "include/SuperString.hh"

bool SuperString::isSequenceEmpty() const
{
    return this->_sequence->isEmpty();
}

bool SuperString::isSequenceNotEmpty() const
{
    return this->_sequence->isNotEmpty();
}

bool SuperString::testrefRelease_case0() const
{
    return this->_sequence->refRelease() == 0;
}

bool SuperString::testfreeingCost_notnull() const
{
    SuperString s1 = SuperString::Const("aaa");
    SubstringSequence *ss1 = new SubstringSequence(s1._sequence, 1, 2);
    this->_sequence->addReferencer(ss1);
    this->_sequence->reconstructReferencers();
    return true;
}

bool SuperString::testbad_substringMatches() const
{
    SuperString s1 = SuperString::Const("aaa");
    return this->_sequence->_substringMatches(1, s1);
}

bool SuperString::testCopyASCIISequence() const
{
    SuperString::Byte b[4] = "aaa";
    auto s1 = new SuperString::ConstASCIISequence(b);
    auto s2 = SuperString::CopyASCIISequence(s1);
    return true;
}

bool SuperString::testCopyUTF8Sequence() const
{
    SuperString::Byte b[4] = "aaa";
    auto s1 = new SuperString::ConstUTF8Sequence(b);
    auto s2 = SuperString::CopyUTF8Sequence(s1);
    return true;
}

bool SuperString::testUTF16BE_simple() const
{
    SuperString::Byte b[11] = {0xD8, 0xD8, 0xD8, 0xD8};
    SuperString s1 = SuperString::Const(b, SuperString::Encoding::UTF16BE);
    s1.length();
    s1.codeUnitAt(0);
    s1.codeUnitAt(1);
    s1.print(std::cout);
    return true;
}

bool SuperString::testCopyUTF16BESequence() const
{
    SuperString::Byte b[4] = "aaa";
    auto s1 = new SuperString::ConstUTF16BESequence(b);
    auto s2 = SuperString::CopyUTF16BESequence(s1);
    return true;
}

bool SuperString::testUTF32_simple() const
{
    SuperString::Byte b[11] = {0x00, 0x00, 0x10, 0x00};
    SuperString s1 = SuperString::Const(b, SuperString::Encoding::UTF32);
    s1.length();
    s1.print(std::cout);
    s1.length();
    return true;
}

bool SuperString::testCopyUTF32Sequence() const
{
    SuperString::Byte b[4] = "aaa";
    auto s1 = new SuperString::ConstUTF32Sequence(b);
    auto s2 = SuperString::CopyUTF32Sequence(s1);
    return true;
}

bool SuperString::testSubstringSequence_ref() const
{
    auto *s1 = new SubstringSequence(this->_sequence, 0, 3);
    SubstringSequence ss1 = SubstringSequence(s1, 0, 3);
    return true;
}

bool SuperString::testSubstringSequence_substr() const
{
    SubstringSequence ss1 = SubstringSequence(this->_sequence, 0, 3);
    SubstringSequence ss2 = SubstringSequence(this->_sequence, 1, 3);
    SubstringSequence ss3 = SubstringSequence(this->_sequence, 0, 3);
    SubstringSequence ss4 = SubstringSequence(this->_sequence, 0, 3);
    ss2.reconstructionCost(NULL);
    ss2.reconstruct(NULL);
    ss2.length();
    ss2.codeUnitAt(0).ok();
    ss2.codeUnitAt(5).isErr();
    ss1.substring(1, 2).isOk();
    ss3.substring(-1, 2).isErr();
    ss4.substring(1, 5).isErr();
    ss1.print(std::cout);
    ss2.print(std::cout);
    ss1.print(std::cout, 1, 2);
    ss2.print(std::cout, 1, 2);
    ss2.keepingCost();
    ss2.substring(-1, 2).isErr();
    ss2.substring(1, 5).isErr();
    ss2.substring(1, 2).isErr();
    return true;
}

bool SuperString::testSubstringSequence_trim() const
{
    SubstringSequence ss = SubstringSequence(this->_sequence, 0, 5);
    ss.trim().isNotEmpty();
    ss.trimLeft().isNotEmpty();
    ss.trimRight().isNotEmpty();
    return true;
}

bool SuperString::testConcatenationSequence_simple() const
{
    SuperString s1 = SuperString::Const(" bbb ");
    auto *cs1 = new ConcatenationSequence(this->_sequence, s1._sequence);
    auto *cs2 = new ConcatenationSequence(this->_sequence, s1._sequence);
    auto *cs3 = new ConcatenationSequence(this->_sequence, s1._sequence);
    auto *cs4 = new ConcatenationSequence(this->_sequence, s1._sequence);
    auto *cs5 = new ConcatenationSequence(this->_sequence, s1._sequence);
    auto *cs6 = new ConcatenationSequence(this->_sequence, s1._sequence);
    ConcatenationSequence cs_l = ConcatenationSequence(cs1, this->_sequence);
    ConcatenationSequence cs_r = ConcatenationSequence(this->_sequence, cs2);
    ConcatenationSequence cs_lcstr = ConcatenationSequence(this->_sequence, cs3);
    ConcatenationSequence cs_rcstr = ConcatenationSequence(cs4, this->_sequence);
    ConcatenationSequence cs_lcstr_r = ConcatenationSequence(this->_sequence, cs5);
    ConcatenationSequence cs_rcstr_l = ConcatenationSequence(cs6, this->_sequence);
    cs_lcstr.reconstruct(this->_sequence);
    cs_rcstr.reconstruct(this->_sequence);
    cs_lcstr_r.reconstruct(this->_sequence);
    cs_rcstr_l.reconstruct(this->_sequence);
    cs_lcstr_r.reconstruct(cs5);
    cs_rcstr_l.reconstruct(cs6);
    cs_lcstr.length();
    cs_rcstr.length();
    cs_lcstr_r.length();
    cs_rcstr_l.length();
    cs_l.codeUnitAt(0).isOk();
    cs_l.codeUnitAt(14).isOk();
    cs_l.codeUnitAt(20).isErr();
    cs_lcstr.codeUnitAt(0).isOk();
    cs_lcstr.codeUnitAt(14).isOk();
    cs_lcstr.codeUnitAt(20).isErr();
    cs_rcstr.codeUnitAt(0).isOk();
    cs_rcstr.codeUnitAt(14).isOk();
    cs_rcstr.codeUnitAt(20).isErr();
    cs_rcstr_l.codeUnitAt(0).isOk();
    cs_rcstr_l.codeUnitAt(20).isErr();
    cs_l.substring(1, 2).isErr();
    cs_l.substring(-1, 2).isErr();
    cs_l.substring(1, 20).isErr();
    cs_l.print(std::cout);
    cs_l.print(std::cout, 1, 2);
    cs_l.print(std::cout, 1, 20);
    cs_l.print(std::cout, -1, 2);
    cs_l.print(std::cout, -1, 10);
    cs_lcstr.print(std::cout);
    cs_lcstr.print(std::cout, 1, 2);
    cs_lcstr.print(std::cout, 1, 20);
    cs_lcstr.print(std::cout, -1, 2);
    cs_lcstr.print(std::cout, -1, 10);
    cs_rcstr.print(std::cout);
    cs_rcstr.print(std::cout, 1, 2);
    cs_rcstr.print(std::cout, 1, 20);
    cs_rcstr.print(std::cout, -1, 2);
    cs_rcstr.print(std::cout, -1, 10);
    cs_lcstr_r.print(std::cout);
    cs_lcstr_r.print(std::cout, 1, 2);
    cs_l.trim();
    cs_l.trimLeft();
    cs_l.trimRight();
    cs_lcstr.keepingCost();
    cs_rcstr.keepingCost();
    cs_lcstr_r.keepingCost();
    cs_l.reconstructionCost(cs1);
    cs_l.reconstructionCost(this->_sequence);
    cs_l.reconstructionCost(NULL);
    cs_lcstr.reconstructionCost(cs3);
    cs_lcstr.reconstructionCost(NULL);
    cs_rcstr.reconstructionCost(cs4);
    cs_rcstr.reconstructionCost(NULL);
    cs_lcstr_r.reconstructionCost(NULL);
    return true;
}

bool SuperString::testMultipleSequence_simple() const
{
    auto *ms1ptr = new MultipleSequence(this->_sequence, 2);
    auto *ms2ptr = new MultipleSequence(this->_sequence, 2);
    MultipleSequence ms1 = MultipleSequence(ms1ptr, 3);
    MultipleSequence ms2 = MultipleSequence(ms2ptr, 3);
    ms2.reconstruct(ms2ptr);
    ms2.length();
    ms2.codeUnitAt(31).isErr();
    ms2.codeUnitAt(4).isOk();
    ms1.substring(1, 2).isErr();
    ms1.substring(-1, 2).isErr();
    ms1.substring(1, 40).isErr();
    ms1.print(std::cout);
    ms1.print(std::cout, 1, 2);
    ms1.print(std::cout, 1, 14);
    ms1.print(std::cout, -1, 2);
    ms2.print(std::cout);
    ms2.print(std::cout, -1, 2);
    ms2.print(std::cout, -1, 40);
    ms2.print(std::cout, -1, 24);
    ms1.trim();
    ms1.trimLeft();
    ms1.trimRight();
    ms2.keepingCost();
    ms1.reconstructionCost(ms1ptr);
    ms2.reconstructionCost(NULL);
    return true;
}