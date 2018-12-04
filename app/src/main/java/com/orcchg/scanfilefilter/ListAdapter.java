package com.orcchg.scanfilefilter;

import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import java.util.ArrayList;
import java.util.List;

public class ListAdapter extends RecyclerView.Adapter<ListViewHolder> {

    ListAdapter() {
        super();
        setHasStableIds(true);
    }

    private List<String> data = new ArrayList<>();

    @NonNull @Override
    public ListViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View v = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.rv_item, viewGroup, false);
        return new ListViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull ListViewHolder listViewHolder, int i) {
        listViewHolder.bind(data.get(i));
    }

    @Override
    public long getItemId(int position) {
        return data.get(position).hashCode();
    }

    @Override
    public int getItemCount() {
        return data.size();
    }

    // --------------------------------------------------------------------------------------------
    public void addItem(String item) {
        data.add(item);
        notifyItemInserted(data.size() - 1);
    }

    public void clear() {
        data.clear();
        notifyDataSetChanged();
    }
}
