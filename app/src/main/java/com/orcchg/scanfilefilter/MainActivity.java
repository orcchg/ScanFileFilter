package com.orcchg.scanfilefilter;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.webkit.URLUtil;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import java.util.regex.Pattern;
import java.util.regex.PatternSyntaxException;

public class MainActivity extends AppCompatActivity {

    private Button buttonStart;
    private Button buttonReset;
    private EditText etUrl;
    private EditText etRegexp;
    private ListView list;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etUrl = findViewById(R.id.et_url);
        etRegexp = findViewById(R.id.et_regexp);
        buttonStart = findViewById(R.id.btn_start);
        buttonReset = findViewById(R.id.btn_reset);
        list = findViewById(R.id.lv_items);

        etUrl.setText("https://");

        buttonStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Check URL for validity.
                String url = etUrl.getText().toString();
                if (url.isEmpty() || !URLUtil.isValidUrl(url)) {
                    etUrl.setError("Invalid URL!");
                    return;
                }

                // Check regexp for validity.
                String regexp = etRegexp.getText().toString();
                if (regexp.isEmpty()) {
                    etRegexp.setError("Wrong regexp!");
                    return;
                } else {
                    try {
                        Pattern.compile(regexp);
                    } catch (PatternSyntaxException e) {
                        etRegexp.setError("Wrong regexp!");
                        return;
                    }

                    if (!LogReader.getInstance().setFilter(regexp)) {
                        etRegexp.setError("Wrong regexp!");
                        return;
                    }
                }

                // Start processing.
                hideViews(true);
                start(url, regexp);
            }
        });

        buttonReset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                stop();
                hideViews(false);
            }
        });
    }

    private void start(String url, String regexp) {
        //
    }

    private void stop() {
        // TODO
    }

    private void hideViews(Boolean isHide) {
        if (isHide) {
            buttonStart.setVisibility(View.GONE);
            buttonReset.setVisibility(View.VISIBLE);
            etUrl.setVisibility(View.GONE);
            etRegexp.setVisibility(View.GONE);
        } else {
            buttonStart.setVisibility(View.VISIBLE);
            buttonReset.setVisibility(View.GONE);
            etUrl.setVisibility(View.VISIBLE);
            etRegexp.setVisibility(View.VISIBLE);
        }
    }
}
