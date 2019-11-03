#include "Animation.h"

void Animation::AddFrame(Sprite *sprite, DWORD time)
{
	DWORD t = time;

	if (time == 0) 
		t = this->defaultDelayTime;

	pair <Sprite *, DWORD> frame(sprite, t);

	frames.push_back(frame);
	curFrame = -1;
	done = false;
}
void Animation::Render(SpriteData spriteData)
{
	DWORD now = GetTickCount();

	if (this->curFrame == -1)
	{
		curFrame = 0;
		lastFrameTime = now;
		done = false;
	}

	frames[curFrame].first->SetData(spriteData);

	Graphics::GetInstance()->Draw(frames[curFrame].first);

	DWORD t = frames[curFrame].second;

	if (now - lastFrameTime > t)
	{
		curFrame++;
		lastFrameTime = now;
		if (curFrame == frames.size())
		{
			curFrame = -1;
			done = true;
		}
		else
			done = false;
	}
}