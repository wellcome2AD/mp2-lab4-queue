#include "../Queue/TQueue.h"
#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int>(5));
}

TEST(TQueue, cannot_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<double>(-5));
}

TEST(TQueue, queue_after_creating_is_empty)
{
	TQueue<double> q(5);
	ASSERT_EQ(q.IsEmpty(), true);
}

TEST(TQueue, can_push_element_to_empty_queue)
{
	TQueue<double> q(5);
	ASSERT_NO_THROW(q.Push(1));
}

TEST(TQueue, can_push_element_to_nonfull_queue)
{
	TQueue<double> q(2);
	q.Push(1);
	ASSERT_NO_THROW(q.Push(1));
}

TEST(TQueue, cannot_push_element_to_full_queue)
{
	TQueue<double> q(1);
	q.Push(1);
	ASSERT_ANY_THROW(q.Push(1));
}

TEST(TQueue, cannot_pop_element_from_empty_queue)
{
	TQueue<double> q(5);
	ASSERT_ANY_THROW(q.Pop());
}
TEST(TQueue, can_push_and_pop)
{
	TQueue<double> q(5);
	q.Push(5);
	ASSERT_EQ(q.Pop(), 5);
}