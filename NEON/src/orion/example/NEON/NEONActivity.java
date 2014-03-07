package orion.example.NEON;

import android.app.Activity;
import android.os.Bundle;

import android.widget.TextView;

public class NEONActivity extends Activity
{

    static {
	System.loadLibrary("NEON");
    }

    private native float[] vecAdd(float[] v1, float[] v2);
    private native float[] alignedMalloc(int size, int align);


    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
	TextView tv = new TextView(this);

	float[] a1 = alignedMalloc(4, 16);
	float[] a2 = alignedMalloc(4, 16);

	a1[0] = 5.5f;
	a1[1] = 5.0f;
	a1[2] = 3.0f;
	a1[3] = 1.5f;

	a2[0] = 3.2f;
	a2[1] = 3.2f;
	a2[2] = 1.2f;
	a2[3] = 6.0f;

	float[] a0 = vecAdd(a1, a2);

	tv.setText("val = " + a0[0] + " " + a0[1] + " " + a0[2] + " " + a0[3]);
        setContentView(tv);
    }
}
