#include "folder.hpp"

#include <gtest/gtest.h>

#include "mtest.hpp"

TEST(Init, GetName) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_STREQ(f.getName().c_str(), "/");
}
TEST(Init, Size) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_EQ(f.size(), 0);
}
TEST(Init, Height) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_EQ(f.height(), 1);
}
TEST(Init, RemoveSubfolder) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_NO_THROW(f.removeSubfolder("test"));
  EXPECT_STREQ(f.getName().c_str(), "/");
}
TEST(Init, RemoveSubfolderSelf) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_NO_THROW(f.removeSubfolder("/"));
  EXPECT_STREQ(f.getName().c_str(), "/");
}
TEST(Init, RemoveAll) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_NO_THROW(f.removeAll());
  EXPECT_STREQ(f.getName().c_str(), "/");
}
TEST(Init, Find) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_TRUE(f.find("test").empty());
}
TEST(Init, FindSelf) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_TRUE(f.find("/").empty());
}
TEST(Init, Subfolders) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_TRUE(f.subfolders().empty());
}
TEST(Init, Superfolder) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_EQ(f.superfolder(), nullptr);
}
TEST(Init, Stream) {
  MemoryLeakDetector leakD;
  Folder f("/");
  std::stringstream out;
  out << f;
  EXPECT_STREQ(out.str().c_str(), "/\n0 subfolders\n");
}

TEST(Subfolders, Single) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_EQ(f.subfolders().size(), 0);
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 1);
  EXPECT_STREQ(f.subfolders()[0]->getName().c_str(), "home");
}
TEST(Subfolders, Multiple) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_EQ(f.subfolders().size(), 0);
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 1);
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_EQ(f.subfolders().size(), 2);
  ASSERT_FALSE(f.addSubfolder("docs"));
  ASSERT_EQ(f.subfolders().size(), 2);
  EXPECT_STREQ(f.subfolders()[0]->getName().c_str(), "docs");
  EXPECT_STREQ(f.subfolders()[1]->getName().c_str(), "home");
}
TEST(Subfolders, Nested) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_EQ(f.subfolders().size(), 0);
  ASSERT_TRUE(f.addSubfolder("home"));
  EXPECT_EQ(f.subfolders().size(), 1);
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_EQ(f.subfolders().size(), 2);
  Folder *p = f.subfolders()[0];
  Folder *q = f.subfolders()[1];
  ASSERT_TRUE(p->addSubfolder("scripts"));
  ASSERT_TRUE(p->addSubfolder("articles"));
  ASSERT_TRUE(q->addSubfolder("downloads"));
  ASSERT_TRUE(q->addSubfolder("files"));
  ASSERT_TRUE(q->addSubfolder("articles"));
  ASSERT_EQ(f.subfolders().size(), 2);
  EXPECT_STREQ(f.subfolders()[0]->getName().c_str(), "docs");
  EXPECT_STREQ(f.subfolders()[1]->getName().c_str(), "home");
  ASSERT_EQ(p->subfolders().size(), 2);
  EXPECT_STREQ(p->subfolders()[0]->getName().c_str(), "articles");
  EXPECT_STREQ(p->subfolders()[1]->getName().c_str(), "scripts");
  ASSERT_EQ(q->subfolders().size(), 3);
  EXPECT_STREQ(q->subfolders()[0]->getName().c_str(), "articles");
  EXPECT_STREQ(q->subfolders()[1]->getName().c_str(), "downloads");
  EXPECT_STREQ(q->subfolders()[2]->getName().c_str(), "files");
}
TEST(Subfolders, Removed) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  EXPECT_EQ(f.subfolders().size(), 1);
  f.removeSubfolder("home");
  EXPECT_EQ(f.subfolders().size(), 0);
}

TEST(Superfolder, Single) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 1);
  EXPECT_EQ(f.subfolders()[0]->superfolder(), &f);
}
TEST(Superfolder, Multiple) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_EQ(f.subfolders().size(), 2);
  EXPECT_EQ(f.subfolders()[0]->superfolder(), &f);
  EXPECT_EQ(f.subfolders()[1]->superfolder(), &f);
}
TEST(Superfolder, Nested) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_EQ(f.subfolders().size(), 2);
  EXPECT_EQ(f.subfolders()[0]->superfolder(), &f);
  EXPECT_EQ(f.subfolders()[1]->superfolder(), &f);
  ASSERT_TRUE(f.subfolders()[0]->addSubfolder("test"));
  ASSERT_EQ(f.subfolders()[0]->subfolders().size(), 1);
  EXPECT_EQ(f.subfolders()[0]->subfolders()[0]->superfolder(),
            f.subfolders()[0]);
}

