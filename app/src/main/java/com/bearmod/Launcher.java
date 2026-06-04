package com.bearmod;
import android.app.AlertDialog;
import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.os.Process;
import android.provider.Settings;
import android.text.Html;
import android.text.InputType;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.Toast;
import android.graphics.drawable.GradientDrawable;
import android.graphics.Color;
import android.widget.TextView;
import java.security.acl.Group;
import android.view.Gravity;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.graphics.drawable.Drawable;
import android.util.TypedValue;
import android.graphics.Rect;
import android.app.Activity;
import java.lang.ref.WeakReference;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class Launcher {

    public static native String LoginNameNrg();
    public static native String Pleaselog();
    public static native String KeyAdd();
    public static native String Login();
    public static native String Cancel();
    public static native String Error();
    public static native String Pleasecheck();
    public static native String Ok();
    public static native String Loging();
    
    static{
        System.loadLibrary("bear");
    }
    private static SharedPreferences gifs;
    private static final ExecutorService LOGIN_EXECUTOR = Executors.newSingleThreadExecutor();

    
    

void hideesp()
    {
    Floating.hideesp();
    }

    void stopHideesp()
    {
        Floating.stopHideesp();
    }


    public static void Init(Object object) {
        final Context context = (Context) object;
        Activity m_Activity = (Activity) object;

        Init(context);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            if (!Settings.canDrawOverlays(context)) {
                Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, Uri.parse("package:" + context.getPackageName()));
                m_Activity.startActivity(intent);
            }
        }

        gifs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);

        if (!gifs.contains("USER_KEY")) {

            final SharedPreferences sharedPreferences = context.getSharedPreferences("SavePref", 0);
            String string = sharedPreferences.getString("User", null);
            String string2 = sharedPreferences.getString("Pass", null);

            //Create LinearLayout
            LinearLayout linearLayout = new LinearLayout(context);
            linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
            linearLayout.setOrientation(LinearLayout.VERTICAL);
            GradientDrawable gradientdrawable = new GradientDrawable();
            gradientdrawable.setCornerRadius(30); //Set corner
            gradientdrawable.setColor(Color.parseColor("#FFF1F1F1")); //Set background color
            gradientdrawable.setStroke(0, Color.parseColor("#32cb00")); //Set 
            linearLayout.setBackground(gradientdrawable);



            TextView txt = new TextView(context);
            txt.setGravity(Gravity.CENTER);
            txt.setText(LoginNameNrg());
            //txt.setText("Login");
            txt.setTextColor(0xFF181818);
            txt.setBackgroundColor(Color.TRANSPARENT);
            txt.setTextSize(19);
            txt.setPadding(1,1,1,1);




            TextView txt1 = new TextView(context);
            txt1.setGravity(Gravity.CENTER);
            txt1.setText(Pleaselog());
            //txt1.setText("Please log in");
            txt1.setTextColor(0xFF151515);
            txt1.setBackgroundColor(Color.TRANSPARENT);
            txt1.setTextSize(9);


            final EditText editTextUser = new EditText(context);
            editTextUser.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            editTextUser.setTextColor(Color.parseColor("#000000bb"));
            editTextUser.setHint(KeyAdd());
            editTextUser.setGravity(Gravity.CENTER);
            editTextUser.setTextColor(Color.parseColor("#000000")); // Черный текст


            //  editTextUser.setTextSize(TypedValue.COMPLEX_UNIT_SP, 14); // Размер текста в sp

// Установка линии в центре ввода текста
            editTextUser.setBackgroundColor(Color.parseColor("#000000")); // Черный цвет
            editTextUser.setHintTextColor(Color.parseColor("#000000")); // Черный цвет подсказки

// Создание градиента для обводки
            GradientDrawable strokeDrawable = new GradientDrawable();
            strokeDrawable.setShape(GradientDrawable.RECTANGLE);
            strokeDrawable.setColor(Color.parseColor("#fafafa")); // Красный цвет
            strokeDrawable.setCornerRadius(20); //Set corner
            strokeDrawable.setStroke(30, Color.TRANSPARENT); // Толщина обводки 30 и черный цвет

// Установка обводки для EditText
            editTextUser.setBackground(strokeDrawable);

            LinearLayout ln3 = new LinearLayout(context);
            ln3.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, (int)1));
            ln3.setOrientation(LinearLayout.HORIZONTAL);
            ln3.setGravity(Gravity.CENTER);
            ln3.setBackgroundColor(Color.GRAY);


            LinearLayout ln2 = new LinearLayout(context);
            ln2.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, -1));
            ln2.setOrientation(LinearLayout.HORIZONTAL);
            ln2.setGravity(Gravity.CENTER);


            Button button = new Button(context);
            button.setTextColor(Color.BLUE);
            button.setText(Login());
            //button.setText("                Login                ");
            button.setBackgroundColor(Color.TRANSPARENT);



            LinearLayout ln4 = new LinearLayout(context);
            ln4.setLayoutParams(new LinearLayout.LayoutParams((int)1,LinearLayout.LayoutParams.MATCH_PARENT));
            ln4.setOrientation(LinearLayout.HORIZONTAL);
            ln4.setGravity(Gravity.CENTER);
            ln4.setBackgroundColor(Color.GRAY);

            //Create button
            Button button2 = new Button(context);
            button.setTextColor(Color.BLUE);
            button2.setText(Cancel());
            //button2.setText("               Cancel                ");
            button2.setBackgroundColor(Color.TRANSPARENT);

            linearLayout.addView(txt);
            linearLayout.addView(txt1);
            linearLayout.addView(editTextUser);

            linearLayout.addView(ln3);
            ln2.addView(button2);
            ln2.addView(ln4);
            ln2.addView(button);
            linearLayout.addView(ln2);
            //Create alertdialog

            final Dialog builder = new Dialog(context);
            //builder.setTitle("Login");
            builder.setCancelable(false);
            builder.setContentView(linearLayout);
            builder.getWindow().setBackgroundDrawableResource(android.R.color.transparent);

            final EditText editText3 = editTextUser;

            button.setOnClickListener(new View.OnClickListener() {
                    public void onClick(View view) {
                        String userKey = editTextUser.getText().toString();
                        Login(context, userKey);
                        builder.dismiss();
                    }
                });
            button2.setOnClickListener(new View.OnClickListener() {
                    public void onClick(View view) {
                        Process.killProcess(Process.myPid());
                    }
                });
            builder.show();
        } else{
            Login(context, gifs.getString("USER_KEY", null));
        }
    }


    private static boolean isActivityAlive(Activity activity) {
        return activity != null && !activity.isFinishing() && (Build.VERSION.SDK_INT < Build.VERSION_CODES.JELLY_BEAN_MR1 || !activity.isDestroyed());
    }

    private static class LoginHandler extends Handler {
        private final WeakReference<Activity> activityRef;
        private final WeakReference<Dialog> progressDialogRef;
        private final Context appContext;

        LoginHandler(Activity activity, Dialog progressDialog, Context appContext) {
            super(Looper.getMainLooper());
            this.activityRef = new WeakReference<>(activity);
            this.progressDialogRef = new WeakReference<>(progressDialog);
            this.appContext = appContext;
        }

        @Override
        public void handleMessage(Message ems) {
            Activity activity = activityRef.get();
            Dialog progressDialog = progressDialogRef.get();
            if (progressDialog != null && progressDialog.isShowing()) {
                progressDialog.dismiss();
            }
            if (!isActivityAlive(activity)) {
                return;
            }

            if (ems.what == 0) {
                Intent i = new Intent(appContext, Floating.class);
                appContext.startService(i);
            } else if (ems.what == 1) {
                LinearLayout linearLayout = new LinearLayout(activity);
                linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
                linearLayout.setOrientation(LinearLayout.VERTICAL);

                GradientDrawable gradientdrawable = new GradientDrawable();
                gradientdrawable.setCornerRadius(30);
                gradientdrawable.setColor(Color.parseColor("#FFF1F1F1"));
                gradientdrawable.setStroke(0, Color.parseColor("#32cb00"));
                linearLayout.setBackground(gradientdrawable);

                TextView txt = new TextView(activity);
                txt.setGravity(Gravity.CENTER);
                txt.setText(Error());
                txt.setTextColor(0xFF181818);
                txt.setBackgroundColor(Color.TRANSPARENT);
                txt.setTextSize(20);

                TextView txt1 = new TextView(activity);
                txt1.setGravity(Gravity.CENTER);
                txt1.setText(Pleasecheck());
                txt1.setTextColor(0xFF595959);
                txt1.setBackgroundColor(Color.TRANSPARENT);
                txt1.setTextSize(13);

                final TextView infoText = new TextView(activity);
                infoText.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
                infoText.setGravity(Gravity.CENTER);
                infoText.setBackgroundColor(Color.TRANSPARENT);
                infoText.setText(ems.obj != null ? ems.obj.toString() : "");

                LinearLayout ln3 = new LinearLayout(activity);
                ln3.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, (int)1));
                ln3.setOrientation(LinearLayout.HORIZONTAL);
                ln3.setGravity(Gravity.CENTER);
                ln3.setBackgroundColor(Color.GRAY);

                LinearLayout ln2 = new LinearLayout(activity);
                ln2.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, -1));
                ln2.setOrientation(LinearLayout.HORIZONTAL);
                ln2.setGravity(Gravity.CENTER);

                Button button = new Button(activity);
                button.setTextColor(Color.BLUE);
                button.setText(Ok());
                button.setBackgroundColor(Color.TRANSPARENT);

                linearLayout.addView(txt);
                linearLayout.addView(txt1);
                linearLayout.addView(infoText);
                linearLayout.addView(ln3);
                ln2.addView(button);
                linearLayout.addView(ln2);

                final Dialog errorDialog = new Dialog(activity);
                errorDialog.setCancelable(false);
                errorDialog.setContentView(linearLayout);
                errorDialog.getWindow().setBackgroundDrawableResource(android.R.color.transparent);

                button.setOnClickListener(new View.OnClickListener() {
                        public void onClick(View view) {
                            System.exit(0);
                        }
                    });

                errorDialog.show();
            }
        }
    }

    private static void Login(final Context kontes, final String userKey) {
        final Activity activity = kontes instanceof Activity ? (Activity) kontes : null;
        final Context appContext = kontes.getApplicationContext();
        if (!isActivityAlive(activity)) {
            return;
        }

        LinearLayout linearLayout = new LinearLayout(kontes);
        linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        linearLayout.setOrientation(LinearLayout.VERTICAL);

        GradientDrawable gradientdrawable = new GradientDrawable();
        gradientdrawable.setCornerRadius(20); //Set corner
        gradientdrawable.setColor(Color.parseColor("#FFF1F1F1")); //Set background color
        gradientdrawable.setStroke(0, Color.parseColor("#32cb00")); //Set 
        linearLayout.setBackground(gradientdrawable);

        TextView txt = new TextView(kontes);

        txt.setGravity(Gravity.CENTER);
        txt.setText(Loging());
        //txt.setText("  Loging in...  ");
        txt.setTextColor(0xFF181818);
        txt.setBackgroundColor(Color.TRANSPARENT);
        txt.setTextSize(20);

        linearLayout.addView(txt);

        final Dialog builder = new Dialog(kontes);
        //builder.setTitle("Login");
        builder.setCancelable(false);
        builder.setContentView(linearLayout);
        builder.getWindow().setBackgroundDrawableResource(android.R.color.transparent);
        builder.show();

        final Handler sagen = new LoginHandler(activity, builder, appContext);

        LOGIN_EXECUTOR.execute(new Runnable() {
                @Override
                public void run() {
                    String result = Check(appContext, userKey);
                    if ("OK".equals(result)) {
                        gifs.edit().putString("USER_KEY", userKey).apply();

                        sagen.sendEmptyMessage(0);
                    } else {
                        gifs.edit().clear().apply();

                        Message ems = new Message();
                        ems.what = 1;
                        ems.obj = result;
                        sagen.sendMessage(ems);
                    }
                }
            });


    } 
    private static native void Init(Context mContext);
    private static native String Check(Context mContext, String userKey);

    }

