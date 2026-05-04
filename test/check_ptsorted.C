void check_ptsorted() {
    TFile *file = TFile::Open("Run3_2023_PAT_EXONANO_template_woPFCand.root");  // Replace with actual filename
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    TTree *tree = (TTree*) file->Get("Events");
    if (!tree) {
        std::cerr << "Error: TTree 'Events' not found!" << std::endl;
        return;
    }

    // Use TTreeReader for automatic type detection
    TTreeReader reader(tree);
    TTreeReaderArray<Float_t> pfcands_pt(reader, "Jet_pt");

    int unsorted_count = 0;


    std::cout << "Total events: " << tree->GetEntries() << std::endl;
    Long64_t total_events = tree->GetEntries();
    for (Long64_t i = 0; reader.Next(); i++) {
        std::vector<float> pt_values(pfcands_pt.begin(), pfcands_pt.end()); // Convert to vector

        if (!std::is_sorted(pt_values.rbegin(), pt_values.rend())) {
            std::cout << "Event " << i << ": PFCands_pt is NOT sorted!" << std::endl;
            unsorted_count++;
        }
    }

    std::cout << "Checked " << total_events << " events, " << unsorted_count << " were not sorted." << std::endl;
    file->Close();
}
