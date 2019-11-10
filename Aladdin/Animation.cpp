#include "Animation.h"

void Animation::AddFrame(Sprite *sprite, DWORD time)
{
	DWORD t = time;

	if (time == 0) 
		t = this->defaultDelayTime;

	pair <Sprite *, DWORD> frame(sprite, t);

	frames.push_back(frame);
	this->curFrame = -1;
	this->done = false;
}
void Animation::Render(SpriteData spriteData)
{
	DWORD now = GetTickCount();

	if (this->curFrame == -1)
	{
		this->curFrame = 0;
		this->lastFrameTime = now;
		this->done = false;
	}

	if (this->isDoubleHit)
	{
		frames[curFrame].first->SetData(spriteData);

		Graphics::GetInstance()->Draw(frames[curFrame].first);

		DWORD t = frames[curFrame].second;

		if (now - lastFrameTime > t)
		{
			this->curFrame++;
			lastFrameTime = now;

			if (curFrame == frames.size())
			{
				this->curFrame = 1;
				this->done = true;
			}
			else
				this->done = false;
		}
	}

	if (!this->isSetCurentFrame)
	{
		if (this->isAniRunning)
		{
			frames[curFrame].first->SetData(spriteData);

			Graphics::GetInstance()->Draw(frames[curFrame].first);

			DWORD t = frames[curFrame].second;

			if (now - lastFrameTime > t)
			{
				this->curFrame++;
				lastFrameTime = now;
				if (curFrame == frames.size())
				{
					this->curFrame = 2;
					this->done = true;
				}
				else
					this->done = false;
			}
		}
		else
		{
			frames[curFrame].first->SetData(spriteData);

			Graphics::GetInstance()->Draw(frames[curFrame].first);

			DWORD t = frames[curFrame].second;

			if (now - lastFrameTime > t)
			{
				this->curFrame++;
				lastFrameTime = now;
				if (curFrame == frames.size())
				{
					this->curFrame = -1;
					this->done = true;
				}
				else
					this->done = false;
			}
		}
	}
	else {
		Graphics::GetInstance()->Draw(frames[curFrame].first);
	}
}