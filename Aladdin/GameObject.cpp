#include "GameObject.h"
#include "Game.h"

GameObject::GameObject()
{
	x = y = 0;
	vx = vy = 0;

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = 0;
	collider.height = 0;
}

GameObject::GameObject(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	vx = vy = 0;

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = width;
	collider.height = height;
}

GameObject::~GameObject()
{
}

void GameObject::Update(DWORD dt)
{
}

void GameObject::Render()
{

}

void GameObject::MapCollisions(vector<TileObjectMap *> &tiles, vector<ColliedEvent*> &coEvents)
{
	Collider tileCollider;
	for (int i = 0; i < tiles.size(); i++)
	{
		tileCollider.width = tiles[i]->width;
		tileCollider.height = tiles[i]->height;

		tileCollider.x = tiles[i]->x;
		tileCollider.y = tiles[i]->y;

		if (tiles[i]->type == ObjectType::BRICK)
		{
			float time;
			float normalX;
			float normalY;
			time = Collision::GetInstance()->SweptAABB(this->GetCollider(), tileCollider, normalX, normalY);

			if (time >= 0 && time < 1.0f && normalY == 1)
			{
				coEvents.push_back(new ColliedEvent(EventCollison::EVENT_BRICK, time, normalX, normalY));
			}
		}
		else if (tiles[i]->type == ObjectType::WALL)
		{
			float time;
			float normalX;
			float normalY;

			time = Collision::GetInstance()->SweptAABB(this->GetCollider(), tileCollider, normalX, normalY);

			if (time >= 0 && time < 1.0f && normalY == 1)
			{
				coEvents.push_back(new ColliedEvent(EventCollison::EVENT_WALL, time, normalX, normalY));
			}
		}
		else if (tiles[i]->type == ObjectType::THORN)
		{
			float time;
			float normalX;
			float normalY;

			time = Collision::GetInstance()->SweptAABB(this->GetCollider(), tileCollider, normalX, normalY);

			if (time >= 0 && time < 1.0f && normalY == 1)
			{
				coEvents.push_back(new ColliedEvent(EventCollison::EVENT_THORN, time, normalX, normalY));
			}
		}
	}
}

bool GameObject::IsCollide(GameObject *CollisionObject)
{
	Collider MainObject = this->collider;
	RECT rec;
	rec.top = MainObject.y;
	rec.left = MainObject.x;
	rec.right = MainObject.x + MainObject.width;
	rec.bottom = MainObject.y - MainObject.height;

	Collider TargetObject = CollisionObject->collider;
	if (MainObject.direction == 1)
	{
		if (TargetObject.x > rec.left && TargetObject.x < rec.right)
		{
			if ((rec.top < TargetObject.y && rec.top > TargetObject.y - TargetObject.height)
				|| (rec.top > TargetObject.y && rec.bottom < TargetObject.y))
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (MainObject.direction == -1)
	{
		if (TargetObject.x + TargetObject.width > rec.left && TargetObject.x + TargetObject.width < rec.right)
		{
			if ((rec.top < TargetObject.y && rec.top > TargetObject.y - TargetObject.height)
				|| (rec.top > TargetObject.y && rec.bottom < TargetObject.y))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}

void GameObject::UpdateObjectCollider()
{
	int direction = (isLeft == true) ? -1 : 1;
	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.dt = dt;
	collider.direction = direction;
}

void GameObject::UpdateTileCollider()
{
	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.dt = dt;
	collider.height = 8;
}

RECT GameObject::GetRect()
{
	RECT rect;
	rect.top = y;
	rect.left = x;
	rect.right = x + width;
	rect.bottom = y - height;
	return rect;
}