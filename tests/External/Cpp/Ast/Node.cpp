/*
 * Copyright 2021 Thimo Bohmer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http ://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissionsand
 * limitations under the License.
 */
/*
 * Part of the Deamer External.
 * For more information go to: https://github.com/Deruago/DeamerExternal
 */

#include <Deamer/External/Cpp/Ast/Node.h>
#include <gtest/gtest.h>

class TestNode : public testing::Test
{
protected:
	TestNode()
	{
	}

	virtual ~TestNode()
	{
	}

	const deamer::external::cpp::ast::NodeInformation defaultNodeInformation =
		deamer::external::cpp::ast::NodeInformation(
			0, deamer::external::cpp::ast::NodeValue::unknown,
			deamer::external::cpp::ast::MatchedProductionRule(), "", 0, 0);

	const deamer::external::cpp::ast::MatchedProductionRule defaultMatchedProductionRule =
		deamer::external::cpp::ast::MatchedProductionRule();
	const deamer::external::cpp::ast::NodeValue defaultNodeValue =
		deamer::external::cpp::ast::NodeValue::unknown;

	deamer::external::cpp::ast::Node* emptyNode = nullptr;
	deamer::external::cpp::ast::Node* node1 =
		new deamer::external::cpp::ast::Node(defaultNodeInformation);
	deamer::external::cpp::ast::Node* node2 =
		new deamer::external::cpp::ast::Node(defaultNodeInformation);
	deamer::external::cpp::ast::Node* node3 =
		new deamer::external::cpp::ast::Node(defaultNodeInformation);
	deamer::external::cpp::ast::Node* node4 =
		new deamer::external::cpp::ast::Node(defaultNodeInformation);
};

TEST_F(TestNode, CreateNodeWithNoNodes)
{
	const auto actual = deamer::external::cpp::ast::Node(defaultNodeInformation);

	EXPECT_EQ(0, actual.GetColumnNumber());
	EXPECT_EQ(0, actual.GetLineNumber());
	EXPECT_EQ(defaultMatchedProductionRule, actual.GetMatchedProductionRule());
	EXPECT_EQ(defaultNodeValue, actual.GetNodeValueType());

	EXPECT_EQ(0, actual.Get(0).size());
	EXPECT_EQ(0, actual.Get(1).size());
	EXPECT_EQ(0, actual.Get(2).size());
	EXPECT_EQ(0, actual.Get(3).size());

	EXPECT_EQ(0, actual.GetType());

	delete node1;
	delete node2;
	delete node3;
	delete node4;
}

TEST_F(TestNode, CreateNodeWith1Nodes)
{
	const auto actual = deamer::external::cpp::ast::Node(defaultNodeInformation, { node1 });

	EXPECT_EQ(0, actual.GetColumnNumber());
	EXPECT_EQ(0, actual.GetLineNumber());
	EXPECT_EQ(defaultMatchedProductionRule, actual.GetMatchedProductionRule());
	EXPECT_EQ(defaultNodeValue, actual.GetNodeValueType());

	EXPECT_EQ(1, actual.Get(0).size());
	EXPECT_EQ(0, actual.Get(1).size());
	EXPECT_EQ(0, actual.Get(2).size());
	EXPECT_EQ(0, actual.Get(3).size());

	EXPECT_EQ(0, actual.GetType());

	EXPECT_EQ(&actual, node1->GetParent());
	EXPECT_EQ(nullptr, node2->GetParent());
	EXPECT_EQ(nullptr, node3->GetParent());
	EXPECT_EQ(nullptr, node4->GetParent());

	delete node2;
	delete node3;
	delete node4;
}

TEST_F(TestNode, CreateNodeWith2Nodes)
{
	const auto actual = deamer::external::cpp::ast::Node(defaultNodeInformation, { node1, node2 });

	EXPECT_EQ(0, actual.GetColumnNumber());
	EXPECT_EQ(0, actual.GetLineNumber());
	EXPECT_EQ(defaultMatchedProductionRule, actual.GetMatchedProductionRule());
	EXPECT_EQ(defaultNodeValue, actual.GetNodeValueType());

	EXPECT_EQ(2, actual.Get(0).size());
	EXPECT_EQ(0, actual.Get(1).size());
	EXPECT_EQ(0, actual.Get(2).size());
	EXPECT_EQ(0, actual.Get(3).size());

	EXPECT_EQ(0, actual.GetType());

	EXPECT_EQ(&actual, node1->GetParent());
	EXPECT_EQ(&actual, node2->GetParent());
	EXPECT_EQ(nullptr, node3->GetParent());
	EXPECT_EQ(nullptr, node4->GetParent());

	delete node3;
	delete node4;
}

TEST_F(TestNode, CreateNodeWith3Nodes)
{
	const auto actual =
		deamer::external::cpp::ast::Node(defaultNodeInformation, { node1, node2, node3 });

	EXPECT_EQ(0, actual.GetColumnNumber());
	EXPECT_EQ(0, actual.GetLineNumber());
	EXPECT_EQ(defaultMatchedProductionRule, actual.GetMatchedProductionRule());
	EXPECT_EQ(defaultNodeValue, actual.GetNodeValueType());

	EXPECT_EQ(3, actual.Get(0).size());
	EXPECT_EQ(0, actual.Get(1).size());
	EXPECT_EQ(0, actual.Get(2).size());
	EXPECT_EQ(0, actual.Get(3).size());

	EXPECT_EQ(0, actual.GetType());

	EXPECT_EQ(&actual, node1->GetParent());
	EXPECT_EQ(&actual, node2->GetParent());
	EXPECT_EQ(&actual, node3->GetParent());
	EXPECT_EQ(nullptr, node4->GetParent());

	delete node4;
}

TEST_F(TestNode, CreateNodeWith4Nodes)
{
	const auto actual =
		deamer::external::cpp::ast::Node(defaultNodeInformation, { node1, node2, node3, node4 });

	EXPECT_EQ(0, actual.GetColumnNumber());
	EXPECT_EQ(0, actual.GetLineNumber());
	EXPECT_EQ(defaultMatchedProductionRule, actual.GetMatchedProductionRule());
	EXPECT_EQ(defaultNodeValue, actual.GetNodeValueType());

	EXPECT_EQ(4, actual.Get(0).size());
	EXPECT_EQ(0, actual.Get(1).size());
	EXPECT_EQ(0, actual.Get(2).size());
	EXPECT_EQ(0, actual.Get(3).size());

	EXPECT_EQ(0, actual.GetType());

	EXPECT_EQ(&actual, node1->GetParent());
	EXPECT_EQ(&actual, node2->GetParent());
	EXPECT_EQ(&actual, node3->GetParent());
	EXPECT_EQ(&actual, node4->GetParent());
}