TEST(AddSubfolder, Empty) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_TRUE(f.addSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 1);
  EXPECT_STREQ(f.subfolders()[0]->getName().c_str(), "home");
}
TEST(AddSubfolder, NotEmpty) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_TRUE(f.addSubfolder("home"));
  EXPECT_TRUE(f.addSubfolder("docs"));
  ASSERT_EQ(f.subfolders().size(), 2);
  EXPECT_STREQ(f.subfolders()[0]->getName().c_str(), "docs");
  EXPECT_STREQ(f.subfolders()[1]->getName().c_str(), "home");
}
TEST(AddSubfolder, Duplicate) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_TRUE(f.addSubfolder("home"));
  EXPECT_FALSE(f.addSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 1);
  EXPECT_STREQ(f.subfolders()[0]->getName().c_str(), "home");
}
TEST(AddSubfolder, Emptied) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_TRUE(f.addSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 1);
  f.removeAll();
  EXPECT_TRUE(f.addSubfolder("zzz"));
  ASSERT_EQ(f.subfolders().size(), 1);
  EXPECT_STREQ(f.subfolders()[0]->getName().c_str(), "zzz");
}

TEST(RemoveSubfolder, NotEmpty) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_NO_THROW(f.removeSubfolder("home"));
  EXPECT_EQ(f.subfolders().size(), 0);
}
TEST(RemoveSubfolder, InvalidName) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_NO_THROW(f.removeSubfolder("home"));
  EXPECT_EQ(f.subfolders().size(), 1);
}
TEST(RemoveSubfolder, RemovedName) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_NO_THROW(f.removeSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 0);
  ASSERT_NO_THROW(f.removeSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 0);
}
TEST(RemoveSubfolder, Multiple) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_TRUE(f.addSubfolder("libs"));
  EXPECT_EQ(f.subfolders().size(), 3);
  ASSERT_NO_THROW(f.removeSubfolder("home"));
  EXPECT_EQ(f.subfolders().size(), 2);
  ASSERT_NO_THROW(f.removeSubfolder("docs"));
  EXPECT_EQ(f.subfolders().size(), 1);
  ASSERT_NO_THROW(f.removeSubfolder("libs"));
  EXPECT_EQ(f.subfolders().size(), 0);
}

TEST(RemoveAll, NotEmpty) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_TRUE(f.addSubfolder("libs"));
  ASSERT_EQ(f.subfolders().size(), 3);
  EXPECT_NO_THROW(f.removeAll());
  EXPECT_EQ(f.subfolders().size(), 0);
}

TEST(Find, Subdirectory) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_EQ(f.find("home").size(), 1);
  EXPECT_STREQ(f.find("home")[0]->getName().c_str(), "home");
}
TEST(Find, Nested) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 1);
  Folder *p = f.subfolders()[0];
  ASSERT_TRUE(p->addSubfolder("home"));
  ASSERT_EQ(p->subfolders().size(), 1);
  ASSERT_EQ(f.find("home").size(), 2);
  EXPECT_STREQ(f.find("home")[0]->getName().c_str(), "home");
  EXPECT_STREQ(f.find("home")[1]->getName().c_str(), "home");
  EXPECT_EQ(f.find("home")[0]->superfolder(), &f);
}
TEST(Find, NotFound) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  EXPECT_EQ(f.find("docs").size(), 0);
}
TEST(Find, SubSubfolder) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_EQ(f.subfolders().size(), 1);
  Folder *p = f.subfolders()[0];
  ASSERT_TRUE(p->addSubfolder("docs"));
  ASSERT_EQ(f.find("docs").size(), 1);
  EXPECT_EQ(f.find("docs")[0]->superfolder(), p);
}

TEST(Size, NotEmpty) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  EXPECT_EQ(f.size(), 1);
}
TEST(Size, Changing) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_EQ(f.size(), 0);
  ASSERT_TRUE(f.addSubfolder("home"));
  EXPECT_EQ(f.size(), 1);
  ASSERT_TRUE(f.addSubfolder("docs"));
  EXPECT_EQ(f.size(), 2);
  f.removeAll();
  EXPECT_EQ(f.size(), 0);
}
TEST(Size, Nested) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_EQ(f.size(), 2);
  Folder *p = f.subfolders()[0];
  Folder *q = f.subfolders()[1];
  ASSERT_TRUE(p->addSubfolder("scripts"));
  ASSERT_TRUE(p->addSubfolder("articles"));
  ASSERT_TRUE(q->addSubfolder("downloads"));
  ASSERT_TRUE(q->addSubfolder("files"));
  ASSERT_TRUE(q->addSubfolder("articles"));
  EXPECT_EQ(f.size(), 7);
  EXPECT_EQ(p->size(), 2);
  EXPECT_EQ(q->size(), 3);
}

TEST(Height, NotEmpty) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  EXPECT_EQ(f.height(), 2);
}
TEST(Height, Changing) {
  MemoryLeakDetector leakD;
  Folder f("/");
  EXPECT_EQ(f.height(), 1);
  ASSERT_TRUE(f.addSubfolder("home"));
  EXPECT_EQ(f.height(), 2);
  ASSERT_TRUE(f.addSubfolder("docs"));
  EXPECT_EQ(f.height(), 2);
  f.removeAll();
  EXPECT_EQ(f.height(), 1);
}
TEST(Height, Nested) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_EQ(f.height(), 2);
  Folder *p = f.subfolders()[0];
  Folder *q = f.subfolders()[1];
  ASSERT_TRUE(p->addSubfolder("scripts"));
  ASSERT_TRUE(p->addSubfolder("articles"));
  ASSERT_TRUE(q->addSubfolder("downloads"));
  ASSERT_TRUE(q->addSubfolder("files"));
  ASSERT_TRUE(q->addSubfolder("articles"));
  EXPECT_EQ(f.height(), 3);
  EXPECT_EQ(p->height(), 2);
  EXPECT_EQ(q->height(), 2);
  EXPECT_EQ(q->subfolders()[0]->height(), 1);
}
TEST(Height, Unbalanced) {
  MemoryLeakDetector leakD;
  Folder f("/");
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_EQ(f.height(), 2);
  Folder *p = f.subfolders()[0];
  Folder *q = f.subfolders()[1];
  ASSERT_TRUE(p->addSubfolder("scripts"));
  ASSERT_TRUE(p->addSubfolder("articles"));
  EXPECT_EQ(f.height(), 3);
  EXPECT_EQ(p->height(), 2);
  EXPECT_EQ(q->height(), 1);
  EXPECT_EQ(p->subfolders()[0]->height(), 1);
}

TEST(Stream, Single) {
  MemoryLeakDetector leakD;
  Folder f("/");
  std::stringstream out;
  ASSERT_TRUE(f.addSubfolder("home"));
  out << f;
  EXPECT_STREQ(out.str().c_str(), "/\n\thome\n");
}
TEST(Stream, Multiple) {
  MemoryLeakDetector leakD;
  Folder f("/");
  std::stringstream out;
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_TRUE(f.addSubfolder("libs"));
  out << f;
  EXPECT_STREQ(out.str().c_str(), "/\n\tdocs\thome\tlibs\n");
}
TEST(Stream, Nested) {
  MemoryLeakDetector leakD;
  Folder f("/");
  std::stringstream out;
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_TRUE(f.addSubfolder("libs"));
  ASSERT_TRUE(f.subfolders()[0]->addSubfolder("articles"));
  out << f;
  EXPECT_STREQ(out.str().c_str(), "/\n\tdocs\thome\tlibs\n");
}
TEST(Stream, Nested2) {
  MemoryLeakDetector leakD;
  Folder f("/");
  std::stringstream out;
  ASSERT_TRUE(f.addSubfolder("home"));
  ASSERT_TRUE(f.addSubfolder("docs"));
  ASSERT_TRUE(f.addSubfolder("libs"));
  ASSERT_TRUE(f.subfolders()[0]->addSubfolder("articles"));
  out << *(f.subfolders()[0]);
  EXPECT_STREQ(out.str().c_str(), "docs\n\tarticles\n");
}